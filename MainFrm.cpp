// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"			//MFC类
#include "afxext.h"
#include <direct.h>

#include "stdio.h"
#include <errno.h>
#include <io.h>

#include "OutBarDemo.h"		//框架、界面类
#include "GlobalDoc.h"
#include "MainFrm.h"
#include "GfxOutBarCtrl.h"
#include "TestView1.h"
#include "Splash.h"
#include "MyTreeCtrl.h"

#include "mydlg.h"
#include "UpEx.h"			//对话框类
#include "EdhjSet.h"
#include "Setting.h"
#include "PreTrim.h"
#include "AbnormalCacu.h"
#include "Rdyt.h"
#include "ThrOp.h"
#include "SuffGrap.h"
#include "StaticTest.h"
#include "GravityQt.h"

#include "Notice.h"
#include "Flash.h"

#include <string.h>

typedef struct _person
{
	int   age;
	float weight, height;
} person;

#ifdef __cplusplus
extern "C" {
#endif

void GQT(int *m,int *n,float *ml,float *np,float *d,float *rest, char *a);

#ifdef __cplusplus
}
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_GFX_LARGEICON, OnGfxLargeicon)
	ON_UPDATE_COMMAND_UI(ID_GFX_LARGEICON, OnUpdateGfxLargeicon)
	ON_COMMAND(ID_GFX_SMALLICON, OnGfxSmallicon)
	ON_UPDATE_COMMAND_UI(ID_GFX_SMALLICON, OnUpdateGfxSmallicon)
	ON_COMMAND(ID_TITLE, OnTitle)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_ABNOMAL_CACU, OnAbnormalCacu)
	ON_COMMAND(ID_COHERENCE_MAG, OnCoherenceMag)
	ON_COMMAND(ID_COHERENCE_TEST, OnCoherenceTest)
	ON_COMMAND(ID_DIQIAN, OnDiqian)
	ON_COMMAND(ID_DOWN_EXTEND2, OnDownExtend2)
	ON_COMMAND(ID_DOWN_EXTEND3, OnDownExtend3)
	ON_COMMAND(ID_DYNAMIC_MULTI, OnDynamicMulti)
	ON_COMMAND(ID_DYNAMIC_TWO, OnDynamicTwo)
	ON_COMMAND(ID_DYNAMIC_TWOMAG, OnDynamicTwomag)
	ON_COMMAND(ID_PRE_TRIM, OnPreTrim)
	ON_COMMAND(ID_REVIEW_MAG, OnReviewMag)
	ON_COMMAND(ID_STATIC_TEST, OnStaticTest)
	ON_COMMAND(ID_SUFFER_DRAW, OnSufferDraw)
	ON_COMMAND(ID_UP_EXTEND2, OnUpExtend2)
	ON_COMMAND(ID_UP_EXTEND3, OnUpExtend3)
	ON_COMMAND(ID_EDHJ, OnEdhj)
	ON_COMMAND(ID_QT, OnQt)
	ON_WM_CLOSE()
	ON_COMMAND(ID_GRAPHER_DRAW, OnGrapherDraw)
	ON_COMMAND(ID_DYNAMIC_MULMAG, OnDynamicMulmag)
	ON_COMMAND(ID_GRAVITY_QT, OnGravityQt)
	ON_COMMAND(ID_MAG_DOWNEX2, OnMagDownex2)
	ON_COMMAND(ID_MAG_DOWNEX3, OnMagDownex3)
	ON_COMMAND(ID_MAG_UPEX2, OnMagUpex2)
	ON_COMMAND(ID_MAG_UPEX3, OnMagUpex3)
	ON_COMMAND(ID_MAG_VXZ2, OnMagVxz2)
	ON_COMMAND(ID_MAG_VXZ3, OnMagVxz3)
	ON_COMMAND(ID_MAG_VZZ2, OnMagVzz2)
	ON_COMMAND(ID_MAG_VZZ3, OnMagVzz3)
	ON_COMMAND(ID_MAG_VZZZ2, OnMagVzzz2)
	ON_COMMAND(ID_MAG_VZZZ3, OnMagVzzz3)
	ON_COMMAND(ID_STATIC_TESTMAG, OnStaticTestmag)
	ON_COMMAND(ID_VALUE_RIVISE, OnValueRivise)
	ON_COMMAND(ID_VALUETEST_MAG, OnValuetestMag)
	ON_COMMAND(ID_VXZ3, OnVxz3)
	ON_COMMAND(ID_VZZ2, OnVzz2)
	ON_COMMAND(ID_VZZ3, OnVzz3)
	ON_COMMAND(ID_VZZZ2, OnVzzz2)
	ON_COMMAND(ID_VZZZ3, OnVzzz3)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME,OnUpdateTime)
	ON_COMMAND(ID_DATA_REVIEW, OnDataReview)
	ON_COMMAND(ID_NOTICE, OnNotice)
	ON_COMMAND(ID_ABNORMAL_CACU, OnAbnormalCacu)
	ON_COMMAND(ID_THREE_OP, OnThreeOp)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_OUTBAR_NOTIFY, OnOutbarNotify)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_TIME,
	ID_INDICATOR_SCRL,

};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	_getcwd(thispath,200);
}

