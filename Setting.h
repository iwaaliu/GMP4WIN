#if !defined(AFX_SETTING_H__2AD0AD7E_CFC1_457E_8229_BC725D091DD7__INCLUDED_)
#define AFX_SETTING_H__2AD0AD7E_CFC1_457E_8229_BC725D091DD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetting dialog

class CSetting : public CDialog
{
// Construction
public:
	CBrush m_brushBlue;
	CString m_file;
	CSetting(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
// Dialog Data
	//{{AFX_DATA(CSetting)
	enum { IDD = IDD_SETTING };
	CButton	m_opendata;
	int		m_10;
	int		m_1;
	int		m_2;
	float	m_3;
	int		m_4;
	int		m_5;
	int		m_9;
	CString	m_8;
	CString	m_c1;
	float	m_7;
	float	m_6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void SetStatusText(UINT nID = 0);
	// Generated message map functions
	//{{AFX_MSG(CSetting)
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	afx_msg BOOL OnTipNotify(UINT id,NMHDR *pNMHDR,LRESULT *pResult);

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING_H__2AD0AD7E_CFC1_457E_8229_BC725D091DD7__INCLUDED_)
