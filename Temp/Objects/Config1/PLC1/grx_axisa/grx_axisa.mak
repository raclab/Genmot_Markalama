UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/GRXAxisobj/grx_axisa
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/GRXAxisobj/grx_axisa

$(AS_CPU_PATH)/grx_axisa.br: \
	$(AS_PROJECT_PATH)/Logical/GRXAxisobj/grx_axisa/gz1_axisa.apt
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/GRXAxisobj/grx_axisa/gz1_axisa.apt" -o "$(AS_CPU_PATH)/grx_axisa.br" -T SG4  -v V1.00.0 -s GRXAxisobj.grx_axisa -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

