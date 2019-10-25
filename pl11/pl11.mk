##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=pl11
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/C732S/Documents/CMasMas
ProjectPath            :=C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=C732S
Date                   :=26/10/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="pl11.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
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
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pasajero.cpp$(ObjectSuffix) $(IntermediateDirectory)/Airport.cpp$(ObjectSuffix) $(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) $(IntermediateDirectory)/Box.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Pasajero.cpp$(ObjectSuffix): Pasajero.cpp $(IntermediateDirectory)/Pasajero.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/Pasajero.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pasajero.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pasajero.cpp$(DependSuffix): Pasajero.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pasajero.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pasajero.cpp$(DependSuffix) -MM Pasajero.cpp

$(IntermediateDirectory)/Pasajero.cpp$(PreprocessSuffix): Pasajero.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pasajero.cpp$(PreprocessSuffix) Pasajero.cpp

$(IntermediateDirectory)/Airport.cpp$(ObjectSuffix): Airport.cpp $(IntermediateDirectory)/Airport.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/Airport.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Airport.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Airport.cpp$(DependSuffix): Airport.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Airport.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Airport.cpp$(DependSuffix) -MM Airport.cpp

$(IntermediateDirectory)/Airport.cpp$(PreprocessSuffix): Airport.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Airport.cpp$(PreprocessSuffix) Airport.cpp

$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix): Lista.cpp $(IntermediateDirectory)/Lista.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lista.cpp$(DependSuffix): Lista.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Lista.cpp$(DependSuffix) -MM Lista.cpp

$(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix): Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix) Lista.cpp

$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix): Cola.cpp $(IntermediateDirectory)/Cola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/Cola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cola.cpp$(DependSuffix): Cola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cola.cpp$(DependSuffix) -MM Cola.cpp

$(IntermediateDirectory)/Cola.cpp$(PreprocessSuffix): Cola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cola.cpp$(PreprocessSuffix) Cola.cpp

$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix): NodoCola.cpp $(IntermediateDirectory)/NodoCola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/NodoCola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoCola.cpp$(DependSuffix): NodoCola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NodoCola.cpp$(DependSuffix) -MM NodoCola.cpp

$(IntermediateDirectory)/NodoCola.cpp$(PreprocessSuffix): NodoCola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoCola.cpp$(PreprocessSuffix) NodoCola.cpp

$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix): NodoLista.cpp $(IntermediateDirectory)/NodoLista.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/NodoLista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoLista.cpp$(DependSuffix): NodoLista.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NodoLista.cpp$(DependSuffix) -MM NodoLista.cpp

$(IntermediateDirectory)/NodoLista.cpp$(PreprocessSuffix): NodoLista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoLista.cpp$(PreprocessSuffix) NodoLista.cpp

$(IntermediateDirectory)/Box.cpp$(ObjectSuffix): Box.cpp $(IntermediateDirectory)/Box.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/C732S/Desktop/repositorios/eedd_ejercicio_2/eedd/pl11/Box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Box.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Box.cpp$(DependSuffix): Box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Box.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Box.cpp$(DependSuffix) -MM Box.cpp

$(IntermediateDirectory)/Box.cpp$(PreprocessSuffix): Box.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Box.cpp$(PreprocessSuffix) Box.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


