// CG: This file was added by the Splash Screen component.
// Splash.cpp : implementation file
//

#include "stdafx.h"  // e. g. stdafx.h
#include "resource.h"  // e.g. resource.h

#include "Splash.h"  // e.g. splash.h

#define	 TITLECOLOR    RGB(0,0,255)//Ĭ�ϱ�����ɫ
#define  CONTENTCOLOR  RGB(0,255,255)//Ĭ��˵��������ɫ
#define  FONTSIZE0  15 	//Ĭ���ֺ�


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
//   Splash Screen class

BOOL CSplashWnd::c_bShowSplashWnd;
CSplashWnd* CSplashWnd::c_pSplashWnd;
CSplashWnd::CSplashWnd()
{
	//	m_Bitmap.LoadBitmap(MAKEINTRESOURCE(IDB_SPLASH)); //Load Bitmap
	//	m_Bitmap.GetBitmap(&bmBitmap);         //Get Bitmap Info
	m_nCurPos = 50 ;
	
}

CSplashWnd::~CSplashWnd()
{
	// Clear the static window pointer.
	ASSERT(c_pSplashWnd == this);
	c_pSplashWnd = NULL;
}

BEGIN_MESSAGE_MAP(CSplashWnd, CWnd)
//{{AFX_MSG_MAP(CSplashWnd)
ON_WM_CREATE()
ON_WM_PAINT()
ON_WM_TIMER()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSplashWnd::EnableSplashScreen(BOOL bEnable /*= TRUE*/)
{
	c_bShowSplashWnd = bEnable;
}

void CSplashWnd::ShowSplashScreen(CWnd* pParentWnd /*= NULL*/)
{
	if (!c_bShowSplashWnd || c_pSplashWnd != NULL)
		return;
	
	// Allocate a new splash screen, and create the window.
	c_pSplashWnd = new CSplashWnd;
	if (!c_pSplashWnd->Create(pParentWnd))
		delete c_pSplashWnd;
	else
		c_pSplashWnd->UpdateWindow();
}

BOOL CSplashWnd::PreTranslateAppMessage(MSG* pMsg)
{
	if (c_pSplashWnd == NULL)
		return FALSE;
	
	// If we get a keyboard or mouse message, hide the splash screen.
	if (pMsg->message == WM_KEYDOWN ||
		pMsg->message == WM_SYSKEYDOWN ||
		pMsg->message == WM_LBUTTONDOWN ||
		pMsg->message == WM_RBUTTONDOWN ||
		pMsg->message == WM_MBUTTONDOWN ||
		pMsg->message == WM_NCLBUTTONDOWN ||
		pMsg->message == WM_NCRBUTTONDOWN ||
		pMsg->message == WM_NCMBUTTONDOWN)
	{
		c_pSplashWnd->HideSplashScreen();	//�˴������Ƿ񰴼���ʧ
		return TRUE;	// message handled here
	}
	
	return FALSE;	// message not handled
}

BOOL CSplashWnd::Create(CWnd* pParentWnd /*= NULL*/)
{
	if (!m_bitmap.LoadBitmap(IDB_SPLASH))
		return FALSE;
	
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	m_TextRect.CopyRect(&CRect(0,0,500,400));
	
	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
		NULL, WS_POPUP | WS_VISIBLE, 0, 0, bm.bmWidth, bm.bmHeight, pParentWnd->GetSafeHwnd(), NULL);
	
	
}

void CSplashWnd::HideSplashScreen()
{
	// Destroy the window, and update the mainframe.
	DestroyWindow();
	AfxGetMainWnd()->UpdateWindow();
}

void CSplashWnd::PostNcDestroy()
{
	// Free the C++ class.
	// Free the C++ class.
	m_dcImage.SelectObject(m_pOldBitmap);
	m_dcText.SelectClipRgn(NULL);
	m_dcText.SelectObject(m_pOldBitmapText);
	m_bitmap.DeleteObject();
	m_rgn.DeleteObject();
	
	delete this;
}

int CSplashWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{	if (CWnd::OnCreate(lpCreateStruct) == -1)
return -1;
// Center the window.
CenterWindow();
// Set a timer to destroy the splash screen.
SetTimer(1, 17500, NULL);
return 0;
}

