UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerAx2
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerAx2

$(AS_CPU_PATH)/PowerAx2.br: \
	$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/$(AS_PLC)/Cpu.per \
	$(AS_CPU_PATH)/PowerAx2/PowerAx2.ox
	@"$(AS_BIN_PATH)/BR.AS.TaskBuilder.exe" "$(AS_CPU_PATH)/PowerAx2/PowerAx2.ox" -o "$(AS_CPU_PATH)/PowerAx2.br" -v V1.00.0 -f "$(AS_CPU_PATH)/Global.ofs" -T SG4  -B R4.02 -extConstants -r Cyclic1 -p 3 -s PowerAx2 -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, Acp10sdc: V2.40.1, AsARCfg: V*, AsBrMath: V*, AsBrStr: V*, AsEPL: V*, AsIecCon: V*, asstring: V*, AsTime: V*, AsWeigh: V*, brsystem: V*, dvframe: V*, FileIO: V*, LoopConR: V2.80.9, NcGlobal: V2.40.1, Operator: V*, Runtime: V*, standard: V*, sys_lib: V*" -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.as.taskbuilder.exe"

$(AS_CPU_PATH)/PowerAx2/PowerAx2.ox: \
	$(AS_CPU_PATH)/PowerAx2/a.out
	@"$(AS_BIN_PATH)/BR.AS.Backend.exe" "$(AS_CPU_PATH)/PowerAx2/a.out" -o "$(AS_CPU_PATH)/PowerAx2/PowerAx2.ox" -T SG4 -r Cyclic1   -G V4.1.2  -secret "$(AS_PROJECT_PATH)_br.as.backend.exe"

$(AS_CPU_PATH)/PowerAx2/a.out: \
	$(AS_CPU_PATH)/PowerAx2/PowerAx2.o
	@"$(AS_BIN_PATH)/BR.AS.CCompiler.exe" -link -o "$(AS_CPU_PATH)/PowerAx2/a.out" "$(AS_CPU_PATH)/PowerAx2/PowerAx2.o"  -G V4.1.2  "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10sdc/SG4/libAcp10sdc.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10_MC/SG4/libAcp10_MC.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10man/SG4/libAcp10man.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libdvframe.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsARCfg.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsEPL.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libFileIO.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsBrStr.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/LoopConR/SG4/libLoopConR.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsBrMath.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsWeigh.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libasstring.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libstandard.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10par/SG4/libAcp10par.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/NcGlobal/SG4/libNcGlobal.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libsys_lib.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libbrsystem.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsIecCon.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsTime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libRuntime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libOperator.a" -specs=I386specs -Wl,-q,-T,SG4.x -T SG4  -secret "$(AS_PROJECT_PATH)_br.as.ccompiler.exe"

$(AS_CPU_PATH)/PowerAx2/PowerAx2.o: \
	$(AS_PROJECT_PATH)/Logical/PowerAx2/PowerAx2.c \
	$(AS_PROJECT_PATH)/Logical/Libraries/Acp10_MC/acp10_mc.fun \
	$(AS_PROJECT_PATH)/Logical/Libraries/Acp10_MC/acp10_mc.typ \
	$(AS_PROJECT_PATH)/Logical/Libraries/NcGlobal/Ncglobal.var \
	$(AS_PROJECT_PATH)/Logical/Libraries/Acp10_MC/acp10_mc.var \
	$(AS_PROJECT_PATH)/Logical/Global.var \
	$(AS_PROJECT_PATH)/Logical/Libraries/Acp10man/Acp10man.typ \
	$(AS_PROJECT_PATH)/Logical/Global.typ \
	$(AS_PROJECT_PATH)/Logical/PowerAx2/PowerAx2.var
	@"$(AS_BIN_PATH)/BR.AS.CCompiler.exe" "$(AS_PROJECT_PATH)/Logical/PowerAx2/PowerAx2.c" -o "$(AS_CPU_PATH)/PowerAx2/PowerAx2.o"  -T SG4  -B R4.02 -G V4.1.2  -s PowerAx2 -t "$(AS_TEMP_PATH)" -I "$(AS_PROJECT_PATH)/Logical/PowerAx2" "$(AS_TEMP_PATH)/Includes/PowerAx2" "$(AS_TEMP_PATH)/Includes" -trigraphs -fno-asm -D _DEFAULT_INCLUDES -D _SG4 -fPIC -O0 -g -nostartfiles -Wall -include "$(AS_CPU_PATH)/Libraries.h" -x c -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.as.ccompiler.exe"

-include $(AS_CPU_PATH)/Force.mak 

