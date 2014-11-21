#if !defined(AFX_MYTREECTRL_H__8367F492_5FF2_4A1F_BE60_46C204C64FEB__INCLUDED_)
#define AFX_MYTREECTRL_H__8367F492_5FF2_4A1F_BE60_46C204C64FEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyTreeCtrl window

class MyTreeCtrl : public CTreeCtrl
{
// Construction
public:
	MyTreeCtrl();
	//MyTreeCtrl	m_CtrlTree;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(MyTreeCtrl)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREECTRL_H__8367F492_5FF2_4A1F_BE60_46C204C64FEB__INCLUDED_)
