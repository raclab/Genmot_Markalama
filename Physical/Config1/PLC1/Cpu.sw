<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio Version=3.0.90.36 SP18?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="PowerAx1" Source="PowerAx1.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PowerAx2" Source="PowerAx2.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RZAxisCont" Source="RZAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RYAxisCont" Source="RYAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RXAxisCont" Source="RXAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RAAxisCont" Source="RAAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RC1AxisCon" Source="RC1AxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="RC2AxisCon" Source="RC2AxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="GRXAxisCon" Source="GRXAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="GRZAxisCon" Source="GRZAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="Master" Source="Master.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#2">
    <Task Name="Sender" Source="LibDVFrame1_ST.Sender.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Receiver" Source="LibDVFrame1_ST.Receiver.prg" Memory="UserROM" Language="IEC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4">
    <Task Name="GRYAxisCon" Source="GRYAxisControl.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <DataObjects>
    <DataObject Name="Acp10sys" Source="" Memory="UserROM" Language="Binary" />
  </DataObjects>
  <NcDataObjects>
    <NcDataObject Name="acp10etxen" Source="acp10etxen.dob" Memory="UserROM" Language="Ett" />
    <NcDataObject Name="gaxis01i" Source="RYAxisobj.gaxis01i.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gaxis01a" Source="RYAxisobj.gaxis01a.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gaxis02i" Source="RAAxisobj.gaxis02i.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gaxis02a" Source="RAAxisobj.gaxis02a.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gaxis03i" Source="RXAxisobj.gaxis03i.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gaxis03a" Source="RXAxisobj.gaxis03a.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gz1_axisi" Source="RZAxisobj.gz1_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gz1_axisa" Source="RZAxisobj.gz1_axisa.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gc1_axisi" Source="RC1Axisobj.gc1_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gc2_axisa" Source="RC1Axisobj.gc2_axisa.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gc2_axisi" Source="RC2Axisobj.gc2_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gc2_axisa1" Source="RC2Axisobj.gc2_axisa.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="powersp1i" Source="PowerSp1obj.powersp1i.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="powersp1a" Source="PowerSp1obj.powersp1a.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="powersp2i" Source="PowerSp2obj.powersp2i.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="powersp2a" Source="PowerSp2obj.powersp2a.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="grx_axisi" Source="GRXAxisobj.grx_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="grx_axisa" Source="GRXAxisobj.grx_axisa.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="grz_axisi" Source="GRZAxisobj.grz_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="grz_axisa" Source="GRZAxisobj.grz_axisa.dob" Memory="UserROM" Language="Apt" />
    <NcDataObject Name="gry_axisi" Source="GRYAxisobj.gry_axisi.dob" Memory="UserROM" Language="Ax" />
    <NcDataObject Name="gry_axisa" Source="GRYAxisobj.gry_axisa.dob" Memory="UserROM" Language="Apt" />
  </NcDataObjects>
  <VcDataObjects />
  <Binaries>
    <BinaryObject Name="AsOPCC" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="ashwd" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="iomap" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Acp10cfg" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Acp10map" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Visu03" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcctrend" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccline" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcchtml" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcbclass" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccbmp" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcclbox" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccalarm" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcrt" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcshared" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcnet" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="arialbd" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcdsloc" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcgclass" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcresman" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccstr" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcmgr" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcfile" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcalarm" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccurl" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcpdsw" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Visu02" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcpdvnc" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcdsint" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccnum" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccbtn" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcpfar10" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcpkat" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vctcal" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="arial" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccovl" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcctext" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccshape" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcfntttf" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vcxml" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Visu01" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="visvc" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="vccbar" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="acp10_mc" Source="Libraries.Acp10_MC.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="brsystem" Source="Libraries.brsystem.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="Acp10man" Source="Libraries.Acp10man.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="sys_lib" Source="Libraries.sys_lib.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="NcGlobal" Source="Libraries.NcGlobal.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="Acp10par" Source="Libraries.Acp10par.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="runtime" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="Acp10sdc" Source="Libraries.Acp10sdc.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="standard" Source="Libraries.standard.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="asstring" Source="Libraries.asstring.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="astime" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="powerlnk" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsWeigh" Source="Libraries.AsWeigh.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsBrMath" Source="Libraries.AsBrMath.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="LoopConR" Source="Libraries.LoopConR.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsBrStr" Source="Libraries.AsBrStr.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="FileIO" Source="Libraries.FileIO.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsEPL" Source="Libraries.AsEPL.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsARCfg" Source="Libraries.AsARCfg.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="asieccon" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="dvframe" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="ashw" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="dataobj" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="visapi" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </Libraries>
</SwConfiguration>