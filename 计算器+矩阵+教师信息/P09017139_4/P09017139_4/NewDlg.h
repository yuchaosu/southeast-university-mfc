#pragma once


// NewDlg 对话框

class NewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewDlg)

public:
	NewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NewDlg();

// 对话框数据
	enum { IDD = IDD_NEW_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_mRow;
	int m_mCol;
	BOOL m_Mat2;
};
