##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UnrolledList
ConfigurationName      :=Debug
WorkspacePath          :=/home/christian/experimental
ProjectPath            :=/home/christian/experimental/UnrolledList
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Christian
Date                   :=24/04/16
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
CXXFLAGS :=  -g -O0 -pedantic -std=c++14 -Wall -Wextra $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_unrolled-list-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) 



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

$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix): test/test.cpp $(IntermediateDirectory)/test_test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_test.cpp$(DependSuffix): test/test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_test.cpp$(DependSuffix) -MM "test/test.cpp"

$(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix): test/test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix) "test/test.cpp"

$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(ObjectSuffix): test/unrolled-list-tests.cpp $(IntermediateDirectory)/test_unrolled-list-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/unrolled-list-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(DependSuffix): test/unrolled-list-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(DependSuffix) -MM "test/unrolled-list-tests.cpp"

$(IntermediateDirectory)/test_unrolled-list-tests.cpp$(PreprocessSuffix): test/unrolled-list-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_unrolled-list-tests.cpp$(PreprocessSuffix) "test/unrolled-list-tests.cpp"

$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix): test/iterator-tests.cpp $(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/UnrolledList/test/iterator-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix): test/iterator-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix) -MM "test/iterator-tests.cpp"

$(IntermediateDirectory)/test_iterator-tests.cpp$(PreprocessSuffix): test/iterator-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_iterator-tests.cpp$(PreprocessSuffix) "test/iterator-tests.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


