// SmoothSet.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "SmoothSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSmoothSet dialog


CSmoothSet::CSmoothSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSmoothSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSmoothSet)
	m_input = _T("");
	m_output = _T("");
	m_form = _T("10f8.3");
	m_line = 133;
	m_point = 209;
	m_type = _T("  9点圆滑");
	//}}AFX_DATA_INIT
}


void CSmoothSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSmoothSet)
	DDX_Control(pDX, IDC_DATA_CHECK, m_dataopen);
	DDX_Text(pDX, IDC_FILE_INPUT, m_input);
	DDX_Text(pDX, IDC_FILE_OUTPUT, m_output);
	DDX_CBString(pDX, IDC_FORM, m_form);
	DDX_Text(pDX, IDC_LINE_NO, m_line);
	DDX_Text(pDX, IDC_POINT_NO, m_point);
	DDX_CBString(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSmoothSet, CDialog)
	//{{AFX_MSG_MAP(CSmoothSet)
	ON_BN_CLICKED(IDC_INPUT_OPEN, OnInputOpen)
	ON_BN_CLICKED(IDC_OUTPUT_OPEN, OnOutputOpen)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmoothSet message handlers

void CSmoothSet::OnInputOpen() 
{
	static char BASED_CODE szfilter[]="网格化文件(*.grd)|*.grd|数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,". GRD","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILE_INPUT,filepath);

	bool fileopen=false;
	}	
}

void CSmoothSet::OnOutputOpen() 
{
	static char BASED_CODE szfilter[]="网格化文件(*.grd)|*.grd|数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".GRD","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILE_OUTPUT,filepath);

	bool fileopen=false;
	}	
}

void CSmoothSet::OnOK() 
{
	FILE *fp=NULL;

	FILE *fptype=NULL;
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	};
	fprintf(fptype,"SMOOTH");		//调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("文件打开失败!");
	return;
	};
	int mtype=9;
	UpdateData(TRUE);
	if(m_type=="25点圆滑"){ mtype=25;}
	else if(m_type=="49点圆滑") { mtype=49;}
	else mtype=9;
	if(m_dataopen.GetCheck()==1) mopendata=1;
	else mopendata=0;
	UpdateData(FALSE);

	fprintf(fp,"%d\n%s\n%s\n%s\n%d\n%d",mtype,m_input,m_output,m_form,m_line,m_point);

	fclose(fp);	
	CDialog::OnOK();
}

BOOL CSmoothSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CSmoothSet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)//NULL
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
		if (pWnd->GetDlgCtrlID() == IDC_DATA_CHECK)//NULL
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue;  //返回蓝色刷子		

	return hbr;
}
