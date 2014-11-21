#if !defined(AFX_THROP_H__56DACBFD_1A0D_4FBB_BAF7_17B3E873FD48__INCLUDED_)
#define AFX_THROP_H__56DACBFD_1A0D_4FBB_BAF7_17B3E873FD48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThrOp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThrOp dialog

class CThrOp : public CDialog
{
// Construction
public:
	CThrOp(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;
// Dialog Data
	//{{AFX_DATA(CThrOp)
	enum { IDD = IDD_MAG_THROP };
	CString	m_data;
	CString	m_iszero;
	CString	m_para;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThrOp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThrOp)
	virtual void OnOK();
	afx_msg void OnParaOpen();
	afx_msg void OnDataOprn();
	afx_msg void OnParaForm();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THROP_H__56DACBFD_1A0D_4FBB_BAF7_17B3E873FD48__INCLUDED_)
