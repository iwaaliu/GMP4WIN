// ThrOp.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "ThrOp.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThrOp dialog


CThrOp::CThrOp(CWnd* pParent /*=NULL*/)
	: CDialog(CThrOp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThrOp)
	m_data = _T("");
	m_iszero = _T("Y");
	m_para = _T("");
	//}}AFX_DATA_INIT
}


void CThrOp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThrOp)
	DDX_Text(pDX, IDC_DATA_FILE, m_data);
	DDX_CBString(pDX, IDC_IS_ZERO, m_iszero);
	DDX_Text(pDX, IDC_PARA_FILE, m_para);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThrOp, CDialog)
	//{{AFX_MSG_MAP(CThrOp)
	ON_BN_CLICKED(IDC_PARA_OPEN, OnParaOpen)
	ON_BN_CLICKED(IDC_DATA_OPRN, OnDataOprn)
	ON_BN_CLICKED(IDC_PARA_FORM, OnParaForm)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThrOp message handlers

void CThrOp::OnOK() 
{
	FILE *fp=NULL;

	FILE *fptype=NULL;
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	};
	fprintf(fptype,"GM0");		//调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	};
	
	UpdateData(TRUE);

	UpdateData(FALSE);

	fprintf(fp,"%s\n%s\n%s",m_para,m_data,m_iszero);

//	ShellExecute(NULL,"open","rdhj.exe",NULL,NULL,SW_HIDE);

	fclose(fp);
	CDialog::OnOK();
}

void CThrOp::OnParaOpen() 
{
	static char BASED_CODE szfilter[]="数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_PARA_FILE,filepath);

	bool fileopen=false;
	}
}

void CThrOp::OnDataOprn() 
{
	static char BASED_CODE szfilter[]="GRD Files(*.GRD)|*.GRD|数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".GRD","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_DATA_FILE,filepath);

	bool fileopen=false;
	}}

void CThrOp::OnParaForm() 
{
//		char aa[100]="c:\\mytemp\\input.liu";
	CMainFrame frm;
CString str;str.Format("%s%s",frm.thispath,"\\thropfrm.liu");
		HINSTANCE hin;
		hin=ShellExecute(NULL,"open",str,NULL,NULL,SW_SHOW);
		
		if((int)hin<=32) 
		{
			MessageBox("Cannot open "+str);
		}
	
}

HBRUSH CThrOp::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)//NULL
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue;  //返回蓝色刷子	
	return hbr;
}

BOOL CThrOp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
