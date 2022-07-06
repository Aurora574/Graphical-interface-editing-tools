// draftView.cpp : CdraftView ���ʵ��
//

#include "stdafx.h"
#include "draft.h"
#include "draftDoc.h"
#include "draftView.h"
#include "MessageDlg.h"
COLORREF color;  //������ɫ
int penstyle,width;  //�������ͺͿ��
COLORREF Fontcolor;   //������ɫ   
CFont mypointfont;   //��������
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdraftView

IMPLEMENT_DYNCREATE(CdraftView, CView)

BEGIN_MESSAGE_MAP(CdraftView, CView)
	// ��׼��ӡ����
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

// CdraftView ����/����

CdraftView::CdraftView()
: m_nDrawStyle(0)
, m_ptStart(0)
, m_ptEnd(0)
{
	// TODO: �ڴ˴���ӹ������
	m_nDrawStyle=0;

}

CdraftView::~CdraftView()
{
}

BOOL CdraftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CdraftView ����

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
        if(g.type==1)//��ֱ��
        {
            pDC->MoveTo(g.start);		    pDC->LineTo(g.end);
        }
        if(g.type==2)//������
        { 
            pDC->SelectStockObject(NULL_BRUSH);
			pDC->Rectangle(CRect(g.start,g.end));
        }
		if(g.type==3)//��������
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->Rectangle(CRect(g.start,g.end));
            brush.DeleteObject();
        }
        if(g.type==4)//��Բ��
        {
			pDC->SelectStockObject(NULL_BRUSH);
            pDC->Ellipse(CRect(g.start,g.end));
        }
        
        if(g.type==5)//�����Բ��
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->Ellipse(CRect(g.start,g.end));
            brush.DeleteObject();
        }
        if(g.type==6)//��Բ�Ǿ���
        {
			pDC->SelectStockObject(NULL_BRUSH);
            pDC->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,30,30);
        }
        if(g.type==7)//�����Բ�Ǿ���
        {
            CBrush brush;
            brush.CreateSolidBrush(g.pencolor);
            pDC->SelectObject(&brush);
            pDC->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,30,30);
            brush.DeleteObject();
        }
		 else if(g.type==8)       //��ʾ�ı�
	   {
         pDC->SetTextColor(Fontcolor);	     pDC->SetBkColor(Fontcolor);	     pDC->SetBkMode(TRANSPARENT);         pDC->SelectObject(&mypointfont);         CString string= _T("������ʾʾ��");	 	     pDC->TextOutW(g.start.x,g.start.y,string);
	    }
        
    }

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CdraftView ��ӡ

BOOL CdraftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CdraftView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CdraftView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CdraftView ���

#ifdef _DEBUG
void CdraftView::AssertValid() const
{
	CView::AssertValid();
}

void CdraftView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdraftDoc* CdraftView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdraftDoc)));
	return (CdraftDoc*)m_pDocument;
}
#endif //_DEBUG


// CdraftView ��Ϣ�������

void CdraftView::Onmessage()
{
	// TODO: �ڴ���������������

}

void CdraftView::Onabout()                //������Ϣ��
{
	// TODO: �ڴ���������������
    cMessageDlg dlg;
    int ret=dlg.DoModal();
    if(ret==IDOK)
	{
        MessageBox(_T("ȷ������"),_T("��ʾ"));
	}
	else if(ret==IDCANCEL)
	{
        MessageBox(_T("ȡ������"),_T("��ʾ"));
	}
}

void CdraftView::Online()                      //ֱ��
{
	// TODO: �ڴ���������������
     m_nDrawStyle=1;
}


void CdraftView::OnRect()                     //����
{
	// TODO: �ڴ���������������
     m_nDrawStyle=2;
}

void CdraftView::OnSrect()                    //������
{
	// TODO: �ڴ���������������
	
     m_nDrawStyle=3;
}

void CdraftView::OnElli()                    //Բ��
{
	// TODO: �ڴ���������������
	m_nDrawStyle=4;
}

void CdraftView::OnSelli()                  //���Բ
{
	// TODO: �ڴ���������������

     m_nDrawStyle=5;
}

void CdraftView::OnYtrectangle()           //Բ�Ǿ���
{
	// TODO: �ڴ���������������
	m_nDrawStyle=6;
}

