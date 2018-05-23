UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerSp2obj/powersp2i
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerSp2obj/powersp2i

$(AS_CPU_PATH)/powersp2i.br: \
	$(AS_PROJECT_PATH)/Logical/PowerSp2obj/powersp2i/powersp2i.ax
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/PowerSp2obj/powersp2i/powersp2i.ax" -o "$(AS_CPU_PATH)/powersp2i.br" -T SG4  -v V1.00.0 -s PowerSp2obj.powersp2i -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

