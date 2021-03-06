##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=VectorList
ConfigurationName      :=Release
WorkspacePath          :=/home/christian/experimental
ProjectPath            :=/home/christian/experimental/VectorList
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Christian
Date                   :=08/04/16
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="VectorList.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pthread 
ArLibs                 :=  "pthread" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-5
CC       := /usr/bin/gcc-5
CXXFLAGS :=  -pg -O3 -fexpensive-optimizations -pedantic -W -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -pg -O3 -fexpensive-optimizations -pedantic -W -std=c++14 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/helpers_utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_element-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_utils-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_vectorlist-tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_spinlock-tests.cpp$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/helpers_utils.cpp$(ObjectSuffix): helpers/utils.cpp $(IntermediateDirectory)/helpers_utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/helpers/utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/helpers_utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/helpers_utils.cpp$(DependSuffix): helpers/utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/helpers_utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/helpers_utils.cpp$(DependSuffix) -MM "helpers/utils.cpp"

$(IntermediateDirectory)/helpers_utils.cpp$(PreprocessSuffix): helpers/utils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/helpers_utils.cpp$(PreprocessSuffix) "helpers/utils.cpp"

$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix): test/test.cpp $(IntermediateDirectory)/test_test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_test.cpp$(DependSuffix): test/test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_test.cpp$(DependSuffix) -MM "test/test.cpp"

$(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix): test/test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix) "test/test.cpp"

$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix): test/iterator-tests.cpp $(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/iterator-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix): test/iterator-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_iterator-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_iterator-tests.cpp$(DependSuffix) -MM "test/iterator-tests.cpp"

$(IntermediateDirectory)/test_iterator-tests.cpp$(PreprocessSuffix): test/iterator-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_iterator-tests.cpp$(PreprocessSuffix) "test/iterator-tests.cpp"

$(IntermediateDirectory)/test_element-tests.cpp$(ObjectSuffix): test/element-tests.cpp $(IntermediateDirectory)/test_element-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/element-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_element-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_element-tests.cpp$(DependSuffix): test/element-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_element-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_element-tests.cpp$(DependSuffix) -MM "test/element-tests.cpp"

$(IntermediateDirectory)/test_element-tests.cpp$(PreprocessSuffix): test/element-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_element-tests.cpp$(PreprocessSuffix) "test/element-tests.cpp"

$(IntermediateDirectory)/test_utils-tests.cpp$(ObjectSuffix): test/utils-tests.cpp $(IntermediateDirectory)/test_utils-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/utils-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_utils-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_utils-tests.cpp$(DependSuffix): test/utils-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_utils-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_utils-tests.cpp$(DependSuffix) -MM "test/utils-tests.cpp"

$(IntermediateDirectory)/test_utils-tests.cpp$(PreprocessSuffix): test/utils-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_utils-tests.cpp$(PreprocessSuffix) "test/utils-tests.cpp"

$(IntermediateDirectory)/test_vectorlist-tests.cpp$(ObjectSuffix): test/vectorlist-tests.cpp $(IntermediateDirectory)/test_vectorlist-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/vectorlist-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_vectorlist-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_vectorlist-tests.cpp$(DependSuffix): test/vectorlist-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_vectorlist-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_vectorlist-tests.cpp$(DependSuffix) -MM "test/vectorlist-tests.cpp"

$(IntermediateDirectory)/test_vectorlist-tests.cpp$(PreprocessSuffix): test/vectorlist-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_vectorlist-tests.cpp$(PreprocessSuffix) "test/vectorlist-tests.cpp"

$(IntermediateDirectory)/test_spinlock-tests.cpp$(ObjectSuffix): test/spinlock-tests.cpp $(IntermediateDirectory)/test_spinlock-tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/christian/experimental/VectorList/test/spinlock-tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_spinlock-tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_spinlock-tests.cpp$(DependSuffix): test/spinlock-tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_spinlock-tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_spinlock-tests.cpp$(DependSuffix) -MM "test/spinlock-tests.cpp"

$(IntermediateDirectory)/test_spinlock-tests.cpp$(PreprocessSuffix): test/spinlock-tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_spinlock-tests.cpp$(PreprocessSuffix) "test/spinlock-tests.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


