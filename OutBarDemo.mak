# Microsoft Developer Studio Generated NMAKE File, Based on OutBarDemo.dsp
!IF "$(CFG)" == ""
CFG=OutBarDemo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to OutBarDemo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "OutBarDemo - Win32 Release" && "$(CFG)" != "OutBarDemo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\OutBarDemo.exe" "$(OUTDIR)\OutBarDemo.tlb"


CLEAN :
	-@erase "$(INTDIR)\EdhjSet.obj"
	-@erase "$(INTDIR)\GfxGroupEdit.obj"
	-@erase "$(INTDIR)\GfxOutBarCtrl.obj"
	-@erase "$(INTDIR)\GfxPopupMenu.obj"
	-@erase "$(INTDIR)\GfxSplitterWnd.obj"
	-@erase "$(INTDIR)\GlobalDoc.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MyTreeCtrl.obj"
	-@erase "$(INTDIR)\OutBarDemo.obj"
	-@erase "$(INTDIR)\OutBarDemo.pch"
	-@erase "$(INTDIR)\OutBarDemo.res"
	-@erase "$(INTDIR)\OutBarDemo.tlb"
	-@erase "$(INTDIR)\Setting.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TestView1.obj"
	-@erase "$(INTDIR)\UpEx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\OutBarDemo.exe"
	-@erase ".\OutBarDemo_i.c"
	-@erase ".\OutBarDemo_i.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=df.exe
F90_PROJ=/module:"Release/" /object:"Release/" 
F90_OBJS=.\Release/

