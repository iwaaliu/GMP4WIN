#if !defined(AFX_SUFFGRAP_H__0E4BD024_B893_4DEC_886D_759A8A652362__INCLUDED_)
#define AFX_SUFFGRAP_H__0E4BD024_B893_4DEC_886D_759A8A652362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SuffGrap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSuffGrap dialog

class CSuffGrap : public CDialog
{
// Construction
public:
	CSuffGrap(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CSuffGrap)
	enum { IDD = IDD_SUFF_GRAP };
	CString	m_path;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuffGrap)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSuffGrap)
	afx_msg void OnOpen();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUFFGRAP_H__0E4BD024_B893_4DEC_886D_759A8A652362__INCLUDED_)
