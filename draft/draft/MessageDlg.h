#pragma once


// cMessageDlg �Ի���

class cMessageDlg : public CDialog
{
	DECLARE_DYNAMIC(cMessageDlg)

public:
	cMessageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~cMessageDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

};
