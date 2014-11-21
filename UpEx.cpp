// UpEx.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "UpEx.h"

#include "afxdlgs.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpEx dialog


CUpEx::CUpEx(CWnd* pParent /*=NULL*/)
	: CDialog(CUpEx::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUpEx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpEx)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpEx, CDialog)
	//{{AFX_MSG_MAP(CUpEx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpEx message handlers

void CUpEx::OnOK() 
{
	// TODO: Add extra validation here
	CFileDialog fileDlg(TRUE);
	if(fileDlg.DoModal()==IDOK)
	{
		CString strFileName = fileDlg.GetFileName();
		CString strPathName = fileDlg.GetPathName();
	}
	CDialog::OnOK();
}
