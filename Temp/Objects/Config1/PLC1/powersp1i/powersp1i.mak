UnmarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerSp1obj/powersp1i
MarkedObjectFolder := C:/projects/Genmot_Markalama_/Logical/PowerSp1obj/powersp1i

$(AS_CPU_PATH)/powersp1i.br: \
	$(AS_PROJECT_PATH)/Logical/PowerSp1obj/powersp1i/powersp1i.ax
	@"$(AS_BIN_PATH)/BR.MC.Builder.exe"   "$(AS_PROJECT_PATH)/Logical/PowerSp1obj/powersp1i/powersp1i.ax" -o "$(AS_CPU_PATH)/powersp1i.br" -T SG4  -v V1.00.0 -s PowerSp1obj.powersp1i -L "Acp10_MC: V2.40.1, Acp10man: V2.40.1, Acp10par: V2.40.1, NcGlobal: V2.40.1" -warmRestart -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.mc.builder.exe"

