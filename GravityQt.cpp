// GravityQt.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "GravityQt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGravityQt dialog


CGravityQt::CGravityQt(CWnd* pParent /*=NULL*/)
	: CDialog(CGravityQt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGravityQt)
	m_h = 10.0f;
	m_output = _T("c:\\my temp\\output.liu");
	m_l = 1.0f;
	m_ln = 51;
	m_p = 1.0f;
	m_pn = 51;
	m_rou = 2.40f;
	//}}AFX_DATA_INIT
}


void CGravityQt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGravityQt)
	DDX_Control(pDX, IDC_DATA_OPEN, m_opendata);
	DDX_Text(pDX, IDC_CENTER_DEEP, m_h);
	DDX_Text(pDX, IDC_FILE_OUT, m_output);
	DDX_Text(pDX, IDC_LINE_DIS, m_l);
	DDX_Text(pDX, IDC_LINE_NO, m_ln);
	DDX_Text(pDX, IDC_POINT_DIS, m_p);
	DDX_Text(pDX, IDC_POINT_NO, m_pn);
	DDX_Text(pDX, IDC_REST_ROU, m_rou);
	DDV_MinMaxFloat(pDX, m_rou, 0.f, 2.e+007f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGravityQt, CDialog)
	//{{AFX_MSG_MAP(CGravityQt)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGravityQt message handlers

HBRUSH CGravityQt::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CGravityQt::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGravityQt::OnOK() 
{
	// TODO: Add extra validation here
UpdateData(TRUE);
mopendata=m_opendata.GetCheck();
UpdateData(FALSE);

	CDialog::OnOK();
}
