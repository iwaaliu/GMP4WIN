#if !defined(AFX_NOTICE_H__D019C6CE_E572_42CE_8465_5DED876E1A32__INCLUDED_)
#define AFX_NOTICE_H__D019C6CE_E572_42CE_8465_5DED876E1A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Notice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotice dialog

class CNotice : public CDialog
{
// Construction
public:
	CNotice(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;

// Dialog Data
	//{{AFX_DATA(CNotice)
	enum { IDD = IDD_NOTICE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNotice)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTICE_H__D019C6CE_E572_42CE_8465_5DED876E1A32__INCLUDED_)
