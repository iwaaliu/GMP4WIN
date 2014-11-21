#if !defined(AFX_STATICTEST_H__CAD940D5_81C5_4ED5_9BC2_6FEEF935A696__INCLUDED_)
#define AFX_STATICTEST_H__CAD940D5_81C5_4ED5_9BC2_6FEEF935A696__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StaticTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaticTest dialog

class CStaticTest : public CDialog
{
// Construction
public:
	CStaticTest(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CStaticTest)
	enum { IDD = IDD_STATIC_TEST };
	CString	m_data;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStaticTest)
	afx_msg void OnFileForm();
	afx_msg void OnFileOpen();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICTEST_H__CAD940D5_81C5_4ED5_9BC2_6FEEF935A696__INCLUDED_)
