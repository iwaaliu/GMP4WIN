// EdhjSet.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "EdhjSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEdhjSet dialog


CEdhjSet::CEdhjSet(CWnd* pParent /*=NULL*/)
	: CDialog(CEdhjSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEdhjSet)
	m_a = 0.0f;
	m_ai = 0.0f;
	m_in = _T("");
	m_out = _T("");
	m_no = 31;
	//}}AFX_DATA_INIT
}


void CEdhjSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEdhjSet)
	DDX_Control(pDX, IDC_CHECK_EDHJ, m_opendata);
	DDX_Text(pDX, IDC_A, m_a);
	DDV_MinMaxFloat(pDX, m_a, -90.f, 90.f);
	DDX_Text(pDX, IDC_AI, m_ai);
	DDV_MinMaxFloat(pDX, m_ai, -90.f, 90.f);
	DDX_Text(pDX, IDC_FILEIN, m_in);
	DDX_Text(pDX, IDC_FILEOUT, m_out);
	DDX_Text(pDX, IDC_POINT_NUMBER, m_no);
	DDV_MinMaxInt(pDX, m_no, 1, 1000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEdhjSet, CDialog)
	//{{AFX_MSG_MAP(CEdhjSet)
	ON_BN_CLICKED(IDC_FILEOPEN, OnFileopen)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEdhjSet message handlers


void CEdhjSet::OnBrowse() 
 {
// FILE *fp=NULL;
	// TODO: Add your control notification handler code here
//	if(fp!=NULL)fclose(fp);
	static char BASED_CODE szfilter[]="Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".liu","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILEOUT,filepath);
	bool fileopen=false;
//	fclose(fp);
	}
	
 }

void CEdhjSet::OnFileopen() 
{
	static char BASED_CODE szfilter[]="数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILEIN,filepath);

	bool fileopen=false;
	}

}


void CEdhjSet::OnOK() 
{	FILE *fp=NULL;
	CEdhjSet DlgSet;

	FILE *fptype=NULL;
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	};
	fprintf(fptype,"RDHJ");		//调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	};
	
	UpdateData(TRUE);

	CString ma,mai,mfilein,mfileout,mno;

	GetDlgItemText(IDC_A,ma);
	GetDlgItemText(IDC_AI,mai);
	GetDlgItemText(IDC_POINT_NUMBER,mno);
	GetDlgItemText(IDC_FILEIN,mfilein);
	GetDlgItemText(IDC_FILEOUT,mfileout);
	mopendata=m_opendata.GetCheck();

	UpdateData(FALSE);

	fprintf(fp,"%s\n%s\n%s\n%s\n%s",ma,mai,mno,mfilein,mfileout);

//	ShellExecute(NULL,"open","rdhj.exe",NULL,NULL,SW_HIDE);

	fclose(fp);

	//ShellExecute(NULL,"open","rdhj.exe",NULL,NULL,SW_HIDE);

//	CWnd wnd；
//	wnd.ModifyStyle(0,WS_BORDER,SWP_NOZORDER);

	CDialog::OnOK();
}

HBRUSH CEdhjSet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)//NULL
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	if (pWnd->GetDlgCtrlID() == IDC_CHECK_EDHJ)
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue;  //返回蓝色刷子
	return hbr;
	// TODO: Return a different brush if the default is not desired
}

BOOL CEdhjSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEdhjSet::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

BOOL CEdhjSet::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
