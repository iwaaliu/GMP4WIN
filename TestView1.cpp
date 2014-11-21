// TestView1.cpp : implementation of the CTestView1 class
//

#include "stdafx.h"
#include "afxext.h"
#include <afxhtml.h>
#include "afxwin.h"

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "OutBarDemo.h"
#include "Setting.h"
#include "GlobalDoc.h"
#include "TestView1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView1

IMPLEMENT_DYNCREATE(CTestView1, CView)

BEGIN_MESSAGE_MAP(CTestView1, CView)
	//{{AFX_MSG_MAP(CTestView1)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_MY_FILE_OPEN, OnMyFileOpen)
	ON_WM_VSCROLL()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_EL, OnDrawEl)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_RE, OnDrawRe)
	ON_COMMAND(ID_POINTER, OnPointer)
	ON_COMMAND(ID_MYDRAW, OnMydraw)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView1 construction/destruction

CTestView1::CTestView1()
{
	// TODO: add construction code here

}

CTestView1::~CTestView1()
{
}

BOOL CTestView1::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
flag=0;
ipos=0;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView1 drawing

void CTestView1::OnDraw(CDC* pDC)
{	CGlobalDoc* pDoc = GetDocument();
	//pDoc->SetTitle("我的标题");
	ASSERT_VALID(pDoc);
//pDC->TextOut(10,20,"xxxxx");
	CRect rc;
	int strlong=128;
	GetClientRect(rc);
	strlong=(int)((rc.Width()-72)/6);
//	pDC->DrawText(CString("OUT PUT!!!! TEST VIEW"), rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//	pDC->DrawText(CString("OUT PUT!!!! \nTEST VIEW\nRiver"), rc, NULL);
//flag=1;
	// TODO: add draw code for native data here
	if (flag==0)return;
	 int x=5,y=5;
	 char s[128];
	 in.open(filepath);
	 //ASSERT(in);	// assert(in);

	 while(!in.eof()) 
	 {
		 in.getline(s,strlong,'\n');
         pDC->TextOut(x,y,s);
		 x=5;y+=20;
	 }
	 in.close();
	 
//	 Invalidate();
//bool invalidate();
}

/////////////////////////////////////////////////////////////////////////////
// CTestView1 printing

BOOL CTestView1::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView1::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView1::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView1 diagnostics

#ifdef _DEBUG
void CTestView1::AssertValid() const
{
	CView::AssertValid();
}

void CTestView1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGlobalDoc* CTestView1::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGlobalDoc)));

	return (CGlobalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView1 message handlers


BOOL CTestView1::OnEraseBkgnd(CDC* pDC) 
{
	CBrush Brush (RGB (255 , 255, 255) );
	CBrush* pOldBrush = pDC->SelectObject (&Brush);
	CRect rcClip;
	pDC ->GetClipBox (&rcClip);
	pDC -> PatBlt (rcClip.left , rcClip.top , rcClip.Width ( ) , rcClip.Height( ) , PATCOPY );
	pDC ->SelectObject (pOldBrush );
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}

void CTestView1::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CView::OnLButtonDblClk(nFlags, point);
}

void CTestView1::Serialize(CArchive& ar) 
{
CString m_str;
	if (ar.IsStoring())
	{	
		ar<<m_str;// storing code
	}
	else
	{	// loading code
		ar>>m_str;
	}
}

void CTestView1::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
SCROLLINFO si;							////初始化滚动条
si.cbSize=sizeof(SCROLLINFO);
si.fMask = SIF_PAGE|SIF_RANGE;
/*si.nMin = 0;
si.nMax = 100;
si.nPage = 10;
SetScrollInfo(SB_HORZ,&si);
si.nMin =0;
si.nMax =100;
si.nPage = 5;
SetScrollInfo(SB_VERT,&si);*/
//ModifyStyleEx(0,WS_EX_CLIENTEDGE,SWP_FRAMECHANGED);	
}

