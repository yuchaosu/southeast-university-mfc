#pragma once


// CTeacherClassDlg 对话框

class CTeacherClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherClassDlg)

public:
	CTeacherClassDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeacherClassDlg();

// 对话框数据
	enum { IDD = IDD_TeacherClass };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	COleDateTime m_ClassADate;
	COleDateTime m_ClassBDate;
	CString m_ClassBack;
	CString m_ClassGender;
	CString m_ClassMarry;
	CString m_ClassTitle;	
	int m_Flag;
};
