// PreTrim.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "PreTrim.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreTrim dialog


CPreTrim::CPreTrim(CWnd* pParent /*=NULL*/)
	: CDialog(CPreTrim::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreTrim)
	m_datafile = _T("");
	//}}AFX_DATA_INIT
}


void CPreTrim::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreTrim)
	DDX_Control(pDX, IDC_PRETRIM, m_opendata);
	DDX_Text(pDX, IDC_PRETRIM_INFILE, m_datafile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreTrim, CDialog)
	//{{AFX_MSG_MAP(CPreTrim)
	ON_BN_CLICKED(IDC_PRETRIM_OPEN, OnPretrimOpen)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_FILE_FORM, OnFileForm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreTrim message handlers

void CPreTrim::OnOK() 
{
	FILE *fp=NULL,*fptype=NULL;
	if((fptype=fopen("C:\\mytemp\\type.liu","w+"))==NULL)
	{MessageBox("Can not open file C:\\mytemp\\type.liu!!");return;}
	fprintf(fptype,"PRETRIM");
	fclose(fptype);
	// TODO: Add extra validation here
	UpdateData(TRUE);
	mopendata=m_opendata.GetCheck();

//	int mtype=2;
//	if(m_type=="D-159") mtype=1;

	if(m_datafile=="") {AfxMessageBox("请选择源数据文件!!");return;}
		if((fptype=fopen(m_datafile,"r"))==NULL)
		{AfxMessageBox("请选择正确的源数据文件!!");return;}
		else {fclose(fptype);}
//	if(m_outfile=="") {AfxMessageBox("请输入数据输出文件名!!!");return;}
	
	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	};
	//参数还未定//////////////////////////////
	fprintf(fp,"%s",m_datafile);//k has not defined
	fclose(fp);
	//UpdateData(FALSE);

	CDialog::OnOK();
}

void CPreTrim::OnPretrimOpen() 
{
	static char BASED_CODE szfilter[]="Data Files(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	

	SetDlgItemText(IDC_PRETRIM_INFILE,filepath);
	bool fileopen=false;
	}
}

//DEL void CPreTrim::OnPretrimOpen2() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	static char BASED_CODE szfilter[]="Data Files(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
//DEL 	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
//DEL 	if(myfile.DoModal()==IDOK)
//DEL 	{CString filename=myfile.GetFileName();
//DEL 	 CString filepath=myfile.GetPathName();	
//DEL 
//DEL 	SetDlgItemText(IDC_PRETRIM_OUTFILE,filepath);
//DEL 	bool fileopen=false;
//DEL 	}
//DEL }

HBRUSH CPreTrim::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == IDC_PRETRIM)
	{
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
	}
	// TODO: Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_STATIC )
	{	
		pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
		return m_brushBlue;
	}

	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue; 
	return hbr;
}

BOOL CPreTrim::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreTrim::OnFileForm() 
{CMainFrame frm;
	// TODO: Add your control notification handler code here
	CString str;str.Format("%s%s",frm.thispath,"\\origform.liu");	
	ShellExecute(NULL,"open","notepad.exe",str,NULL,SW_SHOW);
}