void CTestView1::OnMyFileOpen() 
{
	// TODO: Add your command handler code here
		UpdateData(true);
	static char BASED_CODE szfilter[]="文本文档(*.txt)|*.txt|liu文档(*.liu)|*.liu|所有文件(*.*)|*.*|";
	CFileDialog myfile(1,".*","datas",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{//CString filename=myfile.GetFileName();
     filepath=myfile.GetPathName(); 
     
	 CDC *pDC=GetDC();
	 flag=1;
	 OnEraseBkgnd(pDC);
	 OnDraw(pDC);
	UpdateData(false);
	}
}

void CTestView1::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UpdateData(true);
	// TODO: Add your message handler code here and/or call default
		switch ( nSBCode )
		{
		case SB_BOTTOM:   		SetScrollPos(SB_VERT,100,TRUE);//Scroll to bottom.
		break;
		case SB_ENDSCROLL:		//ScrollWindow(0,-5,NULL,NULL);
			ipos+=5;SetScrollPos(SB_VERT,ipos,TRUE);//End scroll.
		break;
		case SB_LINEDOWN:		//ScrollWindow(0,-1,NULL,NULL);
			ipos+=1;SetScrollPos(SB_VERT,ipos,TRUE);//Scroll one line down.
		break;
		case SB_LINEUP:			//ScrollWindow(0,-1,NULL,NULL);
			ipos-=1;SetScrollPos(SB_VERT,ipos,TRUE);//Scroll one line up.
		break;
		case SB_PAGEDOWN:		//ScrollWindow(0,-5,NULL,NULL);
			ipos+=5;SetScrollPos(SB_VERT,ipos,TRUE);//Scroll one page down.
		break;
		case SB_PAGEUP :		//ScrollWindow(0,-5,NULL,NULL);
			ipos-=5;SetScrollPos(SB_VERT,ipos,TRUE);//Scroll one page up.
		break;
		case SB_THUMBPOSITION:	//ScrollWindow(0,-5,NULL,NULL);
			SetScrollPos(SB_VERT,nPos,TRUE);//Scroll to the absolute position. The current position is provided in nPos.
		break;
		case SB_THUMBTRACK :	//ScrollWindow(0,-5,NULL,NULL);
			SetScrollPos(SB_VERT,nPos,TRUE);//Drag scroll box to specified position. The current position is provided in nPos.
		break;
		case SB_TOP:			
			SetScrollPos(SB_VERT,0,TRUE);
		break;
		default:
			SetScrollPos(SB_VERT,ipos,TRUE);
		}
//	SetScrollPos(SB_VERT,ipos,TRUE);
//	CDC *pDC=GetDC();
//	OnDraw(pDC);
/*
	CString str;
	str.Format("%d",ipos);

	CDC *pDC=GetDC();
	pDC->TextOut(50,50,str);
*/
//		Invalidate();
	UpdateData(FALSE);
	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CTestView1::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
		switch ( nChar )
	{
	case VK_HOME:
		OnVScroll ( SB_TOP, 0, NULL);
		OnHScroll ( SB_LEFT, 0, NULL);
		break;
	case VK_END:
		OnVScroll ( SB_BOTTOM, 0, NULL);
		OnHScroll ( SB_RIGHT, 0, NULL);
		break;
	case VK_UP:
		OnVScroll ( SB_LINEUP, 0, NULL);
		break;
	case VK_DOWN:
		OnVScroll ( SB_LINEDOWN, 0, NULL);
		break;
	case VK_PRIOR:
		OnVScroll ( SB_PAGEUP, 0, NULL);
		break;
	case VK_NEXT:
		OnVScroll ( SB_PAGEDOWN, 0, NULL);
		break;
	case VK_LEFT:
		OnHScroll ( SB_LINELEFT, 0, NULL);
		break;
	case VK_RIGHT:
		OnHScroll ( SB_LINERIGHT, 0, NULL);
		break;
	default:
		break;	
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CTestView1::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CView::OnScroll(nScrollCode, nPos, bDoScroll);
}

void CTestView1::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar=='L'||nChar=='l')
	{
	GetDocument()->m_nDrawType=0;
	}
if(nChar=='e'||nChar=='E')
	{
	GetDocument()->m_nDrawType=1;
	}
if(nChar=='R'||nChar=='r')
	{
	GetDocument()->m_nDrawType=2;	//定义矩形
	}
