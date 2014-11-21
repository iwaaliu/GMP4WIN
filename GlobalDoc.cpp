// GlobalDoc.cpp : implementation of the CGlobalDoc class
//

#include "stdafx.h"
#include "afxext.h"
#include "OutBarDemo.h"
#include "GlobalDoc.h"
#include "MainFrm.h"
#include "GfxOutBarCtrl.h"
#include "Splash.h"

//#include "IEBar.h"
//#include "UpEx.h"
//#include "EdhjSet.h"
#include "Setting.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlobalDoc

IMPLEMENT_DYNCREATE(CGlobalDoc, CDocument)

BEGIN_MESSAGE_MAP(CGlobalDoc, CDocument)
	//{{AFX_MSG_MAP(CGlobalDoc)
	ON_COMMAND(ID_SHOW_HIDE_IEBAR, OnShowHideIebar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlobalDoc construction/destruction

CGlobalDoc::CGlobalDoc()
	: m_pStartPoint(0)
	, m_pEndPoint(0)
	, m_nDrawType(3)
	, m_nIsMouseDrag(0)
{
	// TODO: add one-time construction code here
}

CGlobalDoc::~CGlobalDoc()
{
}

BOOL CGlobalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGlobalDoc serialization

void CGlobalDoc::Serialize(CArchive& ar)
{	CSetting DlgSet;
	m_str=DlgSet.m_c1;
	
	if (ar.IsStoring())
	{  ar<<m_str;
		

		// TODO: add storing code here
	}
	else
	{
		ar>>m_str;// TODO: add loading code here

	}

}

/////////////////////////////////////////////////////////////////////////////
// CGlobalDoc diagnostics

#ifdef _DEBUG
void CGlobalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGlobalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGlobalDoc commands

//DEL void CGlobalDoc::OnQt() 
//DEL {	CSetting DlgSet;
//DEL 
//DEL 	AfxGetMainWnd() -> SetWindowText (_T("球体正演计算") );
//DEL 	if(DlgSet.DoModal()==IDOK) {AfxMessageBox("OK!!");}
//DEL 	else {AfxMessageBox("您已经取消了操作!");}
//DEL }

//DEL void CGlobalDoc::OnEdhj() 
//DEL {
//DEL 	AfxGetMainWnd() -> SetWindowText (_T("二度化极") );
//DEL 	CEdhjSet DlgSet;
//DEL 	if(DlgSet.DoModal()==IDOK) {AfxMessageBox("OK!!");}
//DEL 	else {AfxMessageBox("您已经取消了操作!");}
//DEL }

//DEL void CGlobalDoc::OnDownExtend() 
//DEL {	// TODO: Add your command handler code here
//DEL 	AfxGetMainWnd() -> SetWindowText (_T("向下延拓") );
//DEL 
//DEL }

//DEL void CGlobalDoc::OnUpExtend() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	AfxGetMainWnd() -> SetWindowText (_T("向上延拓") );
//DEL }

//DEL void CGlobalDoc::OnMegUpex() 
//DEL {	AfxGetMainWnd() -> SetWindowText (_T("向上延拓") );
//DEL 	// TODO: Add your command handler code here
//DEL 	CUpEx DlgSet;
//DEL 	DlgSet.DoModal();
//DEL }

void CGlobalDoc::OnShowHideIebar() 
{  // CIEBar m_IEBar;
//	CFrameWnd db;
//	db.ShowControlBar(&m_IEBar,
//		((m_IEBar.GetStyle() & WS_VISIBLE) == 0),
//		FALSE);	
 	//AfxMessageBox("!@#$%^&^&&^");
}
