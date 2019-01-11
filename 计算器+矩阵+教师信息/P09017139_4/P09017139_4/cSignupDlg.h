#pragma once


// cSignupDlg 对话框

class cSignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(cSignupDlg)

public:
	cSignupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~cSignupDlg();

// 对话框数据
	enum { IDD = IDD_cSIGNUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Class;
	int m_Code;
	int m_ID;
	CString m_Name;
	CString m_Room;
	CString m_Semester;
	int m_Time;
};
