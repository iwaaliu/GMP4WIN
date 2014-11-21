#if !defined(AFX_PRETRIM_H__0751DC45_16D4_4410_A701_76A76A1C5691__INCLUDED_)
#define AFX_PRETRIM_H__0751DC45_16D4_4410_A701_76A76A1C5691__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreTrim.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreTrim dialog

class CPreTrim : public CDialog
{
// Construction
public:
	CPreTrim(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CPreTrim)
	enum { IDD = IDD_PRETRIM };
	CButton	m_opendata;
	CString	m_datafile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreTrim)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreTrim)
	virtual void OnOK();
	afx_msg void OnPretrimOpen();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnFileForm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRETRIM_H__0751DC45_16D4_4410_A701_76A76A1C5691__INCLUDED_)
