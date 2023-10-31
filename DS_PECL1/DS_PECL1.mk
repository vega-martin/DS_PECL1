##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DS_PECL1
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=E:/DataStructure/DS_PECL1
ProjectPath            :=E:/DataStructure/DS_PECL1/DS_PECL1
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/DS_PECL1
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Vega
Date                   :=10/31/2023
CodeLitePath           :="E:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=E:/MinGW/bin/g++.exe
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=E:/DataStructure/DS_PECL1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=E:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcu
CXX      := E:/MinGW/bin/g++.exe
CC       := E:/MinGW/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix) $(IntermediateDirectory)/Package.cpp$(ObjectSuffix) $(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/DataStructure/DS_PECL1/DS_PECL1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix): Randomize.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/DataStructure/DS_PECL1/DS_PECL1/Randomize.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Randomize.cpp$(PreprocessSuffix): Randomize.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Randomize.cpp$(PreprocessSuffix) Randomize.cpp

$(IntermediateDirectory)/Package.cpp$(ObjectSuffix): Package.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/DataStructure/DS_PECL1/DS_PECL1/Package.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Package.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Package.cpp$(PreprocessSuffix): Package.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Package.cpp$(PreprocessSuffix) Package.cpp

$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix): Stack.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/DataStructure/DS_PECL1/DS_PECL1/Stack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix): Stack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix) Stack.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/DataStructure/DS_PECL1/DS_PECL1/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


