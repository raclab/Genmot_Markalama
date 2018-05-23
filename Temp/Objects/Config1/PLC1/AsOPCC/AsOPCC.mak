$(AS_CPU_PATH)/AsOPCC.br: \
	$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct \
	$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct \
	$(AS_PROJECT_PATH)/Logical/Global.var
	@"$(AS_BIN_PATH)/BR.OPC.Builder.exe"  "$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct" -o "$(AS_CPU_PATH)/AsOPCC.br" -c Config1 -T SG4 -g "$(AS_TEMP_PATH)/Objects/Declarations.lst" -m "$(AS_CPU_PATH)/ConfigInfo.cfi" -P "$(AS_PROJECT_PATH)"
