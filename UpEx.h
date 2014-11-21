#if !defined(AFX_UPEX_H__42685703_959B_4911_8383_3FE8859A0805__INCLUDED_)
#define AFX_UPEX_H__42685703_959B_4911_8383_3FE8859A0805__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UpEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUpEx dialog

class CUpEx : public CDialog
{
// Construction
public:
	CUpEx(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUpEx)
	enum { IDD = IDD_UP_EXTEND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpEx)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpEx)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPEX_H__42685703_959B_4911_8383_3FE8859A0805__INCLUDED_)