if(nChar=='N'||nChar=='n')
	{
	GetDocument()->m_nDrawType=3;	//取消画笔
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CTestView1::OnLButtonDown(UINT nFlags, CPoint point) 
{
 //   MessageBox("msg");	
	CGlobalDoc* pDoc=GetDocument();
	pDoc->m_pStartPoint=point;
	pDoc->m_pEndPoint=point;
	pDoc->m_nIsMouseDrag=1;
	px=point.x;py=point.y;
	CView::OnLButtonDown(nFlags, point);
}

void CTestView1::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CGlobalDoc* pDoc=GetDocument();
    CClientDC dc(this);
	pDoc->m_nIsMouseDrag=0;
	pDoc->m_pEndPoint=point;
	if(pDoc->m_nDrawType==0)
	{
	dc.MoveTo(pDoc->m_pStartPoint);
	dc.LineTo(pDoc->m_pEndPoint);
	}
	if(pDoc->m_nDrawType==1)
	{
	dc.Ellipse(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
	}
	if(pDoc->m_nDrawType==2)
	{
	dc.Rectangle(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
	}
	//////
	if(pDoc->m_nDrawType==0){	
	CGlobalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	float k=10000.0;
	if((point.x - px)!=0){k=-((float)(point.y - py))/((float)(point.x - px));}
	CString str;
	str.Format("起点:%ld %ld 终点:%ld %ld 斜率:%10.2f ",px,480-py,point.x,480-point.y,k);
	if((point.x - px)==0) str.Format("斜率无穷大!!");
//	MessageBox(str);
	CDC *pDC=GetDC();
	pDC->TextOut(0,15,str);//DrawText(str, rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	//////
	CView::OnLButtonUp(nFlags, point);
}

void CTestView1::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CGlobalDoc* pDoc=GetDocument();
    CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	if(pDoc->m_nIsMouseDrag==1)
	{
		if(pDoc->m_nDrawType==0)
		{
		dc.MoveTo(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y);
		dc.LineTo(pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		pDoc->m_pEndPoint=point;
		dc.MoveTo(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y);
		dc.LineTo(pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		}

		if(pDoc->m_nDrawType==1)
		{
		dc.Ellipse(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		pDoc->m_pEndPoint=point;
		dc.Ellipse(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		}

		if(pDoc->m_nDrawType==2)
		{
		dc.Rectangle(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		pDoc->m_pEndPoint=point;
		dc.Rectangle(pDoc->m_pStartPoint.x,pDoc->m_pStartPoint.y,pDoc->m_pEndPoint.x,pDoc->m_pEndPoint.y);
		}
	}
//////
	if(pDoc->m_nDrawType==0){	
	CGlobalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	float k=10000.0;
	if((point.x - px)!=0){k=-((float)(point.y - py))/((float)(point.x - px));}
	CString str="";
	str.Format("起点:%d %d 终点:%d %d 斜率:%10.2f ",px,480-py,point.x,480-point.y,k);
	if(((point.x - px)==0) && ((point.y - py)!=0)) str.Format("斜率无穷大!!");
//	MessageBox(str);
	CDC *pDC=GetDC();
	pDC->TextOut(0,0,str);//DrawText(str, rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
//////	
	CView::OnMouseMove(nFlags, point);
}

void CTestView1::OnDrawEl() 
{
	// TODO: Add your command handler code here
	GetDocument()->m_nDrawType=1;
}

void CTestView1::OnDrawLine() 
{
	// TODO: Add your command handler code here
	GetDocument()->m_nDrawType=0;
}

void CTestView1::OnDrawRe() 
{
	// TODO: Add your command handler code here
	GetDocument()->m_nDrawType=2;
}

void CTestView1::OnPointer() 
{
	// TODO: Add your command handler code here
	GetDocument()->m_nDrawType=-1;
}

void CTestView1::OnMydraw() 
{	CGlobalDoc* pDoc=GetDocument();//
    CClientDC dc(this);
	FILE *fp=NULL;
	CDC *pDC=GetDC();//
CString filename;
CString filepath;
// fileext;
	static char BASED_CODE szfilter[]="Text Files(*.txt)|*.txt|数据文件(*.dat)|*.dat|Liu Files(*.liu)|*.liu|All Files(*.*)|*.*||";
	CFileDialog myfile(1,".txt","data",OFN_OVERWRITEPROMPT,szfilter);
	if(myfile.DoModal()==IDOK)
	{filename=myfile.GetFileName();
	 filepath=myfile.GetPathName();	

	CString	 fileext =myfile.GetFileExt();
	if(fileext=="dat"||fileext=="txt"||fileext=="liu"||fileext=="grd"||fileext=="TXT"||fileext=="GRD"||fileext=="DAT"||fileext=="LIU") {}
	else {AfxMessageBox("文件类型错误!");return;}

	bool fileopen=false;
	float xx=0.0,yy=0.0;
	int top=300;
	int len=0;
	len=filepath.GetLength();
	//	int fh;
	char path[100];//="da.txt"
	//char name[100];
	strcpy(path,filepath.GetBuffer(len));
	//strcpy(filename,path);
	
	/*MessageBox(name);
	for(int i=0;i<len;i++)
	{
	path[i]=filepath.GetAt(i);
	}*/
	
	//MessageBox(path);
	//	int i=0;
	//int x=0,y=0;
	
	if((fp=fopen(path,"r"))==NULL) {MessageBox("Cannot open file");return;}
	fscanf(fp,"%f%f",&xx,&yy);
	dc.MoveTo((int)xx,top-(int)yy);
	while( !feof(fp) )
	{	if( ferror( fp ) )     
	{
		perror( "Read error" );
	//MessageBox( "Read error" );
		break;
	//return;
	}
	fscanf(fp,"%f%f",&xx,&yy);
	dc.LineTo((int)xx,top-(int)yy);
	}
	fclose(fp);
	}
	//if(fileext==("dat"||"txt"||"liu"||"grd"||"TXT")) {}MessageBox("dd");
}
