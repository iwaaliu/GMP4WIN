#if !defined(AFX_SMOOTHSET_H__8EEF6D97_F21C_456B_BF83_FA159A7CFC69__INCLUDED_)
#define AFX_SMOOTHSET_H__8EEF6D97_F21C_456B_BF83_FA159A7CFC69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SmoothSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSmoothSet dialog

class CSmoothSet : public CDialog
{
// Construction
public:
	CSmoothSet(CWnd* pParent = NULL);   // standard constructor
	CBrush m_brushBlue;
	int mopendata;
// Dialog Data
	//{{AFX_DATA(CSmoothSet)
	enum { IDD = IDD_SMOOTH_SET };
	CButton	m_dataopen;
	CString	m_input;
	CString	m_output;
	CString	m_form;
	int		m_line;
	int		m_point;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmoothSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSmoothSet)
	afx_msg void OnInputOpen();
	afx_msg void OnOutputOpen();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMOOTHSET_H__8EEF6D97_F21C_456B_BF83_FA159A7CFC69__INCLUDED_)
