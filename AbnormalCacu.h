#if !defined(AFX_ABNORMALCACU_H__B78FFC74_36F3_432B_A71E_DCAF18BDB978__INCLUDED_)
#define AFX_ABNORMALCACU_H__B78FFC74_36F3_432B_A71E_DCAF18BDB978__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyDlg.h"
// AbnormalCacu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAbnormalCacu dialog

class CAbnormalCacu : public CDialog
{
// Construction
public:
	CAbnormalCacu(CWnd* pParent = NULL);   // standard constructor
	int mopendata;
	CString outfile;
	CString inpath,inname;
	CBrush m_brushBlue;

// Dialog Data
	//{{AFX_DATA(CAbnormalCacu)
	enum { IDD = IDD_ABNORMALCACU };
	CStatic	m_static;
	CEdit	m_first_bt;
	CButton	m_xydata;
	CButton	m_riviseopen;
	CEdit	m_rivisedata;
	CButton	m_rivise;
	CButton	m_opendata;
	CMyDlg*	dlg;
	CString	m_inputdata;
	CString	m_data;
	CString	m_first;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAbnormalCacu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAbnormalCacu)
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnRivise();
	afx_msg void OnRiviseOpen();
	afx_msg void OnInputOpen();
	afx_msg void OnFileForm();
	afx_msg void OnFileEdit();
	afx_msg void OnAbnormalcacu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABNORMALCACU_H__B78FFC74_36F3_432B_A71E_DCAF18BDB978__INCLUDED_)
