AUTOMAKE_OPTIONS = foreign

SUBDIRS = . test

ACLOCAL_AMFLAGS = -I m4
AM_CXXFLAGS = --std=gnu++14 -O3 -Wall -g

include $(top_srcdir)/Makefile.inc

#
# Include paths
#
AM_CPPFLAGS = $(COMMON_INCLUDES)

noinst_LTLIBRARIES = libredex.la libopt.la

#
# libredex: the optimizer's guts
#

libredex_la_SOURCES = \
	liblocator/locator.cpp \
	libredex/ABExperimentContext.cpp \
	libredex/ABExperimentContextImpl.cpp \
	libredex/AnalysisUsage.cpp \
	libredex/AnnoUtils.cpp \
	libredex/ApiLevelChecker.cpp \
	libredex/ApkManager.cpp \
	libredex/BigBlocks.cpp \
	libredex/CFGMutation.cpp \
	libredex/CallGraph.cpp \
	libredex/ClassHierarchy.cpp \
	libredex/ClassUtil.cpp \
	libredex/ConfigFiles.cpp \
	libredex/Configurable.cpp \
	libredex/ControlFlow.cpp \
	libredex/Creators.cpp \
	libredex/Debug.cpp \
	libredex/DexAccess.cpp \
	libredex/DexAnnotation.cpp \
	libredex/DexAsm.cpp \
	libredex/DexCallSite.cpp \
	libredex/DexClass.cpp \
	libredex/DexDebugInstruction.cpp \
	libredex/DexHasher.cpp \
	libredex/DexIdx.cpp \
	libredex/DexInstruction.cpp \
	libredex/DexLoader.cpp \
	libredex/DexMemberRefs.cpp \
	libredex/DexMethodHandle.cpp \
	libredex/DexOpcode.cpp \
	libredex/DexOutput.cpp \
	libredex/DexPosition.cpp \
	libredex/DexStats.cpp \
	libredex/DexStore.cpp \
	libredex/DexStoreUtil.cpp \
	libredex/DexTypeEnvironment.cpp \
	libredex/DexUtil.cpp \
	libredex/DexStoreUtil.cpp \
	libredex/DuplicateClasses.cpp \
	libredex/EditableCfgAdapter.cpp \
	libredex/FbjniMarker.cpp \
	libredex/FrameworkApi.cpp \
	libredex/FrequentlyUsedPointersCache.cpp \
	libredex/GlobalConfig.cpp \
	libredex/GraphVisualizer.cpp \
	libredex/HierarchyUtil.cpp \
	libredex/InitCollisionFinder.cpp \
	libredex/InlineForSpeed.cpp \
	libredex/InlinerConfig.cpp \
	libredex/InstructionLowering.cpp \
	libredex/IODIMetadata.cpp \
	libredex/IRAssembler.cpp \
	libredex/IRCode.cpp \
	libredex/IRInstruction.cpp \
	libredex/IRList.cpp \
	libredex/IRMetaIO.cpp \
	libredex/IROpcode.cpp \
	libredex/IRTypeChecker.cpp \
	libredex/IRTypeChecker.cpp \
	libredex/JarLoader.cpp \
	libredex/JavaParserUtil.cpp \
	libredex/JsonWrapper.cpp \
	libredex/KeepReason.cpp \
	libredex/Match.cpp \
	libredex/MethodDevirtualizer.cpp \
	libredex/MethodOverrideGraph.cpp \
	libredex/MethodProfiles.cpp \
	libredex/MethodUtil.cpp \
	libredex/MonitorCount.cpp \
	libredex/Mutators.cpp \
	libredex/NoOptimizationsMatcher.cpp \
	libredex/NullnessDomain.cpp \
	libredex/OptData.cpp \
	libredex/Pass.cpp \
	libredex/PassManager.cpp \
	libredex/PassRegistry.cpp \
	libredex/PluginRegistry.cpp \
	libredex/PointsToSemantics.cpp \
	libredex/PointsToSemanticsUtils.cpp \
	libredex/PostLowering.cpp \
	libredex/PrintSeeds.cpp \
	libredex/ProguardConfiguration.cpp \
	libredex/ProguardLexer.cpp \
	libredex/ProguardLineRange.cpp \
	libredex/ProguardMap.cpp \
	libredex/ProguardMatcher.cpp \
	libredex/ProguardParser.cpp \
	libredex/ProguardPrintConfiguration.cpp \
	libredex/ProguardRegex.cpp \
	libredex/ProguardReporting.cpp \
	libredex/Purity.cpp \
	libredex/Reachability.cpp \
	libredex/ReachableClasses.cpp \
	libredex/ReadMaybeMapped.cpp \
	libredex/RedexContext.cpp \
	libredex/RedexException.cpp \
	libredex/RedexOptions.cpp \
	libredex/RedexResources.cpp \
	libredex/ReflectionAnalysis.cpp \
	libredex/RefChecker.cpp \
	libredex/Resolver.cpp \
	libredex/Show.cpp \
	libredex/Timer.cpp \
	libredex/Trace.cpp \
	libredex/Transform.cpp \
	libredex/TypeInference.cpp \
	libredex/TypeSystem.cpp \
	libredex/TypeUtil.cpp \
	libredex/UnknownVirtuals.cpp \
	libredex/Vinfo.cpp \
	libredex/VirtualScope.cpp \
	libredex/Warning.cpp \
	libredex/WorkQueue.cpp \
	libresource/FileMap.cpp \
	libresource/ResourceTypes.cpp \
	libresource/Serialize.cpp \
	libresource/SharedBuffer.cpp \
	libresource/Static.cpp \
	libresource/String16.cpp \
	libresource/String8.cpp \
	libresource/TypeWrappers.cpp \
	libresource/Unicode.cpp \
	libresource/VectorImpl.cpp \
	service/api-levels/ApiLevelsUtils.cpp \
	service/class-init/ClassInitCounter.cpp \
	service/class-merging/ApproximateShapeMerging.cpp \
	service/class-merging/ClassAssemblingUtils.cpp \
	service/class-merging/ClassMerging.cpp \
	service/class-merging/MergerType.cpp \
	service/class-merging/ModelMerger.cpp \
	service/class-merging/ModelMethodMerger.cpp \
	service/class-merging/Model.cpp \
	service/class-merging/TypeTagUtils.cpp \
	service/constant-propagation/ConstantEnvironment.cpp \
	service/constant-propagation/ConstantPropagationAnalysis.cpp \
	service/constant-propagation/ConstantPropagation.cpp \
	service/constant-propagation/ConstantPropagationTransform.cpp \
	service/constant-propagation/ConstantPropagationWholeProgramState.cpp \
	service/constant-propagation/ConstructorParams.cpp \
	service/constant-propagation/IPConstantPropagationAnalysis.cpp \
	service/constant-propagation/ObjectDomain.cpp \
	service/constant-propagation/SignDomain.cpp \
	service/copy-propagation/AliasedRegisters.cpp \
	service/copy-propagation/CanonicalizeLocks.cpp \
	service/copy-propagation/CopyPropagation.cpp \
	service/cse/CommonSubexpressionElimination.cpp \
	service/dataflow/LiveRange.cpp \
	service/dataflow/ConstantUses.cpp \
	service/dedup-blocks/DedupBlocks.cpp \
	service/dedup-blocks/DedupBlockValueNumbering.cpp \
	service/escape-analysis/BlamingAnalysis.cpp \
	service/escape-analysis/LocalPointersAnalysis.cpp \
	service/field-ops/FieldOpTracker.cpp \
	service/local-dce/LocalDce.cpp \
	service/loop-info/LoopInfo.cpp \
	service/method-dedup/ConstantLifting.cpp \
	service/method-dedup/ConstantValue.cpp \
	service/method-dedup/MethodDedup.cpp \
	service/method-dedup/NormalizeConstructor.cpp \
	service/method-dedup/TypeTags.cpp \
	service/method-inliner/CFGInliner.cpp \
	service/method-inliner/ConstructorAnalysis.cpp \
	service/method-inliner/Deleter.cpp \
	service/method-inliner/Inliner.cpp \
	service/method-inliner/MethodInliner.cpp \
	service/method-inliner/ObjectInlinePlugin.cpp \
	service/method-merger/MethodMerger.cpp \
	service/reference-update/MethodReference.cpp \
	service/reference-update/TypeReference.cpp \
	service/switch-dispatch/SwitchDispatch.cpp \
	service/switch-partitioning/SwitchEquivFinder.cpp \
	service/switch-partitioning/SwitchMethodPartitioning.cpp \
	service/type-analysis/GlobalTypeAnalyzer.cpp \
	service/type-analysis/LocalTypeAnalyzer.cpp \
	service/type-analysis/WholeProgramState.cpp \
	service/type-analysis/TypeAnalysisTransform.cpp \
	service/type-analysis/TypeAnalysisRuntimeAssert.cpp \
	service/type-string-rewriter/TypeStringRewriter.cpp \
	shared/DexDefs.cpp \
	shared/DexEncoding.cpp \
	shared/file-utils.cpp \
	util/CommandProfiling.cpp \
	util/JemallocUtil.cpp \
	util/Sha1.cpp

