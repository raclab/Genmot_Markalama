UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RAAxisobj/gaxis02a
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RAAxisobj/gaxis02a

$(AS_CPU_PATH)/gaxis02a.br: \
	$(AS_PROJECT_PATH)/Logical/RAAxisobj/gaxis02a/gaxis02a.apt
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/RAAxisobj/gaxis02a/gaxis02a.apt" -o "$(AS_CPU_PATH)/gaxis02a.br" -T SG4  -v V1.00.0 -s RAAxisobj.gaxis02a -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

