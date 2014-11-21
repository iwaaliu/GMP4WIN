#if !defined(AFX_RDYT_H__C6DD4AE0_DF34_4F26_8E78_5BCCFD87D6D8__INCLUDED_)
#define AFX_RDYT_H__C6DD4AE0_DF34_4F26_8E78_5BCCFD87D6D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rdyt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRdyt dialog

class CRdyt : public CDialog
{
// Construction
public:
	CRdyt(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CRdyt)
	enum { IDD = IDD_RDYT_SET };
	CButton	m_opendata;
	CString	m_infile;
	int		m_no;
	CString	m_outfile;
	CString	m_type;
	CString	m_k;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRdyt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRdyt)
	virtual void OnOK();
	afx_msg void OnRdytIn();
	afx_msg void OnRdytOut();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDYT_H__C6DD4AE0_DF34_4F26_8E78_5BCCFD87D6D8__INCLUDED_)
