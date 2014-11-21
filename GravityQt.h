#if !defined(AFX_GRAVITYQT_H__193FA80F_4B62_461A_9A65_1D80C3331DBE__INCLUDED_)
#define AFX_GRAVITYQT_H__193FA80F_4B62_461A_9A65_1D80C3331DBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GravityQt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGravityQt dialog

class CGravityQt : public CDialog
{
// Construction
public:
	CGravityQt(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
// Dialog Data
	//{{AFX_DATA(CGravityQt)
	enum { IDD = IDD_GRAVITY_QT };
	CButton	m_opendata;
	float	m_h;
	CString	m_output;
	float	m_l;
	int		m_ln;
	float	m_p;
	int		m_pn;
	float	m_rou;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGravityQt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGravityQt)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAVITYQT_H__193FA80F_4B62_461A_9A65_1D80C3331DBE__INCLUDED_)
