#pragma once


// tSignupDlg 对话框

class CtSignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CtSignupDlg)

public:
	CtSignupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CtSignupDlg();

// 对话框数据
	enum { IDD = IDD_tSIGNUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_tID;
	int m_Salary;
	COleDateTime m_Date;
	CString m_Name;
	CString m_Back;
	CString m_Gender;
	CString m_Marry;
	CString m_Title;
};
