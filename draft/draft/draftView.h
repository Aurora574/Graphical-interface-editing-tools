// draftView.h : CdraftView 类的接口
//


#pragma once
#include "atltypes.h"
#include "afxwin.h"


class CdraftView : public CView
{
protected: // 仅从序列化创建
	CdraftView();
	DECLARE_DYNCREATE(CdraftView)

// 属性
public:
	CdraftDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CdraftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // draftView.cpp 中的调试版本
inline CdraftDoc* CdraftView::GetDocument() const
   { return reinterpret_cast<CdraftDoc*>(m_pDocument); }
#endif