CMainFrame::~CMainFrame()
{
	::KillTimer(NULL,m_nIDTimer);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
//	_getcwd(thispath,200);

	_mkdir("c:\\mytemp");
	DeleteFile("C:\\mytemp\\execuerr.log");

	m_nIDTimer =::SetTimer(NULL,0,1000,TimerProc);

//	HINSTANCE ss;
	//char path[200];
    //GetModuleFileName(NULL,thispath,200);
//	ss=GetModuleHandle(NULL);

	//_chdir("..\");

//	MessageBox(path);
//	m_path=path;
//	this->UpdateData(FALSE);
//	return TRUE;  

	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) || !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) || !m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);

	m_wndToolBar.ModifyStyle(0,TBSTYLE_FLAT);//设置工具栏为平面格式 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

if( !CFrameWnd::PreCreateWindow(cs) )
        return FALSE;

    cs.style &= ~(LONG)FWS_ADDTOTITLE;//　这一个

    cs.lpszClass = AfxRegisterWndClass(0, NULL, NULL,AfxGetApp()->LoadIcon(IDR_MAINFRAME));
  
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	if (!wndSplitter.CreateStatic(this, 1, 2)) return false;

	if (!wndSplitter.CreateView(0, 1, pContext->m_pNewViewClass, CSize(0,0), pContext)) return false;

	DWORD dwf = CGfxOutBarCtrl::fDragItems|CGfxOutBarCtrl::fEditGroups|CGfxOutBarCtrl::fEditItems|CGfxOutBarCtrl::fRemoveGroups|
				CGfxOutBarCtrl::fRemoveItems|CGfxOutBarCtrl::fAddGroups|CGfxOutBarCtrl::fAnimation;
//				|CGfxOutBarCtrl::fSelHighlight;


	wndBar.Create(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), &wndSplitter, wndSplitter.IdFromRowCol(0, 0), dwf);
	wndBar.SetOwner(this);

	imaLarge.Create(IDB_IMAGELIST, 32, 0, RGB(128,128,128));
	imaSmall.Create(IDB_SMALL_IMAGELIST, 16, 0, RGB(0,128,128));

	wndBar.SetImageList(&imaLarge, CGfxOutBarCtrl::fLargeIcon);
	wndBar.SetImageList(&imaSmall, CGfxOutBarCtrl::fSmallIcon);

	wndTree.Create(WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS, CRect(0,0,0,0), &wndBar, 1010);
	wndTree.SetImageList(&imaSmall, TVSIL_NORMAL);

	wndTree1.Create(WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS, CRect(0,0,0,0), &wndBar, 1000);
	wndTree1.SetImageList(&imaSmall, TVSIL_NORMAL);

	wndTree2.Create(WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS, CRect(0,0,0,0), &wndBar, 1010);
	wndTree2.SetImageList(&imaSmall, TVSIL_NORMAL);

/*	wndTree3.Create(WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS, CRect(0,0,0,0), &wndBar, 1010);
	wndTree3.SetImageList(&imaSmall, TVSIL_NORMAL);

	wndTree4.Create(WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS, CRect(0,0,0,0), &wndBar, 1010);
	wndTree4.SetImageList(&imaSmall, TVSIL_NORMAL);
*/

//	wndBar.SetAnimationTickCount(20);

//	wndBar.SetAnimSelHighlight(200);

