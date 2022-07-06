// draftView.h : CdraftView ��Ľӿ�
//


#pragma once
#include "atltypes.h"
#include "afxwin.h"


class CdraftView : public CView
{
protected: // �������л�����
	CdraftView();
	DECLARE_DYNCREATE(CdraftView)

// ����
public:
	CdraftDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CdraftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onmessage();
public:
	afx_msg void Onabout();
public:
	int m_nDrawStyle;
public:
	CPoint m_ptStart;
public:
	CPoint m_ptEnd;
public:
	afx_msg void Online();
public:
	afx_msg void OnRect();
public:
	afx_msg void OnSrect();
public:
	afx_msg void OnElli();
public:
	afx_msg void OnSelli();
public:
	afx_msg void OnYtrectangle();
public:
	afx_msg void OnSytrectangle();
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);



public:
	afx_msg void Onpencolor();
public:
	afx_msg void Onfillcolor();
public:
	afx_msg void Onfont();
public:
	afx_msg void OnText();
public:
	afx_msg void Onwidth1();
public:
	afx_msg void Onwidth2();
public:
	afx_msg void Onwidth3();
public:
	afx_msg void Onwidth4();
public:
	afx_msg void Onwidth5();
public:
	afx_msg void Onsolidline();
public:
	afx_msg void Ondashline();
public:
	afx_msg void Ondotline();

};

#ifndef _DEBUG  // draftView.cpp �еĵ��԰汾
inline CdraftDoc* CdraftView::GetDocument() const
   { return reinterpret_cast<CdraftDoc*>(m_pDocument); }
#endif