libredex_la_LIBADD = \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_REGEX_LIB) \
	$(BOOST_IOSTREAMS_LIB) \
	$(BOOST_THREAD_LIB) \
	-lpthread

#
# libopt: the optimization passes
#

# Autoconf + libtool does not handle whole-archive well, and it is not
# supported on MacOS ("-all_load"). But we would need this for pass
# registration. Instead, share sources and create libopt for the tests.

libopt_la_SOURCES = \
	analysis/max-depth/MaxDepthAnalysis.cpp \
	analysis/ip-reflection-analysis/IPReflectionAnalysis.cpp \
	opt/access-marking/AccessMarking.cpp \
	opt/annokill/AnnoKill.cpp \
	opt/analyze-pure-method/PureMethods.cpp \
	opt/basic-block/BasicBlockProfile.cpp \
	opt/builder_pattern/BuilderAnalysis.cpp \
	opt/builder_pattern/BuilderTransform.cpp \
	opt/builder_pattern/RemoveBuilderPattern.cpp \
	opt/branch-prefix-hoisting/BranchPrefixHoisting.cpp \
	opt/bridge/Bridge.cpp \
	opt/check_breadcrumbs/CheckBreadcrumbs.cpp \
	opt/check-recursion/CheckRecursion.cpp \
	opt/class-merging/ClassMergingPass.cpp \
	opt/class-splitting/ClassSplitting.cpp \
	opt/constant-propagation/ConstantPropagationPass.cpp \
	opt/constant-propagation/ConstantPropagationRuntimeAssert.cpp \
	opt/constant-propagation/IPConstantPropagation.cpp \
	opt/copy-propagation/CopyPropagationPass.cpp \
	opt/cse/CommonSubexpressionEliminationPass.cpp \
	opt/dedup_blocks/DedupBlocksPass.cpp \
	opt/dedup-strings/DedupStrings.cpp \
	opt/delinit/DelInit.cpp \
	opt/delsuper/DelSuper.cpp \
	opt/evaluate_type_checks/EvaluateTypeChecks.cpp \
	opt/final_inline/FinalInline.cpp \
	opt/final_inline/FinalInlineV2.cpp \
	opt/instrument/Instrument.cpp \
	opt/interdex/CrossDexRefMinimizer.cpp \
	opt/interdex/CrossDexRelocator.cpp \
	opt/interdex/DexStructure.cpp \
	opt/interdex/InterDex.cpp \
	opt/interdex/InterDexPass.cpp \
	opt/layout-reachability/LayoutReachabilityPass.cpp \
	opt/local-dce/LocalDcePass.cpp \
	opt/merge_interface/MergeInterface.cpp \
	opt/obfuscate/Obfuscate.cpp \
	opt/obfuscate/ObfuscateUtils.cpp \
	opt/obfuscate/VirtualRenamer.cpp \
	opt/object-sensitive-dce/ObjectSensitiveDcePass.cpp \
	opt/object-sensitive-dce/SideEffectSummary.cpp \
	opt/object-sensitive-dce/UsedVarsAnalysis.cpp \
	opt/optimize_enums/EnumClinitAnalysis.cpp \
	opt/optimize_enums/EnumConfig.cpp \
	opt/optimize_enums/EnumInSwitch.cpp \
	opt/optimize_enums/EnumAnalyzeGeneratedMethods.cpp \
	opt/optimize_enums/EnumTransformer.cpp \
	opt/optimize_enums/EnumUpcastAnalysis.cpp \
	opt/optimize_enums/OptimizeEnumsAnalysis.cpp \
	opt/optimize_enums/OptimizeEnums.cpp \
	opt/optimize_enums/OptimizeEnumsGeneratedAnalysis.cpp \
	opt/original_name/OriginalNamePass.cpp \
	opt/peephole/Peephole.cpp \
	opt/peephole/RedundantCheckCastRemover.cpp \
	opt/print-members/PrintMembers.cpp \
	opt/rebindrefs/ReBindRefs.cpp \
	opt/regalloc/GraphColoring.cpp \
	opt/regalloc/Interference.cpp \
	opt/regalloc/RegAlloc.cpp \
	opt/regalloc/RegisterType.cpp \
	opt/regalloc/Split.cpp \
	opt/regalloc/VirtualRegistersFile.cpp \
	opt/remove-apilevel-checks/RemoveApiLevelChecks.cpp \
	opt/remove-builders/RemoveBuilders.cpp \
	opt/remove-builders/RemoveBuildersHelper.cpp \
	opt/remove-interfaces/RemoveInterfacePass.cpp \
	opt/remove-recursive-locks/RemoveRecursiveLocks.cpp \
	opt/remove_redundant_check_casts/CheckCastAnalysis.cpp \
	opt/remove_redundant_check_casts/CheckCastTransform.cpp \
	opt/remove_redundant_check_casts/RemoveRedundantCheckCasts.cpp \
	opt/remove-uninstantiables/RemoveUninstantiablesPass.cpp \
	opt/remove-unreachable/RemoveUnreachable.cpp \
	opt/remove-nullcheck-string-arg/RemoveNullcheckStringArg.cpp \
	opt/remove-unused-fields/RemoveUnusedFields.cpp \
	opt/remove_empty_classes/RemoveEmptyClasses.cpp \
	opt/remove_gotos/RemoveGotos.cpp \
	opt/remove-unused-args/RemoveUnusedArgs.cpp \
	opt/renameclasses/RenameClassesV2.cpp \
	opt/reorder-interfaces-decl/ReorderInterfacesDecl.cpp \
	opt/reduce-array-literals/ReduceArrayLiterals.cpp \
	opt/reduce-gotos/ReduceGotos.cpp \
	opt/resolve-refs/ResolveRefsPass.cpp \
	opt/resolve-refs/ExternalRefsManglingPass.cpp \
	opt/result-propagation/ResultPropagation.cpp \
	opt/shorten-srcstrings/Shorten.cpp \
	opt/make-public/MakePublicPass.cpp \
	opt/methodinline/IntraDexInlinePass.cpp \
	opt/methodinline/MethodInlinePass.cpp \
	opt/methodinline/PerfMethodInlinePass.cpp \
	opt/outliner/OutlinerTypeAnalysis.cpp \
	opt/outliner/InstructionSequenceOutliner.cpp \
	opt/singleimpl/SingleImpl.cpp \
	opt/singleimpl/SingleImplAnalyze.cpp \
	opt/singleimpl/SingleImplOptimize.cpp \
	opt/singleimpl/SingleImplStats.cpp \
	opt/simplify_cfg/SimplifyCFG.cpp \
	opt/split_huge_switches/SplitHugeSwitchPass.cpp \
	opt/staticrelo/StaticReloV2.cpp \
	opt/string_concatenator/StringConcatenator.cpp \
	opt/stringbuilder-outliner/StringBuilderOutliner.cpp \
	opt/strip-debug-info/StripDebugInfo.cpp \
	opt/synth/Synth.cpp \
	opt/test_cfg/TestCFG.cpp \
	opt/track_resources/TrackResources.cpp \
	opt/throw-propagation/ThrowPropagationPass.cpp \
	opt/type-analysis/GlobalTypeAnalysisPass.cpp \
	opt/type-analysis/TypeAnalysisCallGraphGenerationPass.cpp \
	opt/unreferenced_interfaces/UnreferencedInterfaces.cpp \
	opt/unmark_proguard_keep/UnmarkProguardKeep.cpp \
	opt/up-code-motion/UpCodeMotion.cpp \
	opt/uses-names/UsesNames.cpp \
	opt/verifier/Verifier.cpp \
	opt/vertical_merging/VerticalMerging.cpp \
	opt/virtual_merging/DedupVirtualMethods.cpp \
	opt/virtual_merging/VirtualMerging.cpp \
	opt/virtual_scope/MethodDevirtualizationPass.cpp

