UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RYAxisobj/gaxis01a
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RYAxisobj/gaxis01a

$(AS_CPU_PATH)/gaxis01a.br: \
	$(AS_PROJECT_PATH)/Logical/RYAxisobj/gaxis01a/gaxis01a.apt
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/RYAxisobj/gaxis01a/gaxis01a.apt" -o "$(AS_CPU_PATH)/gaxis01a.br" -T SG4  -v V1.00.0 -s RYAxisobj.gaxis01a -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

