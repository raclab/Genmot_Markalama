UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RXAxisobj/gaxis03i
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/RXAxisobj/gaxis03i

$(AS_CPU_PATH)/gaxis03i.br: \
	$(AS_PROJECT_PATH)/Logical/RXAxisobj/gaxis03i/gaxis03i.ax
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/RXAxisobj/gaxis03i/gaxis03i.ax" -o "$(AS_CPU_PATH)/gaxis03i.br" -T SG4  -v V1.00.0 -s RXAxisobj.gaxis03i -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