libopt_la_LIBADD = \
    libredex.la \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_REGEX_LIB) \
	$(BOOST_IOSTREAMS_LIB) \
	$(BOOST_THREAD_LIB) \
	-lpthread

#
# redex-all: the main executable
#
bin_PROGRAMS = redexdump
noinst_PROGRAMS = redex-all

redex_all_SOURCES = \
    $(libopt_la_SOURCES) \
	tools/common/ToolsCommon.cpp \
	tools/redex-all/main.cpp

# Workaround for not using libopt.
redex_all_CPPFLAGS = $(AM_CPPFLAGS)

redex_all_LDADD = \
	libredex.la \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_REGEX_LIB) \
	$(BOOST_PROGRAM_OPTIONS_LIB) \
	$(BOOST_THREAD_LIB) \
	-lpthread \
	-ldl

redex_all_LDFLAGS = \
	-rdynamic # function names in stack traces

redexdump_SOURCES = \
	tools/redexdump/DumpTables.cpp \
	tools/redexdump/PrintUtil.cpp \
	tools/redexdump/RedexDump.cpp \
	tools/common/DexCommon.cpp \
	tools/common/Formatters.cpp

redexdump_LDADD = \
	libredex.la \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_REGEX_LIB) \
	$(BOOST_THREAD_LIB) \
	-lpthread \
	-ldl

#
# redex: Python driver script
#
bin_SCRIPTS = redex apkutil
CLEANFILES = redex

PYTHON_SRCS := redex.py \
	pyredex/__init__.py \
	pyredex/logger.py \
	pyredex/unpacker.py \
	pyredex/utils.py

redex: redex-all $(PYTHON_SRCS)
	$(srcdir)/bundle-redex.sh
