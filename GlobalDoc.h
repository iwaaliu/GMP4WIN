// GlobalDoc.h : interface of the CGlobalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBALDOC_H__28FA2C9A_11B7_11D2_8437_0000B43382FE__INCLUDED_)
#define AFX_GLOBALDOC_H__28FA2C9A_11B7_11D2_8437_0000B43382FE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CGlobalDoc : public CDocument
{
protected: // create from serialization only
	CGlobalDoc();
	DECLARE_DYNCREATE(CGlobalDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlobalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_str;

	void OnShowHideIebar();

	virtual ~CGlobalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGlobalDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_pStartPoint;
	CPoint m_pEndPoint;
	int m_nDrawType;
	int m_nIsMouseDrag;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLOBALDOC_H__28FA2C9A_11B7_11D2_8437_0000B43382FE__INCLUDED_)
