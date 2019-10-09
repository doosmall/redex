/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "DexClass.h"
#include "MethodOverrideGraph.h"

enum class CseSpecialLocations : uintptr_t {
  GENERAL_MEMORY_BARRIER,
  ARRAY_COMPONENT_TYPE_INT,
  ARRAY_COMPONENT_TYPE_BYTE,
  ARRAY_COMPONENT_TYPE_CHAR,
  ARRAY_COMPONENT_TYPE_WIDE,
  ARRAY_COMPONENT_TYPE_SHORT,
  ARRAY_COMPONENT_TYPE_OBJECT,
  ARRAY_COMPONENT_TYPE_BOOLEAN,
  END
};

// A (tracked) location is either a special location, or a field.
// Stored in a union, special locations are effectively represented as illegal
// pointer values.
// The nullptr field and CseSpecialLocations::GENERAL_MEMORY_BARRIER are in
// effect aliases.
union CseLocation {
  explicit CseLocation(const DexField* f) : field(f) {}
  explicit CseLocation(CseSpecialLocations sl) : special_location(sl) {}
  const DexField* field;
  CseSpecialLocations special_location;
};

inline bool operator==(const CseLocation& a, const CseLocation& b) {
  return a.field == b.field;
}

inline bool operator!=(const CseLocation& a, const CseLocation& b) {
  return !(a == b);
}

inline bool operator<(const CseLocation& a, const CseLocation& b) {
  if (a.special_location < CseSpecialLocations::END) {
    if (b.special_location < CseSpecialLocations::END) {
      return a.special_location < b.special_location;
    } else {
      return true;
    }
  }
  if (b.special_location < CseSpecialLocations::END) {
    return false;
  }
  return dexfields_comparator()(a.field, b.field);
}

struct CseLocationHasher {
  size_t operator()(const CseLocation& l) const { return (size_t)l.field; }
};

using CseUnorderedLocationSet =
    std::unordered_set<CseLocation, CseLocationHasher>;

std::ostream& operator<<(std::ostream&, const CseLocation&);
std::ostream& operator<<(std::ostream&, const CseUnorderedLocationSet&);

CseLocation get_field_location(IROpcode opcode, const DexField* field);
CseLocation get_field_location(IROpcode opcode, const DexFieldRef* field_ref);
CseLocation get_read_array_location(IROpcode opcode);
CseLocation get_read_location(const IRInstruction* insn);

/*
 * Pure methods...
 * - do not read or write mutable state...
 * - ... in a way that could be observed (by reading state or calling other
 *   methods); so we are actually talking about a notion of "observational
 *   purity" here
 * - are deterministic (and do not return newly allocated objects, unless object
 *                      identity should be truly irrelevant, such as in the case
 *                      of boxing certain values)
 * - may throw trivial exceptions such as null-pointer exception that
 *   generally shouldn't be caught, or return normally
 *
 * If their outputs are not used, pure method invocations can be removed by DCE.
 * Redundant invocations with same incoming arguments can be eliminated by CSE.
 *
 * Note that this notion of pure methods is different from ProGuard's
 * notion of assumenosideeffects. The latter includes methods that may read
 * mutable state, as well as non-deterministic methods.
 *
 * TODO: Derive this list with static analysis rather than hard-coding
 * it.
 */
std::unordered_set<DexMethodRef*> get_pure_methods();

struct LocationsAndDependencies {
  CseUnorderedLocationSet locations;
  std::unordered_set<const DexMethod*> dependencies;
};

// Values indicating what action should be taken for a method
enum class MethodOverrideAction {
  // Ignore this method definition, as it doesn't provide an implementation
  EXCLUDE,
  // The implementation of this method definition is unknown
  UNKNOWN,
  // Consider this method definition and its implementation
  INCLUDE,
};

// Determine what action to take for a method while traversing a base method
// and its overriding methods.
MethodOverrideAction get_base_or_overriding_method_action(
    const DexMethod* method, bool ignore_methods_with_assumenosideeffects);

// Given a (base) method, iterate over all relevant (base + overriding)
// methods, and run a handler method for each method that should be included
// in the analysis.
// Returns true if all invoked handlers returned true, and no method with an
// unknown implementation was encountered.
bool process_base_and_overriding_methods(
    const method_override_graph::Graph* method_override_graph,
    const DexMethod* method,
    bool ignore_methods_with_assumenosideeffects,
    std::function<bool(DexMethod*)> handler_func);

// Given initial locations and dependencies for each method, compute the closure
// (union) of all such locations over all the stated dependencies, taking into
// account all overriding methods.
// When encountering unknown method implementations, the resulting map will have
// no entry for the relevant (base) methods.
// The return value indicates how many iterations the fixed-point computation
// required.
size_t compute_locations_closure(
    const Scope& scope,
    const method_override_graph::Graph* method_override_graph,
    std::function<boost::optional<LocationsAndDependencies>(DexMethod*)>
        init_func,
    std::unordered_map<const DexMethod*, CseUnorderedLocationSet>* result);

// Compute all "conditionally pure" methods, i.e. methods which are pure except
// that they may read from a set of well-known locations (not including
// GENERAL_MEMORY_BARRIER). For each conditionally pure method, the returned
// map indicates the set of read locations.
// The return value indicates how many iterations the fixed-point computation
// required.
size_t compute_conditionally_pure_methods(
    const Scope& scope,
    const method_override_graph::Graph* method_override_graph,
    const std::unordered_set<DexMethodRef*>& pure_methods,
    std::unordered_map<const DexMethod*, CseUnorderedLocationSet>* result);

// Compute all methods with no side effects, i.e. methods which do not mutate
// state and only call other methods which do not have side effects.
// The return value indicates how many iterations the fixed-point computation
// required.
// The return value indicates how many iterations the fixed-point computation
// required.
size_t compute_no_side_effects_methods(
    const Scope& scope,
    const method_override_graph::Graph* method_override_graph,
    const std::unordered_set<DexMethodRef*>& pure_methods,
    std::unordered_set<const DexMethod*>* result);
