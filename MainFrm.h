// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__28FA2C98_11B7_11D2_8437_0000B43382FE__INCLUDED_)
#define AFX_MAINFRM_H__28FA2C98_11B7_11D2_8437_0000B43382FE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "GfxSplitterWnd.h"
#include "GfxOutBarCtrl.h"
#include "MyTreeCtrl.h"
#include "fstream.h"
//#include "IEBar.h"	// Added by ClassView

class CMainFrame : public CFrameWnd
{
public://protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CGfxSplitterWnd	wndSplitter;
	CGfxOutBarCtrl	wndBar;
	CImageList		imaLarge, imaSmall;

	//CTreeCtrl		wndTree,wndTree1,wndTree2;//,wndTree3,wndTree4;
	MyTreeCtrl		wndTree,wndTree1,wndTree2;//My_wndTree,My_wndTree1,My_wndTree2;//,wndTree3,wndTree4;
	//CTreeCtrl		m_wndTree,m_wndTree1,m_wndTree2;//,m_wndTree3,m_wndTree4;
    MyTreeCtrl		m_wndTree,m_wndTree1,m_wndTree2;//My_m_wndTree,My_m_wndTree1,My_m_wndTree2;
	HTREEITEM		m_htm;
	ifstream			in;
	char thispath[200];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
//	CIEBar m_IEBar;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;


// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnGfxLargeicon();
	afx_msg void OnUpdateGfxLargeicon(CCmdUI* pCmdUI);
	afx_msg void OnGfxSmallicon();
	afx_msg void OnUpdateGfxSmallicon(CCmdUI* pCmdUI);
	afx_msg void OnTitle();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnAbnormalCacu();
	afx_msg void OnCoherenceMag();
	afx_msg void OnCoherenceTest();
	afx_msg void OnDiqian();
	afx_msg void OnDownExtend2();
	afx_msg void OnDownExtend3();
	afx_msg void OnDynamicMulti();
	afx_msg void OnDynamicTwo();
	afx_msg void OnDynamicTwomag();
	afx_msg void OnPreTrim();
	afx_msg void OnReviewMag();
	afx_msg void OnStaticTest();
	afx_msg void OnSufferDraw();
	afx_msg void OnUpExtend2();
	afx_msg void OnUpExtend3();
	afx_msg void OnEdhj();
	afx_msg void OnQt();
	afx_msg void OnClose();
	afx_msg void OnGrapherDraw();
	afx_msg void OnDynamicMulmag();
	afx_msg void OnGravityQt();
	afx_msg void OnMagDownex2();
	afx_msg void OnMagDownex3();
	afx_msg void OnMagUpex2();
	afx_msg void OnMagUpex3();
	afx_msg void OnMagVxz2();
	afx_msg void OnMagVxz3();
	afx_msg void OnMagVzz2();
	afx_msg void OnMagVzz3();
	afx_msg void OnMagVzzz2();
	afx_msg void OnMagVzzz3();
	afx_msg void OnStaticTestmag();
	afx_msg void OnValueRivise();
	afx_msg void OnValuetestMag();
	afx_msg void OnVxz2();
	afx_msg void OnVxz3();
	afx_msg void OnVzz2();
	afx_msg void OnVzz3();
	afx_msg void OnVzzz2();
	afx_msg void OnVzzz3();
	afx_msg void OnUpdateTime(CCmdUI *pCmdUI);
	afx_msg void OnDataReview();
	afx_msg void OnNotice();
	afx_msg void OnThreeOp();
	//}}AFX_MSG
	afx_msg long OnOutbarNotify(WPARAM wParam, LPARAM lParam);
public:
	void CallFunction();
	static void CALLBACK TimerProc(HWND hwnd,UINT uMsg,UINT  uIDEvent,DWORD dwTime);
	int m_nIDTimer;
	void DoEdhj();
	void DoSetting();
	void DoSuffer();
	void DoGrapher();
	void DoAbnormalCacu();
	void DoCoherenceTest();
	void DoCoherenceMag();
	void DoDownExtend2();
	void DoDownExtend3();
	void DoDynamicMulti();
	void DoDynamicTwo();
	void DoDynamicTwomag();
	void DoPreTrim();
	void DoReviewMag();
	void DoStaticTest();
	void DoSufferDraw();
	void DoUpExtend2();
	void DoUpExtend3();
	void DoClose();
	void DoGrapherDraw();
	void DoDynamicMulmag();
	void DoGravityQt();
	void DoMagDownex2();
	void DoMagDownex3();
	void DoMagUpex2();
	void DoMagUpex3();
	void DoMagVxz2();
	void DoMagVxz3();
	void DoMagVzz2();
	void DoMagVzz3();
	void DoMagVzzz2();
	void DoMagVzzz3();
	void DoStaticTestmag();
	void DoValueRivise();
	void DoValuetestMag();
	void DoVxz2();
	void DoVxz3();
	void DoVzz2();
	void DoVzz3();
	void DoVzzz2();
	void DoVzzz3();
	void DoDiqian();
	void DoDataReview();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__28FA2C98_11B7_11D2_8437_0000B43382FE__INCLUDED_)
