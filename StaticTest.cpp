// StaticTest.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "StaticTest.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticTest dialog


CStaticTest::CStaticTest(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaticTest)
	m_data = _T("");
	//}}AFX_DATA_INIT
}


void CStaticTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaticTest)
	DDX_Text(pDX, IDC_DATA_FILE, m_data);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStaticTest, CDialog)
	//{{AFX_MSG_MAP(CStaticTest)
	ON_BN_CLICKED(IDC_FILE_FORM, OnFileForm)
	ON_BN_CLICKED(IDC_FILE_OPEN, OnFileOpen)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticTest message handlers

void CStaticTest::OnFileForm() 
{
CMainFrame frm;
	// TODO: Add your control notification handler code here
	CString str;str.Format("%s%s",frm.thispath,"\\statform.liu");	
HINSTANCE hin=ShellExecute(NULL,"open","notepad.exe",str,NULL,SW_SHOW);
if((int)hin<32) {;}

}
void CStaticTest::OnFileOpen() 
{
	static char BASED_CODE szfilter[]="Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".liu","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_DATA_FILE,filepath);
	bool fileopen=false;
}
}
void CStaticTest::OnOK() 
{	FILE *fp=NULL;
	FILE *fptype=NULL;
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	}
	fprintf(fptype,"STATICTEST");		//调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	}
	
	UpdateData(TRUE);

	UpdateData(FALSE);

	fprintf(fp,"%s",m_data);

//	ShellExecute(NULL,"open","rdhj.exe",NULL,NULL,SW_HIDE);
	fclose(fp);
	CDialog::OnOK();
}

HBRUSH CStaticTest::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
/*	if (pWnd->GetDlgCtrlID() == IDC_OPENDATA)
   {
      pDC->SetBkMode(TRANSPARENT);
	  return m_brushBlue;
   }
*/	if(nCtlColor == CTLCOLOR_DLG)
	return m_brushBlue;	
	// TODO: Return a different brush if the default is not desired

  return hbr;
}

BOOL CStaticTest::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
