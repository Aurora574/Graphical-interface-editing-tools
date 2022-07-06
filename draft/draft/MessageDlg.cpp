// MessageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "draft.h"
#include "MessageDlg.h"


// cMessageDlg 对话框

IMPLEMENT_DYNAMIC(cMessageDlg, CDialog)

cMessageDlg::cMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(cMessageDlg::IDD, pParent)
{

}

cMessageDlg::~cMessageDlg()
{
}

void cMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cMessageDlg, CDialog)
	
END_MESSAGE_MAP()


// cMessageDlg 消息处理程序