///////////////////////////////////////////////////////////////给树命名
	HTREEITEM htm = wndTree.InsertItem("仪器性能试验", 0,0);
	HTREEITEM htm1 = wndTree.InsertItem("静态试验", 1,1, htm);
			  htm1 = wndTree.InsertItem("动态试验", 1,1, htm);
	HTREEITEM	htm2 = wndTree.InsertItem("两点", 1,1, htm1);
				htm2 = wndTree.InsertItem("多点", 1,1, htm1);
			  htm1 = wndTree.InsertItem("仪器一致性检验", 1,1, htm);
			  htm1 = wndTree.InsertItem("格值校正", 1,1, htm);
	
			  htm = wndTree.InsertItem("资料整理", 0,0);
				htm1 = wndTree.InsertItem("初步整理", 1,1, htm);
				htm1 = wndTree.InsertItem("异常计算", 1,1, htm);

			  htm = wndTree.InsertItem("资料处理", 0,0);
				htm1 = wndTree.InsertItem("延拓", 1,1, htm);
					htm2 = wndTree.InsertItem("二度上延", 1,1, htm1);
					htm2 = wndTree.InsertItem("二度下延", 1,1, htm1);
					htm2 = wndTree.InsertItem("三度上延", 1,1, htm1);
					htm2 = wndTree.InsertItem("三度下延", 1,1, htm1);
				htm1 = wndTree.InsertItem("导数", 1,1, htm);
					htm2 = wndTree.InsertItem("二度Vxz", 1,1, htm1);
					htm2 = wndTree.InsertItem("二度Vzz", 1,1, htm1);
					htm2 = wndTree.InsertItem("二度Vzzz", 1,1, htm1);
					htm2 = wndTree.InsertItem("三度Vxz", 1,1, htm1);
					htm2 = wndTree.InsertItem("三度Vzz", 1,1, htm1);
					htm2 = wndTree.InsertItem("三度Vzzz", 1,1, htm1);
			  htm = wndTree.InsertItem("正演计算", 0,0);
				  htm1 = wndTree.InsertItem("球体", 1,1, htm);
				  htm1 = wndTree.InsertItem("二度体", 1,1, htm);
//
////////////////////////////////////////////////////////////////		磁法
	 htm = wndTree1.InsertItem("回放", 1,0);  //给树命名
			  htm1 = wndTree1.InsertItem("数据回放", 1,1, htm);
	 htm = wndTree1.InsertItem("仪器性能试验", 1,0);  //给树命名
			  htm1 = wndTree1.InsertItem("静态试验", 1,1, htm);
			  htm1 = wndTree1.InsertItem("动态试验", 1,1, htm);
				htm2 = wndTree1.InsertItem("两点", 1,1, htm1);
				htm2 = wndTree1.InsertItem("多点", 1,1, htm1);
			  htm1 = wndTree1.InsertItem("仪器一致性检验", 1,1, htm);
			  htm1 = wndTree.InsertItem("格值校正", 1,1, htm);
	
			  htm = wndTree1.InsertItem("资料整理", 1,0);
				htm1 = wndTree.InsertItem("初步整理", 1,1, htm);
				htm1 = wndTree.InsertItem("异常计算", 1,1, htm);

			  htm = wndTree1.InsertItem("资料处理", 1,0);
	  			htm1 = wndTree1.InsertItem("化极", 1,1, htm);
					htm2 = wndTree1.InsertItem("二度化极", 1,1, htm1);
				htm1 = wndTree1.InsertItem("延拓", 1,1, htm);
					htm2 = wndTree1.InsertItem("二度上延", 1,1, htm1);
					htm2 = wndTree1.InsertItem("二度下延", 1,1, htm1);
					htm2 = wndTree1.InsertItem("三度上延", 1,1, htm1);
					htm2 = wndTree1.InsertItem("三度下延", 1,1, htm1);
				htm1 = wndTree1.InsertItem("导数", 1,1, htm);
					htm2 = wndTree1.InsertItem("二度Vxz", 1,1, htm1);
					htm2 = wndTree1.InsertItem("二度Vzz", 1,1, htm1);
					htm2 = wndTree1.InsertItem("二度Vzzz", 1,1, htm1);
					htm2 = wndTree1.InsertItem("三度Vxz", 1,1, htm1);
					htm2 = wndTree1.InsertItem("三度Vzz", 1,1, htm1);
					htm2 = wndTree1.InsertItem("三度Vzzz", 1,1, htm1);
			  htm = wndTree1.InsertItem("正演计算", 1,0);
				htm1 = wndTree1.InsertItem("球体", 1,1, htm);
				htm1 = wndTree1.InsertItem("二度体", 1,1, htm);
			  htm = wndTree1.InsertItem("磁法三分量", 1,0);
				htm1 = wndTree1.InsertItem("磁三分量法", 1,1, htm);