.SUFFIXES: .fpp

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.fpp{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\OutBarDemo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\OutBarDemo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\OutBarDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\OutBarDemo.pdb" /machine:I386 /out:"$(OUTDIR)\OutBarDemo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\EdhjSet.obj" \
	"$(INTDIR)\GfxGroupEdit.obj" \
	"$(INTDIR)\GfxOutBarCtrl.obj" \
	"$(INTDIR)\GfxPopupMenu.obj" \
	"$(INTDIR)\GfxSplitterWnd.obj" \
	"$(INTDIR)\GlobalDoc.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MyTreeCtrl.obj" \
	"$(INTDIR)\OutBarDemo.obj" \
	"$(INTDIR)\Setting.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TestView1.obj" \
	"$(INTDIR)\UpEx.obj" \
	"$(INTDIR)\OutBarDemo.res"

"$(OUTDIR)\OutBarDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\OutBarDemo.exe" "$(OUTDIR)\OutBarDemo.tlb" ".\OutBarDemo_i.h" ".\OutBarDemo_i.c" "$(OUTDIR)\OutBarDemo.bsc"


CLEAN :
	-@erase "$(INTDIR)\EdhjSet.obj"
	-@erase "$(INTDIR)\EdhjSet.sbr"
	-@erase "$(INTDIR)\GfxGroupEdit.obj"
	-@erase "$(INTDIR)\GfxGroupEdit.sbr"
	-@erase "$(INTDIR)\GfxOutBarCtrl.obj"
	-@erase "$(INTDIR)\GfxOutBarCtrl.sbr"
	-@erase "$(INTDIR)\GfxPopupMenu.obj"
	-@erase "$(INTDIR)\GfxPopupMenu.sbr"
	-@erase "$(INTDIR)\GfxSplitterWnd.obj"
	-@erase "$(INTDIR)\GfxSplitterWnd.sbr"
	-@erase "$(INTDIR)\GlobalDoc.obj"
	-@erase "$(INTDIR)\GlobalDoc.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MyTreeCtrl.obj"
	-@erase "$(INTDIR)\MyTreeCtrl.sbr"
	-@erase "$(INTDIR)\OutBarDemo.obj"
	-@erase "$(INTDIR)\OutBarDemo.pch"
	-@erase "$(INTDIR)\OutBarDemo.res"
	-@erase "$(INTDIR)\OutBarDemo.sbr"
	-@erase "$(INTDIR)\OutBarDemo.tlb"
	-@erase "$(INTDIR)\Setting.obj"
	-@erase "$(INTDIR)\Setting.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TestView1.obj"
	-@erase "$(INTDIR)\TestView1.sbr"
	-@erase "$(INTDIR)\UpEx.obj"
	-@erase "$(INTDIR)\UpEx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\OutBarDemo.bsc"
	-@erase "$(OUTDIR)\OutBarDemo.exe"
	-@erase "$(OUTDIR)\OutBarDemo.ilk"
	-@erase "$(OUTDIR)\OutBarDemo.pdb"
	-@erase ".\OutBarDemo_i.c"
	-@erase ".\OutBarDemo_i.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=df.exe
F90_PROJ=/browser:"Debug/" /module:"Debug/" /object:"Debug/" 
F90_OBJS=.\Debug/

.SUFFIXES: .fpp

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.fpp{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\OutBarDemo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x410 /fo"$(INTDIR)\OutBarDemo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\OutBarDemo.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\EdhjSet.sbr" \
	"$(INTDIR)\GfxGroupEdit.sbr" \
	"$(INTDIR)\GfxOutBarCtrl.sbr" \
	"$(INTDIR)\GfxPopupMenu.sbr" \
	"$(INTDIR)\GfxSplitterWnd.sbr" \
	"$(INTDIR)\GlobalDoc.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MyTreeCtrl.sbr" \
	"$(INTDIR)\OutBarDemo.sbr" \
	"$(INTDIR)\Setting.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TestView1.sbr" \
	"$(INTDIR)\UpEx.sbr"

"$(OUTDIR)\OutBarDemo.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\OutBarDemo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\OutBarDemo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\EdhjSet.obj" \
	"$(INTDIR)\GfxGroupEdit.obj" \
	"$(INTDIR)\GfxOutBarCtrl.obj" \
	"$(INTDIR)\GfxPopupMenu.obj" \
	"$(INTDIR)\GfxSplitterWnd.obj" \
	"$(INTDIR)\GlobalDoc.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MyTreeCtrl.obj" \
	"$(INTDIR)\OutBarDemo.obj" \
	"$(INTDIR)\Setting.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TestView1.obj" \
	"$(INTDIR)\UpEx.obj" \
	"$(INTDIR)\OutBarDemo.res"

"$(OUTDIR)\OutBarDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("OutBarDemo.dep")
!INCLUDE "OutBarDemo.dep"
!ELSE 
!MESSAGE Warning: cannot find "OutBarDemo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "OutBarDemo - Win32 Release" || "$(CFG)" == "OutBarDemo - Win32 Debug"
SOURCE=.\EdhjSet.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\EdhjSet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\EdhjSet.obj"	"$(INTDIR)\EdhjSet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\GfxGroupEdit.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\GfxGroupEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\GfxGroupEdit.obj"	"$(INTDIR)\GfxGroupEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\GfxOutBarCtrl.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\GfxOutBarCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\GfxOutBarCtrl.obj"	"$(INTDIR)\GfxOutBarCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\GfxPopupMenu.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\GfxPopupMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\GfxPopupMenu.obj"	"$(INTDIR)\GfxPopupMenu.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\GfxSplitterWnd.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\GfxSplitterWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\GfxSplitterWnd.obj"	"$(INTDIR)\GfxSplitterWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\GlobalDoc.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\GlobalDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\GlobalDoc.obj"	"$(INTDIR)\GlobalDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\MyTreeCtrl.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\MyTreeCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\MyTreeCtrl.obj"	"$(INTDIR)\MyTreeCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\OutBarDemo.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\OutBarDemo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.c" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\OutBarDemo.obj"	"$(INTDIR)\OutBarDemo.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\OutBarDemo.idl

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\OutBarDemo.tlb" /h "OutBarDemo_i.h" /iid "OutBarDemo_i.c" /Oicf /o "NUL" /win32 

"$(INTDIR)\OutBarDemo.tlb"	".\OutBarDemo_i.h"	".\OutBarDemo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\OutBarDemo.tlb" /h "OutBarDemo_i.h" /iid "OutBarDemo_i.c" /Oicf /o "NUL" /win32 

"$(INTDIR)\OutBarDemo.tlb"	".\OutBarDemo_i.h"	".\OutBarDemo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\OutBarDemo.rc

"$(INTDIR)\OutBarDemo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Setting.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\Setting.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\Setting.obj"	"$(INTDIR)\Setting.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\Splash.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\Splash.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\OutBarDemo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\OutBarDemo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\OutBarDemo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\OutBarDemo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TestView1.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\TestView1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\TestView1.obj"	"$(INTDIR)\TestView1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 

SOURCE=.\UpEx.cpp

!IF  "$(CFG)" == "OutBarDemo - Win32 Release"


"$(INTDIR)\UpEx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch" ".\OutBarDemo_i.h"


!ELSEIF  "$(CFG)" == "OutBarDemo - Win32 Debug"


"$(INTDIR)\UpEx.obj"	"$(INTDIR)\UpEx.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OutBarDemo.pch"


!ENDIF 


!ENDIF 