void CdraftView::OnSytrectangle()            //���Բ�Ǿ���
{
	// TODO: �ڴ���������������
     m_nDrawStyle=7;
}

void CdraftView::OnLButtonDown(UINT nFlags, CPoint point)           //��갴��
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
     m_ptStart=point;
	CView::OnLButtonDown(nFlags, point);
}

void CdraftView::OnLButtonUp(UINT nFlags, CPoint point)          //���̧��
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptEnd=point;
    Graphic g;
    g.start=m_ptStart;
    g.end=m_ptEnd;
    g.type=m_nDrawStyle;
	g.pentype=penstyle;
	g.pencolor=color;
	g.penwidth=width;
	GetDocument()->Mylist.AddTail(g);  //������Ϣ
    Invalidate();

	CView::OnLButtonUp(nFlags,point);
}

void CdraftView::Onpencolor()               //������ɫ
{
	// TODO: �ڴ���������������

	CString strColor;
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal() == IDOK)
	{
		color = dlg.GetColor();
		strColor.Format(_T("%x"),color);
		MessageBox(_T("��ȡ����ɫ")+strColor,_T("ѡ����ɫ"));
	}

}

void CdraftView::Onfont()           //������ʽ
{
	// TODO: �ڴ���������������
	CString strColor;
    LOGFONT lf;
	CFontDialog dlg(&lf);
	if(dlg.DoModal() == IDOK)
	{ 
		if(mypointfont.m_hObject)
        {
            mypointfont.DeleteObject();
        }
        mypointfont.CreateFontIndirect(dlg.m_cf.lpLogFont);//������Ϣ
		CString str=_T("��������Ϊ");
		MessageBox(str+lf.lfFaceName);    //��ȡ��������
		Fontcolor=dlg.GetColor();
		strColor.Format(_T("%x"),color);
		MessageBox(_T("��ȡ����ɫ")+strColor,_T("ѡ����ɫ"));
	}
	
}
void CdraftView::OnText()             //����ı�
{
	// TODO: �ڴ���������������
	m_nDrawStyle=8;	
}

void CdraftView::Onwidth1()                       //�������
{
	// TODO: �ڴ���������������
	width=1;
}

void CdraftView::Onwidth2()
{
	// TODO: �ڴ���������������
	width=2;
    MessageBox(_T("���ݲ��Ŀα����ݵ�֪��ֻ���ڿ��Ϊ1��ʱ�򣬲�����ʾ��ʵ����������������ͣ�����ȴ���1ʱ�������Ķ���ʵ�����͵�����"),_T("ע��"));
}


void CdraftView::Onwidth3()
{
	// TODO: �ڴ���������������
	MessageBox(_T("���ݲ��Ŀα����ݵ�֪��ֻ���ڿ��Ϊ1��ʱ�򣬲�����ʾ��ʵ����������������ͣ�����ȴ���1ʱ�������Ķ���ʵ�����͵�����"),_T("ע��"));
	width=3;

}

void CdraftView::Onwidth4()
{
	// TODO: �ڴ���������������
	MessageBox(_T("���ݲ��Ŀα����ݵ�֪��ֻ���ڿ��Ϊ1��ʱ�򣬲�����ʾ��ʵ����������������ͣ�����ȴ���1ʱ�������Ķ���ʵ�����͵�����"),_T("ע��"));
	width=4;
}


void CdraftView::Onwidth5()
{
	// TODO: �ڴ���������������
	MessageBox(_T("���ݲ��Ŀα����ݵ�֪��ֻ���ڿ��Ϊ1��ʱ�򣬲�����ʾ��ʵ����������������ͣ�����ȴ���1ʱ�������Ķ���ʵ�����͵�����"),_T("ע��"));
	width=5;
}

void CdraftView::Onsolidline()                           //ʵ��
{
	// TODO: �ڴ���������������
	penstyle=PS_SOLID;
}

void CdraftView::Ondashline()                          //����
{
	// TODO: �ڴ���������������
    penstyle=PS_DASH;
}

void CdraftView::Ondotline()                               //����
{
	// TODO: �ڴ���������������
    penstyle=PS_DOT;
}

