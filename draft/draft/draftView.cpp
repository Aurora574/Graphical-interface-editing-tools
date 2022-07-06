// draftView.cpp : CdraftView 类的实现
//

#include "stdafx.h"
#include "draft.h"
#include "draftDoc.h"
#include "draftView.h"
#include "MessageDlg.h"
COLORREF color;  //画笔颜色
int penstyle,width;  //画笔线型和宽度
COLORREF Fontcolor;   //字体颜色   
CFont mypointfont;   //字体类型
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdraftView

IMPLEMENT_DYNCREATE(CdraftView, CView)

BEGIN_MESSAGE_MAP(CdraftView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDD_message, &CdraftView::Onmessage)
	ON_COMMAND(ID_about, &CdraftView::Onabout)
	ON_COMMAND(ID_line, &CdraftView::Online)
	ON_COMMAND(ID_RECT, &CdraftView::OnRect)
	ON_COMMAND(ID_SRECT, &CdraftView::OnSrect)
	ON_COMMAND(ID_ELLI, &CdraftView::OnElli)
	ON_COMMAND(ID_SELLI, &CdraftView::OnSelli)
	ON_COMMAND(ID_YTRECTANGLE, &CdraftView::OnYtrectangle)
	ON_COMMAND(ID_SYTRECTANGLE, &CdraftView::OnSytrectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_pencolor, &CdraftView::Onpencolor)
	ON_COMMAND(ID_font, &CdraftView::Onfont)
	ON_COMMAND(ID_Text, &CdraftView::OnText)
	ON_COMMAND(ID_width1, &CdraftView::Onwidth1)
	ON_COMMAND(ID_width2, &CdraftView::Onwidth2)
	ON_COMMAND(ID_width3, &CdraftView::Onwidth3)
	ON_COMMAND(ID_width4, &CdraftView::Onwidth4)
	ON_COMMAND(ID_width5, &CdraftView::Onwidth5)
	ON_COMMAND(ID_solidline, &CdraftView::Onsolidline)
	ON_COMMAND(ID_dashline, &CdraftView::Ondashline)
	ON_COMMAND(ID_dotline, &CdraftView::Ondotline)
END_MESSAGE_MAP()

// CdraftView 构造/析构

CdraftView::CdraftView()
: m_nDrawStyle(0)
, m_ptStart(0)
, m_ptEnd(0)
{
	// TODO: 在此处添加构造代码
	m_nDrawStyle=0;

}

CdraftView::~CdraftView()
{
}

BOOL CdraftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdraftView 绘制

void CdraftView::OnDraw(CDC* pDC)
{
	CdraftDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Graphic g;
    POSITION pos=pDoc->Mylist.GetHeadPosition();
    for(int i=0;i<pDoc->Mylist.GetCount();i++)
    {
        g = pDoc->Mylist.GetNext(pos);
        CPen pen;	    pen.CreatePen(g.pentype,g.penwidth,g.pencolor);
        pDC->SelectObject(&pen);
        if(g.type==1)//画直线
        {
            pDC->MoveTo(g.start);		    pDC->LineTo(g.end);
        }
        if(g.type==2)//画矩形
        { 
            pDC->SelectStockObject(NULL_BRUSH);
			pDC->Rectangle(CRect(g.start,g.end));
        }
		if(g.type==3)//画填充矩形
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->Rectangle(CRect(g.start,g.end));
            brush.DeleteObject();
        }
        if(g.type==4)//画圆形
        {
			pDC->SelectStockObject(NULL_BRUSH);
            pDC->Ellipse(CRect(g.start,g.end));
        }
        
        if(g.type==5)//画填充圆形
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->Ellipse(CRect(g.start,g.end));
            brush.DeleteObject();
        }
        if(g.type==6)//画圆角矩形
        {
			pDC->SelectStockObject(NULL_BRUSH);
            pDC->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,30,30);
        }
        if(g.type==7)//画填充圆角矩形
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,30,30);
            brush.DeleteObject();
        }
		 else if(g.type==8)       //显示文本
	   {
         pDC->SetTextColor(Fontcolor);	     pDC->SetBkColor(Fontcolor);	     pDC->SetBkMode(TRANSPARENT);         pDC->SelectObject(&mypointfont);         CString string= _T("文字显示示例");	 	     pDC->TextOutW(g.start.x,g.start.y,string);
	    }
        
    }

	// TODO: 在此处为本机数据添加绘制代码
}


// CdraftView 打印

BOOL CdraftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdraftView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdraftView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CdraftView 诊断

#ifdef _DEBUG
void CdraftView::AssertValid() const
{
	CView::AssertValid();
}

void CdraftView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdraftDoc* CdraftView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdraftDoc)));
	return (CdraftDoc*)m_pDocument;
}
#endif //_DEBUG


// CdraftView 消息处理程序

