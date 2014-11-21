// SuffGrap.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "SuffGrap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuffGrap dialog


CSuffGrap::CSuffGrap(CWnd* pParent /*=NULL*/)
	: CDialog(CSuffGrap::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSuffGrap)
	m_path = _T("");
	m_type = _T("GRAPHER");
	//}}AFX_DATA_INIT
}


void CSuffGrap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSuffGrap)
	DDX_Text(pDX, IDC_MY_PATH, m_path);
	DDX_CBString(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSuffGrap, CDialog)
	//{{AFX_MSG_MAP(CSuffGrap)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuffGrap message handlers

void CSuffGrap::OnOpen() 
{
	static char BASED_CODE szfilter[]="可执行文件(*.exe)|*.exe|All Files(*.*)|*.*|";
	CFileDialog myfile(1,". exe","GRAP4WIN",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{CString filename=myfile.GetFileName();
	 CString filepath=myfile.GetPathName();	
	
//	CString	 fileext =myfile.GetFileExt();
//	m_path=myfile.GetPathName();
	UpdateData(TRUE);
	m_path=myfile.GetPathName();
	UpdateData(FALSE);

//	SetDlgItemText(IDC_MY_PATH,filepath);

	bool fileopen=false;
	}		
}

void CSuffGrap::OnOK() 
{
	UpdateData(TRUE);
/*	FILE *fp=NULL;
	if((fp=fopen("sugrpath.liu","a+"))==NULL)
	{	
		fp=fopen("sugrpath.liu","w+");
	}
	fprintf(fp,"%s%c%s\n",m_type,'@',m_path);
	fclose(fp);		
	UpdateData(FALSE);
*/	CDialog::OnOK();
}

HBRUSH CSuffGrap::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	
	if(nCtlColor == CTLCOLOR_DLG)
	return m_brushBlue;
	return hbr;
}

BOOL CSuffGrap::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
