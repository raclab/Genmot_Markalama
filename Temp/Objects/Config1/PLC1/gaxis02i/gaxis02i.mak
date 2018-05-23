UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RAAxisobj/gaxis02i
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RAAxisobj/gaxis02i

$(AS_CPU_PATH)/gaxis02i.br: \
	$(AS_PROJECT_PATH)/Logical/RAAxisobj/gaxis02i/gaxis02i.ax
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/RAAxisobj/gaxis02i/gaxis02i.ax" -o "$(AS_CPU_PATH)/gaxis02i.br" -T SG4  -v V1.00.0 -s RAAxisobj.gaxis02i -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

