UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RZAxisobj/gz1_axisi
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RZAxisobj/gz1_axisi

$(AS_CPU_PATH)/gz1_axisi.br: \
	$(AS_PROJECT_PATH)/Logical/RZAxisobj/gz1_axisi/gz1_axisi.ax
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/RZAxisobj/gz1_axisi/gz1_axisi.ax" -o "$(AS_CPU_PATH)/gz1_axisi.br" -T SG4  -v V1.00.0 -s RZAxisobj.gz1_axisi -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

