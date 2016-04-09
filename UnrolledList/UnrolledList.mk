##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## debug
ProjectName            :=UnrolledList
ConfigurationName      :=debug
WorkspacePath          :=/home/christian/experimental
ProjectPath            :=/home/christian/experimental/UnrolledList
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Christian
Date                   :=09/04/16
CodeLitePath           :=/home/christian/.codelite
LinkerName             :=/usr/bin/g++-5
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UnrolledList.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-5
CC       := /usr/bin/gcc-5
CXXFLAGS :=  -g -O0 -pedantic -W -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/helpers_bits.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_helpers_helpers.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/helpers_bits.cpp$(ObjectSuffix): helpers/bits.cpp $(IntermediateDirectory)/helpers_bits.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/helpers/bits.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/helpers_bits.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/helpers_bits.cpp$(DependSuffix): helpers/bits.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/helpers_bits.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/helpers_bits.cpp$(DependSuffix) -MM "helpers/bits.cpp"

$(IntermediateDirectory)/helpers_bits.cpp$(PreprocessSuffix): helpers/bits.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/helpers_bits.cpp$(PreprocessSuffix) "helpers/bits.cpp"

$(IntermediateDirectory)/test_helpers_helpers.cpp$(ObjectSuffix): test/helpers/helpers.cpp $(IntermediateDirectory)/test_helpers_helpers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/helpers/helpers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_helpers_helpers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_helpers_helpers.cpp$(DependSuffix): test/helpers/helpers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_helpers_helpers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_helpers_helpers.cpp$(DependSuffix) -MM "test/helpers/helpers.cpp"

$(IntermediateDirectory)/test_helpers_helpers.cpp$(PreprocessSuffix): test/helpers/helpers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_helpers_helpers.cpp$(PreprocessSuffix) "test/helpers/helpers.cpp"

$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(ObjectSuffix): test/debug-tests/debug-tests.cpp $(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/debug-tests/debug-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(DependSuffix): test/debug-tests/debug-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(DependSuffix) -MM "test/debug-tests/debug-tests.cpp"

$(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(PreprocessSuffix): test/debug-tests/debug-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_debug-tests_debug-tests.cpp$(PreprocessSuffix) "test/debug-tests/debug-tests.cpp"

$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(ObjectSuffix): test/debug-tests/node-tests.cpp $(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/debug-tests/node-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(DependSuffix): test/debug-tests/node-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(DependSuffix) -MM "test/debug-tests/node-tests.cpp"

$(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(PreprocessSuffix): test/debug-tests/node-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_debug-tests_node-tests.cpp$(PreprocessSuffix) "test/debug-tests/node-tests.cpp"

$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(ObjectSuffix): test/debug-tests/utils-bit-tests.cpp $(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/debug-tests/utils-bit-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(DependSuffix): test/debug-tests/utils-bit-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(DependSuffix) -MM "test/debug-tests/utils-bit-tests.cpp"

$(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(PreprocessSuffix): test/debug-tests/utils-bit-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_debug-tests_utils-bit-tests.cpp$(PreprocessSuffix) "test/debug-tests/utils-bit-tests.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


