##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DS_PECL1
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/DataStructure/PECL1/DS_PECL1
ProjectPath            :=C:/DataStructure/PECL1/DS_PECL1/DS_PECL1
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/DS_PECL1
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Vega
Date                   :=11/7/2023
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/msys64/clang64/bin/clang++.exe
SharedObjectLinkerName :=C:/msys64/clang64/bin/clang++.exe -shared -fPIC
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
OutputDirectory        :=C:/DataStructure/PECL1/DS_PECL1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/clang64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)C:\msys64\clang64\include\c++\v1 $(IncludeSwitch)C:\msys64\clang64\lib\clang\17\include $(IncludeSwitch)C:\msys64\clang64\include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/clang64/bin/ar.exe -r
CXX      := C:/msys64/clang64/bin/clang++.exe
CC       := C:/msys64/clang64/bin/clang.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/clang64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Package.cpp$(ObjectSuffix) $(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix) $(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Central.cpp$(ObjectSuffix) $(IntermediateDirectory)/Show.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Package.cpp$(ObjectSuffix): Package.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Package.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Package.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Package.cpp$(PreprocessSuffix): Package.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Package.cpp$(PreprocessSuffix) Package.cpp

$(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix): Randomize.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Randomize.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Randomize.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Randomize.cpp$(PreprocessSuffix): Randomize.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Randomize.cpp$(PreprocessSuffix) Randomize.cpp

$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix): Stack.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Stack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Stack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix): Stack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Stack.cpp$(PreprocessSuffix) Stack.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

$(IntermediateDirectory)/Central.cpp$(ObjectSuffix): Central.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Central.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Central.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Central.cpp$(PreprocessSuffix): Central.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Central.cpp$(PreprocessSuffix) Central.cpp

$(IntermediateDirectory)/Show.cpp$(ObjectSuffix): Show.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/DataStructure/PECL1/DS_PECL1/DS_PECL1/Show.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Show.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Show.cpp$(PreprocessSuffix): Show.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Show.cpp$(PreprocessSuffix) Show.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


