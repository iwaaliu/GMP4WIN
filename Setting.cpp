// DlgSet.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetting dialog


CSetting::CSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetting)
	m_10 = 1;
	m_1 = 21;
	m_2 = 21;
	m_3 = 10.0f;
	m_4 = 20;
	m_5 = 500;
	m_9 = 1;
	m_8 = _T("output.txt");
	m_c1 = _T("0");
	m_7 = 3.1f;
	m_6 = 45.0f;
	//}}AFX_DATA_INIT
}

void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetting)
	DDX_Control(pDX, IDC_OPENDATA, m_opendata);
	DDX_Text(pDX, IDC_EDIT10, m_10);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDV_MinMaxInt(pDX, m_1, 1, 100);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	DDV_MinMaxInt(pDX, m_2, 1, 100);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	DDX_Text(pDX, IDC_EDIT4, m_4);
	DDX_Text(pDX, IDC_EDIT5, m_5);
	DDX_Text(pDX, IDC_EDIT9, m_9);
	DDX_Text(pDX, IDC_EDIT8, m_8);
	DDX_CBString(pDX, IDC_COMBO1, m_c1);
	DDV_MaxChars(pDX, m_c1, 1);
	DDX_Text(pDX, IDC_EDIT7, m_7);
	DDX_Text(pDX, IDC_EDIT6, m_6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetting, CDialog)
	//{{AFX_MSG_MAP(CSetting)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetting message handlers

void CSetting::OnOK() 
{	FILE *fp=NULL,*fptype=NULL;
	CSetting DlgSet;
	// TODO: Add extra validation here
	if((fptype=fopen("c:\\mytemp\\type.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\type.liu!");
	return;
	};
	fprintf(fptype,"QT");		//调用的DLL类型
	fclose(fptype);

	if((fp=fopen("c:\\mytemp\\input.liu","w+"))==NULL)
	{
	MessageBox("无法创建文件::  c:\\mytemp\\input.liu!");
	return;
	};
	
	CString m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,mc1;

UpdateData(TRUE);

	GetDlgItemText(IDC_EDIT1,m1);
	GetDlgItemText(IDC_EDIT2,m2);
	GetDlgItemText(IDC_EDIT3,m3);
	GetDlgItemText(IDC_EDIT4,m4);
	GetDlgItemText(IDC_EDIT5,m5);
	GetDlgItemText(IDC_EDIT6,m6);
	GetDlgItemText(IDC_EDIT7,m7);
	GetDlgItemText(IDC_EDIT8,m8);
	GetDlgItemText(IDC_EDIT9,m9);
	GetDlgItemText(IDC_EDIT10,m10);
	GetDlgItemText(IDC_COMBO1,mc1);
	
	mopendata=m_opendata.GetCheck();

UpdateData(FALSE);

	fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",m1,m2,m3,m4,m5,m6,m7,m10,m9,mc1,m8);//	fwrite("\n",1,1,fp);

//	ShellExecute(NULL,"open","qt.exe",NULL,NULL,SW_HIDE);

	fclose(fp);
	CDialog::OnOK();
}

HBRUSH CSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{	
//	CBrush Brush (RGB (255 , 0 , 255 ) );
//	CBrush* pOldBrush = pDC->SelectObject (&Brush);
//	CRect rcClip;
//	pDC ->GetClipBox (&rcClip);
//	pDC -> PatBlt (rcClip.left , rcClip.top , rcClip.Width ( ) , rcClip.Height( ) , PATCOPY );
//	pDC ->SelectObject (pOldBrush );
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if (pWnd->GetDlgCtrlID() == IDC_STATIC)
   {
      pDC->SetBkMode(TRANSPARENT);//让text的显示模式为透明
	  return m_brushBlue;
   }
	if (pWnd->GetDlgCtrlID() == IDC_OPENDATA)
   {
      pDC->SetBkMode(TRANSPARENT);
	  return m_brushBlue;
   }
	if(nCtlColor == CTLCOLOR_DLG)
	return m_brushBlue;
	return hbr;
}

BOOL CSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_brushBlue.CreateSolidBrush ( RGB (214, 255,255 ));//240, 200, 240  206, 200, 206

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CSetting::OnDestroy() 
{
	CDialog::OnDestroy();
	SetStatusText();
	// TODO: Add your message handler code here
	
}

BOOL CSetting::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(pWnd==this)
		SetStatusText();
	else
	{TOOLTIPTEXT m_psttt;
	m_psttt.hdr.hwndFrom =m_hWnd;
	m_psttt.hdr.idFrom = pWnd->GetDlgCtrlID();
m_psttt.hdr.code = TTN_NEEDTEXT;

m_psttt.uFlags = TTF_IDISHWND;
SetStatusText(pWnd->GetDlgCtrlID());
this->SendMessage(WM_NOTIFY,m_psttt.hdr.idFrom,(LPARAM)&m_psttt);
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CSetting::SetStatusText(UINT nID)
{
if(nID==0)
nID=AFX_IDS_IDLEMESSAGE;
CWnd *pWnd = AfxGetMainWnd()->GetDescendantWindow(AFX_IDW_STATUS_BAR);
if(pWnd)
{
	AfxGetMainWnd()->SendMessage(WM_SETMESSAGESTRING,nID);
	pWnd->SendMessage(WM_IDLEUPDATECMDUI);
	pWnd->UpdateWindow();
}
}
BOOL OnTipNotify(UINT id,NMHDR *pNMHDR,LRESULT *pResult)
{
	TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pNMHDR;
	UINT nID= pNMHDR->idFrom;
	if(pTTT->uFlags&TTF_IDISHWND)
	{nID=::GetDlgCtrlID((HWND)nID);
	if(nID)
		{TCHAR szFullText[256];
		CString StrTipText;
		AfxLoadString(nID,szFullText);
		AfxExtractSubString(StrTipText,szFullText,1,'\n');
		strcpy(pTTT->lpszText,StrTipText);
		pTTT->hinst = AfxGetResourceHandle();
	return (TRUE);
		}
	}
return (FALSE);

}
