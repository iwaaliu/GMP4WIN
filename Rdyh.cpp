// Rdyh.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "Rdyh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdyh dialog


CRdyh::CRdyh(CWnd* pParent /*=NULL*/)
	: CDialog(CRdyh::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRdyh)
	m_input = _T("");
	m_output = _T("");
	m_type = _T("���Բ��");
	//}}AFX_DATA_INIT
}


void CRdyh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRdyh)
	DDX_Control(pDX, IDC_CHECK_DATA, m_opendata);
	DDX_Text(pDX, IDC_FILE_INPUT, m_input);
	DDX_Text(pDX, IDC_FILE_OUTPUT, m_output);
	DDX_CBString(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRdyh, CDialog)
	//{{AFX_MSG_MAP(CRdyh)
	ON_BN_CLICKED(IDC_INPUT_OPEN, OnInputOpen)
	ON_BN_CLICKED(IDC_OUTPUT_OPEN, OnOutputOpen)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRdyh message handlers

void CRdyh::OnOK() 
{
	FILE *fp=NULL,*fptype=NULL;
	if((fptype=fopen("C:\\mytemp\\type.liu","w+"))==NULL)
	{MessageBox("Can not open file C:\\mytemp\\type.liu!!");return;}
	fprintf(fptype,"RDYH");
	fclose(fptype);

	UpdateData(TRUE);
	mopendata=m_opendata.GetCheck();

	if(m_input=="") {AfxMessageBox("��ѡ��Դ�����ļ�!!");return;}
		if((fptype=fopen(m_input,"r"))==NULL)
		{AfxMessageBox("��ѡ����ȷ��Դ�����ļ�!!");return;}
		else {fclose(fptype);}
	if(m_output=="") {AfxMessageBox("��ѡ��Դ�����ļ�!!");return;}
	
	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("�ļ���ʧ��!");
	return;
	};

	int mtype=5;if(m_type=="�ߵ�Բ��") mtype=7;

	fprintf(fp,"%s\n%s\n%d",m_input,m_output,mtype);//k has not defined
	fclose(fp);
	//UpdateData(FALSE);
	CDialog::OnOK();
}

void CRdyh::OnInputOpen() 
{
	static char BASED_CODE szfilter[]="�����ļ�(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	 CString fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("�ļ����ʹ���!");goto label;}

	SetDlgItemText(IDC_FILE_INPUT,filepath);

	bool fileopen=false;
	}		
}

void CRdyh::OnOutputOpen() 
{
	static char BASED_CODE szfilter[]="�����ļ�(*.dat)|*.dat|Text Files(*.txt)|*.txt|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
label:	CFileDialog myfile(1,".dat","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	 CString fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("�ļ����ʹ���!");goto label;}

	SetDlgItemText(IDC_FILE_OUTPUT,filepath);

	bool fileopen=false;
	}	}

HBRUSH CRdyh::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

		if (pWnd->GetDlgCtrlID() == IDC_CHECK_DATA)
	{
      pDC->SetBkMode(TRANSPARENT);//��text����ʾģʽΪ͸��
	  return m_brushBlue;
	}	// TODO: Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_STATIC )
	{	
		pDC->SetBkMode(TRANSPARENT);//��text����ʾģʽΪ͸��
		return m_brushBlue;
	}

	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue; 
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CRdyh::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));		
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
