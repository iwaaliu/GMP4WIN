// Notice.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "Notice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotice dialog


CNotice::CNotice(CWnd* pParent /*=NULL*/)
	: CDialog(CNotice::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotice)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNotice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotice)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNotice, CDialog)
	//{{AFX_MSG_MAP(CNotice)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_WM_DESTROY()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotice message handlers

HBRUSH CNotice::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CNotice::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CNotice::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CNotice::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}


void CNotice::OnLButtonUp(UINT nFlags, CPoint point) 
{

	//CString str;
	//str.Format("%s%d%d",str,point.x,point.y);
	// 获得鼠标位置
	if (point.x>250 && point.y>408)//pWnd->GetDlgCtrlID() == IDC_STATIC
	{if (point.x<280 && point.y<422)
	{//	AfxMessageBox(str);
	CDialog::OnOK();
	}
	}

	CDialog::OnLButtonUp(nFlags, point);
}
