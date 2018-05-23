$(AS_CPU_PATH)/LazerOpcMap.opcs: \
	$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct \
	$(AS_PROJECT_PATH)/Physical/Config1/PLC1/LazerOpcMap.opcm \
	$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct \
	$(AS_PROJECT_PATH)/Logical/Global.var
	@"$(AS_BIN_PATH)/BR.OPC.Builder.exe"  "$(AS_PROJECT_PATH)/Logical/LazerMarkalama.opct" -o "$(AS_CPU_PATH)/LazerOpcMap.opcs" -x "$(AS_PROJECT_PATH)/Physical/Config1/PLC1/LazerOpcMap.opcm" -c Config1 -T Win -g "$(AS_TEMP_PATH)/Objects/Declarations.lst" -m "$(AS_CPU_PATH)/ConfigInfo.cfi" -P "$(AS_PROJECT_PATH)" -C "/RT=1000 /DAIP=192.168.137.2 /REPO=11159 /ANSL=1" -D "/IF=tcpip /LOPO=11159 /SA=1" -p "@/Pvi/LNINA2/Config1/PLC1/CPU" -remoteTimeout "0" -remoteRetryTime "5" -remoteInitParam "IP=195.168.0.101 PN=20000 LM=100"
