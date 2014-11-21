// AbnormalCacu.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "AbnormalCacu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAbnormalCacu dialog


CAbnormalCacu::CAbnormalCacu(CWnd* pParent /*=NULL*/)
	: CDialog(CAbnormalCacu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAbnormalCacu)
	dlg = NULL;
	m_inputdata = _T("");
	m_data = _T("");
	m_first = _T("");
	//}}AFX_DATA_INIT
}


void CAbnormalCacu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAbnormalCacu)
	DDX_Control(pDX, IDC_STATIC_1, m_static);
	DDX_Control(pDX, IDC_EDIT_FIRST, m_first_bt);
	DDX_Control(pDX, IDC_XYDATA, m_xydata);
	DDX_Control(pDX, IDC_RIVISE_OPEN, m_riviseopen);
	DDX_Control(pDX, IDC_FILE_RIVISE, m_rivisedata);
	DDX_Control(pDX, IDC_RIVISE, m_rivise);
	DDX_Control(pDX, IDC_ABNORMALCACU, m_opendata);
	DDX_Text(pDX, IDC_FILE_INPUT, m_inputdata);
	DDX_Text(pDX, IDC_FILE_RIVISE, m_data);
	DDX_Text(pDX, IDC_EDIT_FIRST, m_first);
	DDV_MaxChars(pDX, m_first, 1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAbnormalCacu, CDialog)
	//{{AFX_MSG_MAP(CAbnormalCacu)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RIVISE, OnRivise)
	ON_BN_CLICKED(IDC_RIVISE_OPEN, OnRiviseOpen)
	ON_BN_CLICKED(IDC_INPUT_OPEN, OnInputOpen)
	ON_BN_CLICKED(IDC_FILE_FORM, OnFileForm)
	ON_BN_CLICKED(IDC_FILE_EDIT, OnFileEdit)
	ON_BN_CLICKED(IDC_ABNORMALCACU, OnAbnormalcacu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAbnormalCacu message handlers

void CAbnormalCacu::OnOK() 
{FILE *fp=NULL,*fptype=NULL;
	if((fptype=fopen("C:\\mytemp\\type.liu","w+"))==NULL)
	{MessageBox("Can not open file C:\\mytemp\\type.liu!!");return;}
	fprintf(fptype,"BOUGUER");	//BOUGUER 异常计算
	fclose(fptype);
	// TODO: Add extra validation here
	UpdateData(TRUE);
	mopendata=m_opendata.GetCheck();

//	CString str,str1;
	//str=str.Format("%s",inpath);

	int lenstr=inpath.GetLength(),lenstr1=inname.GetLength();
	int len=lenstr-lenstr1;

//	MessageBox(outfile);
//	outfile.Format("%s",str);
	UpdateData(FALSE);
	char xydata='N';
	if((m_xydata.GetCheck())==1) xydata='Y';
	if((fp=fopen("C:\\mytemp\\input.liu","w+"))==NULL)
	{MessageBox("Can not open file C:\\mytemp\\input.liu!!");return;}
	
	if(m_inputdata=="")	{MessageBox("请输入参数据文件名!!");return;}
	
	if((m_rivise.GetCheck())==1)
	{	if(m_data=="")	{MessageBox("请输入地形校正值文件名!!");return;}

		fprintf(fp,"%s\n%c\n%s\n%c",m_inputdata,'Y',m_data,xydata);
	}
	else 
	{fprintf(fp,"%s\n%c\n%c",m_inputdata,'N',xydata);
	}
	fclose(fp);
	

	CDialog::OnOK();
}

HBRUSH CAbnormalCacu::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if (pWnd->GetDlgCtrlID() == IDC_ABNORMALCACU)
	{
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
	}
		if (pWnd->GetDlgCtrlID() == IDC_XYDATA)
	{
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
	}
		if (pWnd->GetDlgCtrlID() == IDC_RIVISE)
	{
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC )
	{	
		pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
		return m_brushBlue;
	}
if (pWnd->GetDlgCtrlID() == IDC_STATIC_1 )
	{	
		pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
		return m_brushBlue;
	}

	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue; 
	return hbr;
}

BOOL CAbnormalCacu::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAbnormalCacu::OnRivise() 
{
	UpdateData(TRUE); 
	if(m_rivise.GetCheck()==1){
		m_rivisedata.EnableWindow(TRUE);
//m_rivisedata.ShowWindow(SW_SHOW);
		m_riviseopen.EnableWindow(TRUE);}
	else {
//m_rivisedata.ShowWindow(SW_HIDE);
		m_rivisedata.EnableWindow(FALSE);
		m_riviseopen.EnableWindow(FALSE);}
	UpdateData(FALSE);
}

void CAbnormalCacu::OnRiviseOpen() 
{
	static char BASED_CODE szfilter[]="数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	 CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILE_RIVISE,filepath);

	bool fileopen=false;
	}	
}

void CAbnormalCacu::OnInputOpen() 
{	static char BASED_CODE szfilter[]="数据文件(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
		inpath=myfile.GetPathName();
		inname=myfile.GetFileName();
	 CString fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");goto label;}

	SetDlgItemText(IDC_FILE_INPUT,filepath);

	bool fileopen=false;
	}	
}

void CAbnormalCacu::OnFileForm() 
{CMainFrame frm;
	// TODO: Add your control notification handler code here
	CString str;str.Format("%s%s",frm.thispath,"\\abcacufm.liu");	
	ShellExecute(NULL,"open","notepad.exe",str,NULL,SW_SHOW);
}

void CAbnormalCacu::OnFileEdit() 
{
	CString str;
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_FILE_INPUT,str);
	if((str.GetLength())==0)
	{
		if((MessageBox("Create a new file?",NULL,MB_OKCANCEL))==IDOK)
			ShellExecute(NULL,"open","notepad.exe",NULL,NULL,SW_SHOW);
	}
	else{ShellExecute(NULL,"open","notepad.exe",str,NULL,SW_SHOW);}
}

void CAbnormalCacu::OnAbnormalcacu() 
{
	UpdateData(TRUE); 
	if(m_opendata.GetCheck()==1){
		m_first_bt.EnableWindow(TRUE);
		m_first_bt.ShowWindow(SW_SHOW);
	//	m_static.Visible(TRUE);
		m_static.ShowWindow(SW_SHOW);
		m_static.EnableWindow(TRUE);}
	else {
		m_first_bt.EnableWindow(FALSE);
		m_first_bt.ShowWindow(SW_HIDE);
		m_static.ShowWindow(SW_HIDE);
		m_static.EnableWindow(FALSE);}
	UpdateData(FALSE);	
}
