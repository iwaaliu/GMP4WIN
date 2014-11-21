# Microsoft Developer Studio Project File - Name="OutBarDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=OutBarDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OutBarDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OutBarDemo.mak" CFG="OutBarDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OutBarDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "OutBarDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /o "NUL" /win32
# ADD BASE RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD F90 /browser
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /o "NUL" /win32
# ADD BASE RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 GMTDLL.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "OutBarDemo - Win32 Release"
# Name "OutBarDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AbnormalCacu.cpp
# End Source File
# Begin Source File

SOURCE=.\EdhjSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Flash.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxGroupEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxOutBarCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxPopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxSplitterWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\GlobalDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\GravityQt.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Notice.cpp
# End Source File
# Begin Source File

SOURCE=.\OutBarDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\OutBarDemo.idl
# ADD MTL /h "OutBarDemo_i.h" /iid "OutBarDemo_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\OutBarDemo.rc
# End Source File
# Begin Source File

SOURCE=.\PreTrim.cpp
# End Source File
# Begin Source File

SOURCE=.\Rdyh.cpp
# End Source File
# Begin Source File

SOURCE=.\Rdyt.cpp
# End Source File
# Begin Source File

SOURCE=.\Setting.cpp
# End Source File
# Begin Source File

SOURCE=.\SmoothSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StaticTest.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SuffGrap.cpp
# End Source File
# Begin Source File

SOURCE=.\TestView1.cpp
# End Source File
# Begin Source File

SOURCE=.\ThrOp.cpp
# End Source File
# Begin Source File

SOURCE=.\UpEx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AbnormalCacu.h
# End Source File
# Begin Source File

SOURCE=.\EdhjSet.h
# End Source File
# Begin Source File

SOURCE=.\Flash.h
# End Source File
# Begin Source File

SOURCE=.\GfxGroupEdit.h
# End Source File
# Begin Source File

SOURCE=.\GfxOutBarCtrl.h
# End Source File
# Begin Source File

SOURCE=.\GfxPopupMenu.h
# End Source File
# Begin Source File

SOURCE=.\GfxSplitterWnd.h
# End Source File
# Begin Source File

SOURCE=.\GlobalDoc.h
# End Source File
# Begin Source File

SOURCE=.\GravityQt.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MyDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Notice.h
# End Source File
# Begin Source File

SOURCE=.\OutBarDemo.h
# End Source File
# Begin Source File

SOURCE=.\PreTrim.h
# End Source File
# Begin Source File

SOURCE=.\Rdyh.h
# End Source File
# Begin Source File

SOURCE=.\Rdyt.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Setting.h
# End Source File
# Begin Source File

SOURCE=.\SmoothSet.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StaticTest.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SuffGrap.h
# End Source File
# Begin Source File

SOURCE=.\TestView1.h
# End Source File
# Begin Source File

SOURCE=.\ThrOp.h
# End Source File
# Begin Source File

SOURCE=.\UpEx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\dragging.cur
# End Source File
# Begin Source File

SOURCE=.\res\GlobalDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icr_hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\imageList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MAIL18.ICO
# End Source File
# Begin Source File

SOURCE=.\res\MSN.ICO
# End Source File
# Begin Source File

SOURCE=.\res\nodraggi.cur
# End Source File
# Begin Source File

SOURCE=.\res\OutBarDemo.ico
# End Source File
# Begin Source File

SOURCE=.\res\OutBarDemo.rc2
# End Source File
# Begin Source File

SOURCE=.\s.bmp
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\treeImageList.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\html1.htm
# End Source File
# Begin Source File

SOURCE=.\OutBarDemo.rgs
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section OutBarDemo : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:107
# 	2:21:SplashScreenInsertKey:4.0
# End Section
# Section OutBarDemo : {006E006F-0065-0020-6400-65006C006C00}
# 	1:14:IDR_OUTBARDEMO:108
# End Section
# Section OutBarDemo : {CD6C7868-5864-11D0-ABF0-0020AF6B0B7A}
# 	2:21:DefaultSinkHeaderFile:tv.h
# 	2:16:DefaultSinkClass:CTV
# End Section
# Section OutBarDemo : {D8EF53B0-11BB-11D2-8437-0000B43382FE}
# 	2:16:GfxSplitterWnd.h:GfxSplitterWnd.h
# 	2:22:CLASS: CGfxSplitterWnd:CGfxSplitterWnd
# 	2:18:GfxSplitterWnd.cpp:GfxSplitterWnd.cpp
# 	2:19:Application Include:OutBarDemo.h
# End Section
# Section OutBarDemo : {CD6C7866-5864-11D0-ABF0-0020AF6B0B7A}
# 	2:5:Class:CTV
# 	2:10:HeaderFile:tv.h
# 	2:8:ImplFile:tv.cpp
# End Section
# Section OutBarDemo : {C60DD072-1276-11D2-843A-0000B43382FE}
# 	2:16:GfxPopupMenu.cpp:GfxPopupMenu.cpp
# 	2:14:GfxPopupMenu.h:GfxPopupMenu.h
# 	2:19:Application Include:OutBarDemo.h
# 	2:20:CLASS: CGfxPopupMenu:CGfxPopupMenu
# End Section
