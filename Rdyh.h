#if !defined(AFX_RDYH_H__83B8147C_98F3_4EAA_BC9E_E65699BB1C6E__INCLUDED_)
#define AFX_RDYH_H__83B8147C_98F3_4EAA_BC9E_E65699BB1C6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rdyh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRdyh dialog

class CRdyh : public CDialog
{
// Construction
public:
	CRdyh(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CRdyh)
	enum { IDD = IDD_RDYH_SET };
	CButton	m_opendata;
	CString	m_input;
	CString	m_output;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRdyh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRdyh)
	virtual void OnOK();
	afx_msg void OnInputOpen();
	afx_msg void OnOutputOpen();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDYH_H__83B8147C_98F3_4EAA_BC9E_E65699BB1C6E__INCLUDED_)