/////////////////////////////////////////////////////////////			其它
			htm =	wndTree2.InsertItem("绘图", 0,2);
				htm1 =	wndTree2.InsertItem("GRAPHER", 1,1, htm);
						wndTree2.InsertItem("SUFFER", 1,1, htm);
/*			htm =	wndTree2.InsertItem("NMR", 0,2);
				htm1 =	wndTree2.InsertItem("NMR正演计算", 1,1, htm);
						wndTree2.InsertItem("NMR反演解释", 1,1, htm);
*/
////////////////////////////////////////////////////////自定义选项
CString str,strname,strexec,strt;
char cust[100];
//char name[20]
//char exec[100][100];
int len,lenl,lenr,pos;
	FILE *fp=NULL;
	if((fp=fopen("customize.ini","r"))==NULL)
	{
	MessageBox("自定义选项初始化失败!");//	return;
	}
	else 
	{while( !feof(fp) )
	{	if( ferror( fp ) )     
	{
		perror( "Read error" );
		break;
	}
	else
	{
		fscanf(fp,"%s",&cust);
		str.Format("%s",cust);
		len=str.GetLength();
		
		if(str.Left(1)=="@"){htm = wndTree2.InsertItem(str.Right(len-1), 0,2);}
		else if( str.Left(1)=="+" ){
			pos=str.Find("@");
			strt.Format("%s",str.Left(pos));
			lenl=pos-1;
			strname.Format("%s",strt.Right(lenl));
			pos+=2;
			lenr=len-pos;
			wndTree2.InsertItem(strname, 1,1, htm);	
			strexec.Format("%s",str.Right(lenr-1));
		}
		else {;}
	}
	}
	}
	fclose(fp);
////////////////////////////////////////////////////////给抽屉命名
	wndBar.AddFolder("预处理", 0);						
	wndBar.AddFolderBar("重力", &wndTree);
	wndBar.AddFolderBar("磁法", &wndTree1);
	wndBar.AddFolderBar("自定义、其它", &wndTree2);
	wndBar.AddFolder("综合", 1);
////////////////////////////////////////////////////////给.....命名???
	if((fp=fopen("customize.ini","r"))==NULL){;}
	while( !feof(fp) )
	{	if( ferror( fp ) )     
	{
	//	perror( "Read error" );
		break;
	}
	else
	{	fscanf(fp,"%s",&cust);
		str.Format("%s",cust);
		len=str.GetLength();	
		if( str.Left(1)=="$" || str.Left(1)=="%" )
			{int ifoder=0;
			if(str.Left(1)=="%" ) ifoder=4;
			pos=str.Find("@");
			strt.Format("%s",str.Left(pos));
			lenl=pos-1;
			strname.Format("%s",strt.Right(lenl));
			pos+=2;
			lenr=len-pos;
			wndBar.InsertItem(ifoder, 1, strname, 1, 0);
			strexec.Format("%s",str.Right(lenr-1));
			}
	}
	}
	wndBar.InsertItem(0, 0, "二度圆滑", 0, 0);			
	wndBar.InsertItem(0, 1, "平面圆滑", 1, 0);

	
/*	wndBar.InsertItem(4, 0, "Item 1", 0, 0);
	wndBar.InsertItem(4, 1, "Let's see what this Item will become actually 2", 1, 0);
	wndBar.InsertItem(4, 2, "Item 3", 0, 0);
	wndBar.InsertItem(4, 3, "Item 4", 3, 0);
*/
	wndBar.SetSelFolder(0);

	CRect r;
	GetClientRect(&r);

	int w1 = r.Width()/5;
	int w2 = r.Width()/6;

	wndSplitter.SetColumnInfo( 0, w1, 0 );
	wndSplitter.SetColumnInfo( 1, w2, 0 );

	wndSplitter.RecalcLayout();


	return true;
}

long CMainFrame::OnOutbarNotify(WPARAM wParam, LPARAM lParam)
{
	CSetting DlgSet;
	switch (wParam)
	{
		case NM_OB_ITEMCLICK:
		{
			break;
		}
	}
	
	return 0;
}

void CMainFrame::OnGfxLargeicon() 
{
	wndBar.SetSmallIconView(false);
}

void CMainFrame::OnUpdateGfxLargeicon(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(!wndBar.IsSmallIconView());
}

void CMainFrame::OnGfxSmallicon() 
{
	wndBar.SetSmallIconView(true);

}

void CMainFrame::OnUpdateGfxSmallicon(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(wndBar.IsSmallIconView());
}