void CSplashWnd::OnPaint()
{
	CPaintDC dc(this);
	
	CDC dcImage;
	if (!dcImage.CreateCompatibleDC(&dc))
		return;
	
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	static BOOL bFirst = TRUE;//ָʾ�Ƿ��һ�λ��ƴ���
	
	if(bFirst)
	{
		if (!m_dcImage.CreateCompatibleDC(&dc)) 	return;
		m_pOldBitmap = m_dcImage.SelectObject(&m_bitmap);		
		if (!m_dcText.CreateCompatibleDC(&dc))		return;
		m_pBitmap = new CBitmap ;
		int nBitCount = m_dcText.GetDeviceCaps(BITSPIXEL);
		m_pBitmap->CreateBitmap
			(bm.bmWidth,bm.bmHeight,1,nBitCount,NULL);
		m_pOldBitmapText = m_dcText.SelectObject(m_pBitmap);
		m_rgn.CreateRectRgn(m_TextRect.left,m_TextRect.top,
			m_TextRect.right,m_TextRect.bottom);
		bFirst = FALSE;
	}
	m_dcText.SelectClipRgn(NULL);
	m_dcText.BitBlt(0, 0, bm.bmWidth, 
		bm.bmHeight,&m_dcImage, 0, 0, SRCCOPY);
	m_dcText.SelectClipRgn(&m_rgn);
	int nBasex = m_TextRect.left ; 
	int nBasey = m_TextRect.bottom-m_nCurPos; 
	int nMidx = m_TextRect.left + m_TextRect.Width()/2 ;
	
	FILE *fp;
	char user[40]="����ƻ�˪�";
	char conpny[40]="�й����ʴ�ѧ��������ϵ62001��";
	char id[20]="ͬѧ";
	char version[20]="1.0.0.1";
	
	if((fp=fopen("info.liu","r"))!=NULL)
	{
		fscanf(fp,"%s",&user);
		fscanf(fp,"%s",&id);
		fscanf(fp,"%s",&conpny);
		fscanf(fp,"%s",&version);
	}
	else
	{
		MessageBox("��ʼ���ļ���ʧ��!!!");
		//	 Afx	DrawText(&m_dcText,nMidx-230,nBasey-200, 0,"����", 15,RGB (214, 215,0 ),"��ʼ���ļ���ʧ��!!!");
		
		char buf[50];
		//	char buf[MAX_COMPUTERNAME_LENGTH + 1];
		unsigned long uSize=MAX_COMPUTERNAME_LENGTH ;
		
		if(GetComputerName(buf,&uSize)){buf[uSize]=0;strcpy(user,buf);}// GetComputerName
		else AfxMessageBox("Get Computer Name Failed!");
	
		if(GetUserName(buf,&uSize)){buf[uSize]=0;strcpy(conpny,buf);}// GetUserName
		else AfxMessageBox("Get User Name Failed!");
		
		
	}
/*	int i=0,j=0,ii;
	for(i=0;i<400;i++){	for(j=0;j<256;j++){
		ii=i%400;
	DrawText(&m_dcText,i,-30+j , 0,"", 20,RGB(ii,j,250),".");
	}
	}*/
	int pox=48,poy=160; //pox=210,poy=0
	int color=255;

//	DrawText(&m_dcText,0,poy-160, 0,"����_GB2312", 60,200,"�˪̪̪�");
//�˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪̪˪�
	DrawText(&m_dcText,10,poy-100, 0,"����_GB2312", 20,color,"���������ش�����");
	DrawText(&m_dcText,10,poy-80 , 0,"����_GB2312", 20,color," �����봦��ϵͳ");


	//color=0;
	DrawText(&m_dcText,pox,poy-15, 0,"����", 11,1,"��Ȩ��:");
	
	CString str;//
	str=user;
	str.Format("%s%s", str+" ",id);
	DrawText(&m_dcText,pox,poy, 0,"����", 11,1,str);
	str=conpny;
	str.Format("%s", str);
	DrawText(&m_dcText,pox,poy+15, 0,"����", 11,1,str);
	str=version;
	str.Format("%s","��ǰ�汾:"+str);
	DrawText(&m_dcText,pox,poy+30, 0,"����", 11,1,str);
	DrawText(&m_dcText,330,280, 1,"", 12,255,"��Ȩ���С�CUG");
	DrawText(&m_dcText,354,281, 1,"", 9,255,"C");

	/*
	DrawText(&m_dcText,nMidx,nBasey, 1,"����", FONTSIZE0+1,TITLECOLOR,"���Ƶ�λ");
	*/
	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight,&m_dcText, 0,0, SRCCOPY);
	
	// Paint the image.
//	CBitmap* pOldBitmap = dcImage.SelectObject(&m_bitmap);
//	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &dcImage, 0, 0, SRCCOPY);
//	dcImage.SelectObject(pOldBitmap);
}

void CSplashWnd::OnTimer(UINT nIDEvent)
{
	// Destroy the splash screen window.
	m_nCurPos++;
	if( m_nCurPos>15 )
	{	
		m_nCurPos = 0 ;
	}
	Invalidate(TRUE);
	
	HideSplashScreen();
}


void CSplashWnd::DrawText(CDC *pDC, int x, int y, int nAlign, CString sFontName, int nFONTSIZE0, COLORREF crTextColor, CString sText)
{
	LOGFONT lf;//����
	lf.lfStrikeOut=0;//ɾ����
	lf.lfCharSet = DEFAULT_CHARSET ;//�ַ���
	lf.lfEscapement =0;//�Ƕ�
	lf.lfItalic = 0 ;//��б
	lf.lfUnderline = 0 ;//�»���
	lf.lfHeight = nFONTSIZE0 ;//�ֺ�
	lf.lfWidth = nFONTSIZE0-3 ;
	
	strcpy(lf.lfFaceName,sFontName.GetBuffer(sFontName.GetLength()));
	CFont font ;
	font.CreateFontIndirect(&lf);
	CFont *pOldFont = (CFont *)
		pDC->SelectObject(&font);
	UINT oldAlign,uAlign ;
	switch(nAlign)
	{
	case 0: uAlign = TA_LEFT | TA_TOP ; break;
	case 1: uAlign = TA_CENTER | TA_TOP; break;
	case 2: uAlign = TA_RIGHT  | TA_TOP ; break; 
	default: uAlign = TA_LEFT | TA_TOP ; break;
	}
	oldAlign = pDC->SetTextAlign(uAlign);
	int  oldMode =  pDC->SetBkMode(TRANSPARENT);
	int  oldColor = pDC->SetTextColor(crTextColor) ;
	pDC->TextOut(x,y,sText);
	
	pDC->SetTextColor(oldColor) ;
	pDC->SetTextAlign(oldAlign);
	pDC->SetBkMode(oldMode);
	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}
