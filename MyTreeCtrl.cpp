// MyTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "OutBarDemo.h"
#include "MyTreeCtrl.h"
#include "MainFrm.h"

#include "ThrOp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyTreeCtrl

MyTreeCtrl::MyTreeCtrl()
{
}

MyTreeCtrl::~MyTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(MyTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(MyTreeCtrl)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyTreeCtrl message handlers

void MyTreeCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CMainFrame frm;
	HTREEITEM treehwnd;//,treehwnd2
	HTREEITEM hrootitem;
	CString str,str2,str3;

	treehwnd=GetSelectedItem();
//	treehwnd2=GetParentItem(treehwnd);//GetParentItem
	hrootitem=GetRootItem();

	str=GetItemText(treehwnd);//	str2=GetItemText(treehwnd2);
	str2=GetItemText(hrootitem);//AfxMessageBox(str2);

	char t[20]="回放";

	if(str=="二度化极"){ if(str2==t) frm.DoEdhj();}
	else if (str=="球体") {if(str2==t) frm.DoSetting();			else frm.DoGravityQt();}
	else if (str=="静态试验") {if(str2==t) goto label;	else frm.DoStaticTest() ;}
	else if (str=="两点") {if(str2==t) frm.DoDynamicTwomag() ;	else frm.DoDynamicTwo() ;}
	else if (str=="多点") {if(str2==t)frm.DoDynamicMulmag()  ;	else frm.DoDynamicMulti() ;}
	else if (str=="仪器一致性检验") {if(str2==t) frm.DoCoherenceMag() ;else frm.DoCoherenceTest() ;}
	else if (str=="格值校正") {if(str2==t) frm.DoValuetestMag() ;else frm.DoValueRivise() ;}
	else if (str=="初步整理") {if(str2==t) goto label; else frm.DoPreTrim() ;}
	else if (str=="异常计算") {if(str2==t) goto label; else frm.DoAbnormalCacu();}
	else if (str=="二度上延") {if(str2==t) {goto label;frm.DoMagUpex2() ;}	else frm.DoUpExtend2() ;}
	else if (str=="二度下延") {if(str2==t) {goto label;frm.DoMagDownex2() ;}else frm.DoDownExtend2() ;}
	else if (str=="三度上延") {if(str2==t) {goto label;frm.DoMagUpex3() ;}	else frm.DoMagUpex3(); }
	else if (str=="三度下延") {if(str2==t) {goto label;frm.DoMagDownex3();}	else frm.DoDownExtend3() ;}
	else if (str=="二度Vxz")  {if(str2==t) {goto label;frm.DoMagVxz2() ;}	else frm.DoVxz2();}
	else if (str=="二度Vzz")  {if(str2==t) {goto label;frm.DoMagVzz2() ;}	else frm.DoVzz2();}
	else if (str=="二度Vzzz") {if(str2==t) {goto label;frm.DoMagVzzz2() ;}	else frm.DoVzzz2(); }
	else if (str=="三度Vxz")  {if(str2==t) {goto label;frm.DoMagVxz3() ;}	else frm.DoVxz3();}
	else if (str=="三度Vzz")  {if(str2==t) {goto label;frm.DoMagVzz3() ;}	else frm.DoVzz3() ;}
	else if (str=="三度Vzzz") {if(str2==t) {goto label;frm.DoMagVzz3() ;}	else frm.DoVzzz3() ;}
	else if (str=="二度体")   {if(str2==t)  ;else  ;}
	else if (str=="数据回放") {if(str2==t) frm.DoDataReview();else  ;}
	else if (str=="磁三分量法") {//MessageBox("");
label:									CThrOp DlgSet;
									if((DlgSet.DoModal())==IDOK)
									{frm.CallFunction();}
								}
/*	else if (str=="NMR正演计算") {if(str2==t)  ;else  ;}
	else if (str=="NMR反演解释") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
	else if (str=="") {if(str2==t)  ;else  ;}
*/
	else if (str=="SUFFER")frm.DoSuffer();
	else if (str=="GRAPHER")frm.DoGrapher();
	else
	{if(str2=="绘图"&&str!="绘图"){
	CString str1,strname,strexec,strt;
char cust[100];
//char name[20]
//char exec[100][100];
int len,lenl,lenr,pos;
	FILE *fp=NULL,*fptype=NULL;
	if((fp=fopen("customize.ini","r"))==NULL)
	{
	MessageBox("自定义选项程序打开失败!");	return;
	}
	else 
	{while( !feof(fp) )
	{	if( ferror( fp ) )     
	{
		perror( "Read error" );
		break;
	}
	else
	{
		fscanf(fp,"%s",&cust);
		str1.Format("%s",cust);
		len=str1.GetLength();
		
		if(str1.Left(1)=="+"){/*htm = wndTree2.InsertItem(str.Right(len-1), 0,2);*/
			pos=str1.Find("@");
			strt.Format("%s",str1.Left(pos));
			lenl=pos-1;
			strname.Format("%s",strt.Right(lenl));
			pos+=2;
			lenr=len-pos;
			strexec.Format("%s",str1.Right(lenr-1));
			if((fptype=fopen("mytype.liu","w+"))==NULL)
			{
				MessageBox("创建mytype.liu文件失败!");//	return;
			}
			else 
			{
				if(str==strname)
				{
//					MessageBox(str+strname+strexec);
					fprintf(fptype,"%s",strname);
				HINSTANCE hin =	ShellExecute(NULL,"open",strexec,NULL,NULL,SW_SHOW);
				if(((int)hin)<32) AfxMessageBox("未能找到指定的程序,请重新指定链接程序!");
					fclose(fptype);
					break;
				}
				
			}
		}	
	}
	}
	}
	fclose(fp);
	}
	};
	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}
