// draftDoc.cpp : CdraftDoc 类的实现
//

#include "stdafx.h"
#include "draft.h"

#include "draftDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdraftDoc

IMPLEMENT_DYNCREATE(CdraftDoc, CDocument)

BEGIN_MESSAGE_MAP(CdraftDoc, CDocument)
END_MESSAGE_MAP()


// CdraftDoc 构造/析构

CdraftDoc::CdraftDoc()
{
	// TODO: 在此添加一次性构造代码

}

CdraftDoc::~CdraftDoc()
{
}

BOOL CdraftDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CdraftDoc 序列化

void CdraftDoc::Serialize(CArchive& ar)
{
	int i;
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<Mylist.GetCount();
        Graphic g;
        POSITION pos = Mylist.GetHeadPosition();
        for(i=0;i<Mylist.GetCount();i++)
        {
            g=Mylist.GetNext(pos);
            ar<<g.type<<g.penwidth<<g.pencolor<<g.start<<g.end<<g.pentype;
        }
	}
	else
	{
		// TODO: 在此添加加载代码
		int count;
        ar>>count;
        Graphic g;
        POSITION pos = Mylist.GetHeadPosition();
        for(i = 0; i<count; i++)
        {
            ar<<g.type<<g.penwidth<<g.pencolor<<g.start<<g.end<<g.pentype;
            Mylist.AddTail(g);
        }
	}
}


// CdraftDoc 诊断

#ifdef _DEBUG
void CdraftDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdraftDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdraftDoc 命令


