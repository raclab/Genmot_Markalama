UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/LibDVFrame1_ST/Receiver
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/LibDVFrame1_ST/Receiver

$(AS_CPU_PATH)/Receiver.br: \
	$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/$(AS_PLC)/Cpu.per \
	$(AS_CPU_PATH)/Receiver/Receiver.ox
	@"$(AS_BIN_PATH)/BR.AS.TaskBuilder.exe" "$(AS_CPU_PATH)/Receiver/Receiver.ox" -o "$(AS_CPU_PATH)/Receiver.br" -v V1.00.0 -f "$(AS_CPU_PATH)/Global.ofs" -T SG4  -B R4.02 -extConstants -d "runtime: V* - V*,asieccon: V* - V*" -r Cyclic2 -p 3 -s LibDVFrame1_ST.Receiver -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, Acp10sdc: V2.40.1, AsARCfg: V*, AsBrMath: V*, AsBrStr: V*, AsEPL: V*, AsIecCon: V*, asstring: V*, AsTime: V*, AsWeigh: V*, brsystem: V*, dvframe: V*, FileIO: V*, LoopConR: V2.80.9, NcGlobal: V2.40.1, Operator: V*, Runtime: V*, standard: V*, sys_lib: V*" -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.as.taskbuilder.exe"

$(AS_CPU_PATH)/Receiver/Receiver.ox: \
	$(AS_CPU_PATH)/Receiver/a.out
	@"$(AS_BIN_PATH)/BR.AS.Backend.exe" "$(AS_CPU_PATH)/Receiver/a.out" -o "$(AS_CPU_PATH)/Receiver/Receiver.ox" -T SG4 -r Cyclic2   -G V4.1.2  -secret "$(AS_PROJECT_PATH)_br.as.backend.exe"

$(AS_CPU_PATH)/Receiver/a.out: \
	$(AS_CPU_PATH)/Receiver/ReceiverCyclic.o
	@"$(AS_BIN_PATH)/BR.AS.CCompiler.exe" -link -o "$(AS_CPU_PATH)/Receiver/a.out" "$(AS_CPU_PATH)/Receiver/ReceiverCyclic.o"  -G V4.1.2  "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10sdc/SG4/libAcp10sdc.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10_MC/SG4/libAcp10_MC.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10man/SG4/libAcp10man.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libdvframe.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsARCfg.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsEPL.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libFileIO.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsBrStr.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/LoopConR/SG4/libLoopConR.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsBrMath.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsWeigh.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libasstring.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libstandard.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/Acp10par/SG4/libAcp10par.a" "-Wl,$(AS_PROJECT_PATH)/Logical/Libraries/NcGlobal/SG4/libNcGlobal.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libsys_lib.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libbrsystem.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsIecCon.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libAsTime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libRuntime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/R0402/SG4/libOperator.a" -specs=I386specs -Wl,-q,-T,SG4.x -nostdlib "-Wl,$(AS_GNU_INST_PATH)/i386-elf/lib/libasiec.a" -T SG4  -secret "$(AS_PROJECT_PATH)_br.as.ccompiler.exe"

$(AS_CPU_PATH)/Receiver/ReceiverCyclic.o: \
	$(AS_PROJECT_PATH)/Logical/LibDVFrame1_ST/Receiver/ReceiverCyclic.st \
	$(AS_PROJECT_PATH)/Logical/Libraries/dvframe/dvframe.fun \
	$(AS_PROJECT_PATH)/Logical/Libraries/dvframe/dvframe.var \
	$(AS_PROJECT_PATH)/Logical/LibDVFrame1_ST/Receiver/Receiver.var \
	$(AS_PROJECT_PATH)/Logical/LibDVFrame1_ST/Receiver/Receiver.typ \
	$(AS_PROJECT_PATH)/Logical/Libraries/dvframe/dvframe.typ
	@"$(AS_BIN_PATH)/BR.AS.IecCompiler.exe" "$(AS_PROJECT_PATH)/Logical/LibDVFrame1_ST/Receiver/ReceiverCyclic.st" -o "$(AS_CPU_PATH)/Receiver/ReceiverCyclic.o"  -O "$(AS_CPU_PATH)/Receiver/ReceiverCyclic.o.opt" -secret "$(AS_PROJECT_PATH)_br.as.ieccompiler.exe"

-include $(AS_CPU_PATH)/Force.mak 

