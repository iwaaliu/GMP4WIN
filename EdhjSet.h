#if !defined(AFX_EDHJSET_H__E753709E_0A41_4B53_9189_7473D14F9EEB__INCLUDED_)
#define AFX_EDHJSET_H__E753709E_0A41_4B53_9189_7473D14F9EEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EdhjSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEdhjSet dialog

class CEdhjSet : public CDialog
{
// Construction
public:
	CBrush m_brushBlue;
	CEdhjSet(CWnd* pParent = NULL);   // standard constructor
	int mopendata;

// Dialog Data
	//{{AFX_DATA(CEdhjSet)
	enum { IDD = IDD_EDHJ_SET };
	CButton	m_opendata;
	float	m_a;
	float	m_ai;
	CString	m_in;
	CString	m_out;
	int		m_no;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEdhjSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEdhjSet)
	afx_msg void OnFileopen();
	afx_msg void OnBrowse();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDHJSET_H__E753709E_0A41_4B53_9189_7473D14F9EEB__INCLUDED_)
