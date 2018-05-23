UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/acp10etxen
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/acp10etxen

$(AS_CPU_PATH)/acp10etxen.br: \
	$(AS_PROJECT_PATH)/Logical/acp10etxen/acp10etxen.ett
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/acp10etxen/acp10etxen.ett" -o "$(AS_CPU_PATH)/acp10etxen.br" -T SG4  -v V1.00.0 -s acp10etxen -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