//DEL  void CMainFrame::OnShowHideIEBar()
//DEL  { 
//DEL  	ShowControlBar(&m_IEBar, 
//DEL  		           (m_IEBar.GetStyle() & WS_VISIBLE) == 0, 
//DEL  		           FALSE);	
//DEL  }

void CMainFrame::OnTitle() 
{
	// TODO: Add your command handler code here
	AfxGetMainWnd() -> SetWindowText (_T("Application title") );
}


/*void CMainFrame::OnDblClkTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_htm = m_wndTree.GetSelectedItem();
	//以GetItemText()函数为例：
	CString S1 = m_wndTree.GetItemText(m_htm);
	AfxMessageBox("You have selected "+S1);
	*pResult = 0;	
}*/

void CMainFrame::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	MessageBox(">>>>>>我倒 |/_ 这是我倒下的过程~~~~ ");
	CFrameWnd::OnLButtonDblClk(nFlags, point);
}

void CMainFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CFrameWnd::OnSetFocus(pOldWnd);
	AfxGetMainWnd() -> SetWindowText (_T("重力&磁法数据整理与处理  版本1.0.0.1 刘爱华(06100214)") );

}

void CMainFrame::OnAbnormalCacu() 
{
CAbnormalCacu DlgSet;
if((DlgSet.DoModal())==IDOK)
{
	CallFunction();
	if(DlgSet.mopendata==1) 
	{
	FILE *fp=NULL;
	char path[200];
	int len=DlgSet.inpath.GetLength();
	strcpy(path,DlgSet.inpath.GetBuffer(len));
	if((fp=fopen(path,"r"))!=NULL)
	{char year[4],month[2],day[2];
	fscanf(fp,"%s%s%s",&year,&month,&day);
	fclose(fp);
	
	CMainFrame frm;
	int lenstr1=DlgSet.inname.GetLength();

	DlgSet.outfile.Format("%s%s%s%s%s%s%s",frm.thispath,"\\",DlgSet.m_first,month,"-",day,".wps");
	
	ShellExecute(NULL,"open","notepad.exe",DlgSet.outfile,NULL,SW_SHOW);}
	}//	else 
	//{AfxMessageBox("数据保存在了当前文件夹!");}
}
}
void CMainFrame::DoAbnormalCacu() 
{
	OnAbnormalCacu();	
}

void CMainFrame::OnCoherenceMag() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoCoherenceMag() 
{
OnCoherenceMag();	
}

void CMainFrame::OnCoherenceTest() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoCoherenceTest() 
{
	OnCoherenceTest(); 	
}

void CMainFrame:: OnDiqian()
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoDiqian() 
{
OnDiqian();	
}

void CMainFrame::OnDownExtend2()
{
CRdyt DlgSet;
if((DlgSet.DoModal())==IDOK)
{
	CallFunction();
	if(DlgSet.mopendata==1) 
		{ShellExecute(NULL,"open","notepad.exe",DlgSet.m_outfile,NULL,SW_SHOW);}
};

}
void CMainFrame::DoDownExtend2() 
{
OnDownExtend2();	
}

void CMainFrame::OnDownExtend3() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoDownExtend3() 
{
OnDownExtend3();	
}

void CMainFrame::OnDynamicMulti() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoDynamicMulti() 
{
OnDynamicMulti();	
}

void CMainFrame::OnDynamicTwo() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoDynamicTwo() 
{
OnDynamicTwo();	
}

void CMainFrame::OnDynamicTwomag() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoDynamicTwomag() 
{
OnDynamicTwomag();	
}

void CMainFrame::OnPreTrim() 
{
CPreTrim DlgSet;
if((DlgSet.DoModal())==IDOK){ CMainFrame::CallFunction();};
	// TODO: Add your command handler code here
}
void CMainFrame::DoPreTrim() 
{
	OnPreTrim();
}

void CMainFrame::OnReviewMag() 
{
	// TODO: Add your command handler code here
}

void CMainFrame::OnStaticTest() 
{
CStaticTest DlgSet;
if((DlgSet.DoModal())==IDOK){CallFunction();}
}
void CMainFrame::DoStaticTest() 
{
	OnStaticTest(); 
}