void CdraftView::Onmessage()
{
	// TODO: 在此添加命令处理程序代码

}

void CdraftView::Onabout()                //个人信息框
{
	// TODO: 在此添加命令处理程序代码
    cMessageDlg dlg;
    int ret=dlg.DoModal();
    if(ret==IDOK)
	{
        MessageBox(_T("确定！！"),_T("提示"));
	}
	else if(ret==IDCANCEL)
	{
        MessageBox(_T("取消！！"),_T("提示"));
	}
}

void CdraftView::Online()                      //直线
{
	// TODO: 在此添加命令处理程序代码
     m_nDrawStyle=1;
}


void CdraftView::OnRect()                     //矩形
{
	// TODO: 在此添加命令处理程序代码
     m_nDrawStyle=2;
}

void CdraftView::OnSrect()                    //填充矩形
{
	// TODO: 在此添加命令处理程序代码
	
     m_nDrawStyle=3;
}

void CdraftView::OnElli()                    //圆形
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=4;
}

void CdraftView::OnSelli()                  //填充圆
{
	// TODO: 在此添加命令处理程序代码

     m_nDrawStyle=5;
}

void CdraftView::OnYtrectangle()           //圆角矩形
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=6;
}

void CdraftView::OnSytrectangle()            //填充圆角矩形
{
	// TODO: 在此添加命令处理程序代码
     m_nDrawStyle=7;
}

void CdraftView::OnLButtonDown(UINT nFlags, CPoint point)           //鼠标按下
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
     m_ptStart=point;
	CView::OnLButtonDown(nFlags, point);
}

void CdraftView::OnLButtonUp(UINT nFlags, CPoint point)          //鼠标抬起
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptEnd=point;
    Graphic g;
    g.start=m_ptStart;
    g.end=m_ptEnd;
    g.type=m_nDrawStyle;
	g.pentype=penstyle;
	g.pencolor=color;
	g.penwidth=width;
	GetDocument()->Mylist.AddTail(g);  //保存信息
    Invalidate();

	CView::OnLButtonUp(nFlags,point);
}

void CdraftView::Onpencolor()               //画笔颜色
{
	// TODO: 在此添加命令处理程序代码

	CString strColor;
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal() == IDOK)
	{
		color = dlg.GetColor();
		strColor.Format(_T("%x"),color);
		MessageBox(_T("已取得颜色")+strColor,_T("选择颜色"));
	}

}

void CdraftView::Onfont()           //字体样式
{
	// TODO: 在此添加命令处理程序代码
	CString strColor;
    LOGFONT lf;
	CFontDialog dlg(&lf);
	if(dlg.DoModal() == IDOK)
	{ 
		if(mypointfont.m_hObject)
        {
            mypointfont.DeleteObject();
        }
        mypointfont.CreateFontIndirect(dlg.m_cf.lpLogFont);//字体信息
		CString str=_T("设置字体为");
		MessageBox(str+lf.lfFaceName);    //获取字体名称
		Fontcolor=dlg.GetColor();
		strColor.Format(_T("%x"),color);
		MessageBox(_T("已取得颜色")+strColor,_T("选择颜色"));
	}
	
}
void CdraftView::OnText()             //添加文本
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=8;	
}

void CdraftView::Onwidth1()                       //宽度设置
{
	// TODO: 在此添加命令处理程序代码
	width=1;
}

void CdraftView::Onwidth2()
{
	// TODO: 在此添加命令处理程序代码
	width=2;
    MessageBox(_T("根据查阅课本内容得知，只有在宽度为1的时候，才能显示除实线外的其他画笔类型，当宽度大于1时画出来的都是实线类型的线条"),_T("注意"));
}


void CdraftView::Onwidth3()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("根据查阅课本内容得知，只有在宽度为1的时候，才能显示除实线外的其他画笔类型，当宽度大于1时画出来的都是实线类型的线条"),_T("注意"));
	width=3;

}

void CdraftView::Onwidth4()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("根据查阅课本内容得知，只有在宽度为1的时候，才能显示除实线外的其他画笔类型，当宽度大于1时画出来的都是实线类型的线条"),_T("注意"));
	width=4;
}


void CdraftView::Onwidth5()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("根据查阅课本内容得知，只有在宽度为1的时候，才能显示除实线外的其他画笔类型，当宽度大于1时画出来的都是实线类型的线条"),_T("注意"));
	width=5;
}

void CdraftView::Onsolidline()                           //实线
{
	// TODO: 在此添加命令处理程序代码
	penstyle=PS_SOLID;
}

void CdraftView::Ondashline()                          //虚线
{
	// TODO: 在此添加命令处理程序代码
    penstyle=PS_DASH;
}

void CdraftView::Ondotline()                               //点线
{
	// TODO: 在此添加命令处理程序代码
    penstyle=PS_DOT;
}

