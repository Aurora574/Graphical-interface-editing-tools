// MessageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "draft.h"
#include "MessageDlg.h"


// cMessageDlg �Ի���

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


// cMessageDlg ��Ϣ�������


