#if !defined(AFX_FLASH_H__21D4DCA2_C8FB_47FB_9ECE_5C04878FBB3B__INCLUDED_)
#define AFX_FLASH_H__21D4DCA2_C8FB_47FB_9ECE_5C04878FBB3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Flash.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlash dialog

class CFlash : public CDialog
{
// Construction
public:
	CFlash(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CFlash)
	enum { IDD = IDD_Flash };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlash)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFlash)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASH_H__21D4DCA2_C8FB_47FB_9ECE_5C04878FBB3B__INCLUDED_)