void CMainFrame::OnSufferDraw() 
{
	_chdir(thispath);
	FILE *fp=NULL;
	FILE *fp1=NULL;
	char path[200];
	CString str,strpath;
	HINSTANCE hin;
	int len;
	if((fp=fopen("sugrpath.liu","r+"))==NULL)
	{
		if((MessageBox("没有找到指定程序,是否现在指定?",NULL,MB_OKCANCEL))==IDCANCEL) return;

label:	CSuffGrap dlg;
		if((dlg.DoModal()==IDOK))
		{	_chdir(thispath);
			 if((fp1=fopen("sugrpath.liu","a"))==NULL)
			{
				fp1=fopen("sugrpath.liu","w+"); 
			}
			fprintf(fp1,"%s%c%s%c\n",dlg.m_type,'@',dlg.m_path,'#');
			fclose(fp1);
			goto label0;
		}
		else {return;}
//	fp=fopen("sugrpath.liu","r+");
label0:	in.open("sugrpath.liu");
	}
	else
	{in.open("sugrpath.liu");}
	
 while(!in.eof()) //	while(!feof( fp ))
	{
//	fscanf(fp,"%s",path);

	in.getline(path,128,'\n');

	if(path[0]=='S'||path[0]=='s')
		{
		CString str1;
		str.Format("%s",path);
		len=str.GetLength();
		str1.Format("%s",str.Right(len-7));
		strpath.Format("%s",str1.Left(len-8));
		if(strpath.Right(1)=="#")	{break;in.close();}
		}
	}
//MessageBox(strpath);
	if(strpath.GetLength()<=1) goto label;
	hin=ShellExecute(NULL,"open",strpath,NULL,NULL,SW_SHOW);
	if(((int)hin)<=32)
		{	
			if((MessageBox("没有找到指定程序,是否现在指定?",NULL,MB_OKCANCEL))==IDOK)
		{
			fclose(fp);
			in.close();
			goto label;
		}
	}
	in.close();
//	fclose(fp);
}


void CMainFrame::DoSufferDraw() 
{
OnSufferDraw();
}

void CMainFrame::OnUpExtend2() 
{
CRdyt DlgSet;
if((DlgSet.DoModal())==IDOK)
{
	CallFunction();
	if(DlgSet.mopendata==1) 
		{ShellExecute(NULL,"open","notepad.exe",DlgSet.m_outfile,NULL,SW_SHOW);}
};
}
void CMainFrame::DoUpExtend2() 
{
	OnUpExtend2();
}

void CMainFrame::OnUpExtend3() 
{
	// TODO: Add your command handler code here
}
void CMainFrame::DoUpExtend3() 
{
	OnUpExtend3();
}

void CMainFrame::OnQt() 
{	CSetting DlgSet;

	AfxGetMainWnd() -> SetWindowText (_T("球体正演计算") );
	if(DlgSet.DoModal()==IDOK)
	{
		//运行并等待程序结束
		CMainFrame::CallFunction();

		if(DlgSet.mopendata==1) 
		{ShellExecute(NULL,"open","notepad.exe",DlgSet.m_8,NULL,SW_SHOW);}
		//else {AfxMessageBox("数据保存在了:"+(CString)DlgSet.m_8);}
		/*ShellExecute(this->m_hWnd,"open","mailto:nishinapp@yahoo.com","","", SW_SHOW );*/
		}
	else 
	{
	//	AfxMessageBox("您已经取消了操作!");
	}

//	CSetting *dlg =new CSetting;			//无模对话框
//	dlg ->Create(IDD_SETTING,NULL);
//	dlg ->ShowWindow(SW_SHOW);

}

void CMainFrame::OnEdhj() 
{
    CEdhjSet DlgSet;
	AfxGetMainWnd() -> SetWindowText (_T("二度化极") );

	if(DlgSet.DoModal()==IDOK) 
	{
		CMainFrame::CallFunction();
		if(DlgSet.mopendata==1) 
		{ShellExecute(NULL,"open","notepad.exe",DlgSet.m_out,NULL,SW_SHOW);}
	//	else {AfxMessageBox("数据保存在了:"+(CString)DlgSet.m_out);}
	}
	else 
	{
	//	AfxMessageBox("您已经取消了操作!");

	}
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DeleteFile("C:\\mytemp\\input.liu");
	DeleteFile("C:\\mytemp\\type.liu");
	DeleteFile("C:\\mytemp\\execuerr.log");
	CFrameWnd::OnClose();
}

