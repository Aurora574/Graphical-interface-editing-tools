#pragma once


// cMessageDlg 对话框

class cMessageDlg : public CDialog
{
	DECLARE_DYNAMIC(cMessageDlg)

public:
	cMessageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~cMessageDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

};
