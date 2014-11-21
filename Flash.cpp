// Flash.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "Flash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlash dialog


CFlash::CFlash(CWnd* pParent /*=NULL*/)
	: CDialog(CFlash::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlash)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


 void CFlash::DoDataExchange(CDataExchange* pDX)
 {
 	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlash)
 		// NOTE: the ClassWizard will add DDX and DDV calls here
 	//}}AFX_DATA_MAP
 }


BEGIN_MESSAGE_MAP(CFlash, CDialog)
	//{{AFX_MSG_MAP(CFlash)
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlash message handlers

 BOOL CFlash::PreTranslateMessage(MSG* pMsg) 
 {
 	// TODO: Add your specialized code here and/or call the base class
 	Sleep(1500);
 	CDialog::OnCancel();
 	return CDialog::PreTranslateMessage(pMsg);
 }

void CFlash::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnCancel();
	CDialog::OnLButtonUp(nFlags, point);
}

HBRUSH CFlash::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() != IDC_STATIC)
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	if(nCtlColor ==CTLCOLOR_DLG)
	return m_brushBlue;  //返回蓝色刷子

	return hbr;
}

BOOL CFlash::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_brushBlue.CreateSolidBrush( RGB (0 ,205, 255));	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
