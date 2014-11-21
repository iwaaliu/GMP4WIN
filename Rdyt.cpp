// Rdyt.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "Rdyt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdyt dialog


CRdyt::CRdyt(CWnd* pParent /*=NULL*/)
	: CDialog(CRdyt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRdyt)
	m_infile = _T("mydatafile.dat");
	m_no = 27;
	m_outfile = _T("myoutputfile.dat");
	m_type = _T("上延");
	m_k = _T("一倍点距(1h)");
	//}}AFX_DATA_INIT
}


void CRdyt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRdyt)
	DDX_Control(pDX, IDC_RDYT, m_opendata);
	DDX_Text(pDX, IDC_RDYT_INFILE, m_infile);
	DDX_Text(pDX, IDC_RDYT_NO, m_no);
	DDX_Text(pDX, IDC_RDYT_OUTFILE, m_outfile);
	DDX_CBString(pDX, IDC_RHYT_TYPE, m_type);
	DDX_CBString(pDX, IDC_K, m_k);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRdyt, CDialog)
	//{{AFX_MSG_MAP(CRdyt)
	ON_BN_CLICKED(IDC_RDYT_IN, OnRdytIn)
	ON_BN_CLICKED(IDC_RDYT_OUT, OnRdytOut)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRdyt message handlers

void CRdyt::OnOK() 
{
	FILE *fp=NULL;
	FILE *fptype=NULL;
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	};
	fprintf(fptype,"RDYT");		//要调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	};
	//
	int mtype=1;	//GetDlgItemText(IDC_RDYT_TYPE,);
	int mk=2;
	UpdateData(TRUE);
	//判断各项输入是否合法
	if(m_type=="下延") mtype=2;
	if(m_type=="一倍点距(1h)") mk=1;
	if(m_infile=="") {AfxMessageBox("请选择源数据文件!!");return;}
	if(m_outfile=="") {AfxMessageBox("请输入数据输出文件名!!!");return;}
	//获取复选框的状态
	mopendata=m_opendata.GetCheck();
	//输出数据到文件
//	fprintf(fp,"%d\n%d\n%s\n%s\n%d",mtype,m_no,m_infile,m_outfile,5);//k has not defined
	fprintf(fp,"%d\n%d\n%s\n%s\n%d",mtype,m_no,m_infile,m_outfile,mk);//k has not defined
	//
	fclose(fp);
	CDialog::OnOK();
}

void CRdyt::OnRdytIn() 
{
	static char BASED_CODE szfilter[]="Data Files(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{
		CString filename=myfile.GetFileName();
		CString filepath=myfile.GetPathName();	
		
		SetDlgItemText(IDC_RDYT_INFILE,filepath);
		bool fileopen=false;
	}
}

void CRdyt::OnRdytOut() 
{
	static char BASED_CODE szfilter[]="Data Files(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{
		CString filename=myfile.GetFileName();
		CString filepath=myfile.GetPathName();	
		
		SetDlgItemText(IDC_RDYT_OUTFILE,filepath);
		bool fileopen=false;
	}
}

HBRUSH CRdyt::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == IDC_RDYT)
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

BOOL CRdyt::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
