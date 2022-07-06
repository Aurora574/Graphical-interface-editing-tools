// draftDoc.cpp : CdraftDoc ���ʵ��
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


// CdraftDoc ����/����

CdraftDoc::CdraftDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CdraftDoc::~CdraftDoc()
{
}

BOOL CdraftDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CdraftDoc ���л�

void CdraftDoc::Serialize(CArchive& ar)
{
	int i;
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
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
		// TODO: �ڴ���Ӽ��ش���
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


// CdraftDoc ���

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


// CdraftDoc ����


