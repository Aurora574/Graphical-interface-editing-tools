// draftDoc.h : CdraftDoc ��Ľӿ�
//


#pragma once
#include "afxtempl.h"


class CdraftDoc : public CDocument
{
protected: // �������л�����
	CdraftDoc();
	DECLARE_DYNCREATE(CdraftDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CdraftDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
	void Serialize(void);

public:
	CList<Graphic,Graphic> Mylist;
};