void CMainFrame::OnGrapherDraw() 
{
	_chdir(thispath);
	FILE *fp=NULL;
	FILE *fp1=NULL;
	char path[200];
	CString str,strpath;
	HINSTANCE hin;
	int len;
	if((fp=fopen("sugrpath.liu","r+"))==NULL)
	{
		if((MessageBox("没有找到指定程序,是否现在指定?",NULL,MB_OKCANCEL))==IDCANCEL) return;

label:	CSuffGrap dlg;
		if((dlg.DoModal()==IDOK))
		{	_chdir(thispath);
			 if((fp1=fopen("sugrpath.liu","a"))==NULL)
			{
				fp1=fopen("sugrpath.liu","w+"); 
			}
			fprintf(fp1,"%s%c%s%c\n",dlg.m_type,'@',dlg.m_path,'#');
			fclose(fp1);
			goto label0;
		}
		else {return;}
//	fp=fopen("sugrpath.liu","r+");
label0:	in.open("sugrpath.liu");
	}
	else
	{in.open("sugrpath.liu");}
	
 while(!in.eof()) //	while(!feof( fp ))
	{
//	fscanf(fp,"%s",path);

	in.getline(path,128,'\n');

	if(path[0]=='G'||path[0]=='g')
		{
		CString str1;
		str.Format("%s",path);
		len=str.GetLength();
		str1.Format("%s",str.Right(len-8));
		strpath.Format("%s",str1.Left(len-9));
		if(strpath.Right(1)=="#")	{break;in.close();}
		}
	}
// MessageBox(strpath);
	if(strpath.GetLength()<=1) goto label;
	hin=ShellExecute(NULL,"open",strpath,NULL,NULL,SW_SHOW);
	if(((int)hin)<=32)
		{	
			if((MessageBox("没有找到指定程序,是否现在指定?",NULL,MB_OKCANCEL))==IDOK)
		{
			fclose(fp);
			in.close();
			goto label;
		}
	}
	in.close();
//	fclose(fp);
}

void CMainFrame::DoGrapher() 
{
 CMainFrame::OnGrapherDraw();
}

void CMainFrame::DoEdhj()
{
  OnEdhj();
}

void CMainFrame::DoSetting()
{
  CMainFrame::OnQt();
}

void CMainFrame::DoSuffer()
{
  CMainFrame::OnSufferDraw();
}

void CMainFrame::OnDynamicMulmag() 
{
	// TODO: Add your command handler code here
AfxMessageBox("OnDynamicMulmag()");	
}
void CMainFrame::DoDynamicMulmag() 
{
OnDynamicMulmag();	
}

void CMainFrame::OnGravityQt() 
{
 // GQT(int m,int n,float ml,float np,float d,float rest, char *a);
CGravityQt DlgSet;
char str[]= "c:\\my temp\\out.txt";
 int m=1251,n=1251;
 int len;
 float ml=1.0,np=1.0,d=10.0,rest=2000.0;
 if(DlgSet.DoModal()==IDOK)
	{m=DlgSet.m_ln;
	 n=DlgSet.m_pn;
	 ml=DlgSet.m_l;
	 np=DlgSet.m_p;
	 d=DlgSet.m_h;
	 rest=DlgSet.m_rou*1000;
	 len=DlgSet.m_output.GetLength();
	 strcpy(str,DlgSet.m_output.GetBuffer(len));
 
	 GQT(&m,&n,&ml,&np,&d,&rest,str);
 
	 MessageBox("数据保存在"+DlgSet.m_output);
	 if(DlgSet.mopendata==1) ShellExecute(NULL,"open","notepad.exe",str,NULL,SW_SHOW);//wsprintf
	}
}
void CMainFrame:: DoGravityQt()
{
	OnGravityQt();
}

void CMainFrame::OnMagDownex2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagDownex2() 
{
	OnMagDownex2() ;
}

void CMainFrame::OnMagDownex3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagDownex3() 
{
	OnMagDownex3() ;
}

void CMainFrame::OnMagUpex2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagUpex2() 
{
	OnMagUpex2();
}

void CMainFrame::OnMagUpex3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagUpex3() 
{
	OnMagUpex3() ;
}

void CMainFrame::OnMagVxz2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagVxz2() 
{
	OnMagVxz2() ;
}

void CMainFrame::OnMagVxz3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagVxz3() 
{
	OnMagVxz3() ;
}

void CMainFrame::OnMagVzz2() 
{
	
	
}
void CMainFrame::DoMagVzz2() 
{
	OnMagVzz2() ;
}

void CMainFrame::OnMagVzz3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagVzz3() 
{
	OnMagVzz3() ;
}

void CMainFrame::OnMagVzzz2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagVzzz2() 
{
	OnMagVzzz2();
}

void CMainFrame::OnMagVzzz3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoMagVzzz3() 
{
	OnMagVzzz3();
}

void CMainFrame::OnStaticTestmag() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoStaticTestmag() 
{
	OnStaticTestmag() ;
}

void CMainFrame::OnValueRivise()				//格值校正::重力
{
	// TODO: Add your command handler code here

}
void CMainFrame::DoValueRivise() 
{
	OnValueRivise();
}

void CMainFrame::OnValuetestMag() 				//磁法::格值校正
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoValuetestMag()
{
	OnValuetestMag();
}

 void CMainFrame::OnVxz2() 
 {
 	// TODO: Add your command handler code here
 	
 }
void CMainFrame::DoVxz2() 
{
	OnVxz2() ;
}

void CMainFrame::OnVxz3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoVxz3() 
{
	OnVxz3();
}

void CMainFrame::OnVzz2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoVzz2() 
{
	OnVzz2();
}

void CMainFrame::OnVzz3() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoVzz3() 
{
	OnVzz3() ;
}

void CMainFrame::OnVzzz2() 
{
	// TODO: Add your command handler code here
	
}
void CMainFrame::DoVzzz2() 
{
	OnVzzz2();
}

void CMainFrame::OnVzzz3() 
{
CMyDlg DlgSet;
DlgSet.DoModal();	// TODO: Add your command handler code here
	
}
void CMainFrame::DoVzzz3() 
{
	OnVzzz3();
}









void CMainFrame::OnUpdateTime(CCmdUI *pCmdUI)		
{
	CTime t =CTime::GetCurrentTime();
	char szTime[10];
	int nHour = t.GetHour();
	int nMinute = t.GetMinute();
	int nSec = t.GetSecond();
	wsprintf(szTime,"%i:%02i:%02i",nHour,nMinute,nSec);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_TIME),LPCSTR(szTime));
	pCmdUI->Enable();

}

void CALLBACK CMainFrame::TimerProc(HWND hwnd, UINT uMsg, UINT uIDEvent, DWORD dwTime)
{//
	CMainFrame *pMainWnd = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	ASSERT(uIDEvent == (unsigned)pMainWnd->m_nIDTimer);

	CCmdUI cui;
		cui.m_nID= ID_INDICATOR_TIME;
		cui.m_nIndex=6;
		cui.m_pMenu=NULL;
		cui.m_pOther=&pMainWnd->m_wndStatusBar;
	pMainWnd->OnUpdateTime(&cui);
}

void CMainFrame::CallFunction()  //调用计算程序的子函数代码
{								 //调用并等待结束
		CString str;
//		CString str1,str2,str3;
//int len;
	// str.Format("%s%s",thispath,"\\caculation.exe");
//len=str.GetLength();
//len-=14;
//str3=str;
//str2=str.Left(len);
//	str1.Format("%s%s",str,"caculation.exe"	);
//		
	_chdir(thispath);
//	MessageBox(str);
			SHELLEXECUTEINFO ShExecInfo = {0};
			ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
			ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
			ShExecInfo.hwnd = NULL;
			ShExecInfo.lpVerb = NULL;
			ShExecInfo.lpFile = "caculation.exe";	
		//	ShExecInfo.lpFile = str;					//打开程序
			ShExecInfo.lpParameters = "";	
			ShExecInfo.lpDirectory = NULL;
			ShExecInfo.nShow = SW_HIDE;
			ShExecInfo.hInstApp = NULL;	
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	FILE *fp;
	if((fp=fopen("C:\\mytemp\\execuerr.log","r"))!=NULL) 
	{	fclose(fp);
	ShellExecute(NULL,"open","notepad.exe","C:\\mytemp\\execuerr.log",NULL,SW_SHOW);
	AfxMessageBox("计算过程出错!!");
	DeleteFile("C:\\mytemp\\execuerr.log"); /////!!!!!
	}
}

void CMainFrame::OnDataReview() //磁法::数据回放
{
	CFlash dlg;
	dlg.DoModal();
	ShellExecute(NULL,"open","ENVIbyYRM.exe",NULL,NULL,SW_SHOW);
	//程序ENVIbyYRM.exe由杨锐明同学提供
	//Program ENVIbyYRM is provided by RuimingYang
}
void CMainFrame::DoDataReview() //被tree调用的子函数
{
	OnDataReview();
}

void CMainFrame::OnNotice() 
{
	// TODO: Add your command handler code here
CNotice DlgSet;
DlgSet.DoModal();	
}

void CMainFrame::OnThreeOp() 
{
	CThrOp DlgSet;
	if((DlgSet.DoModal())==IDOK)
	CallFunction();
}
