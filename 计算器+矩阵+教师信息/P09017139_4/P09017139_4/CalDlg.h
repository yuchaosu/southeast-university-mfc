#pragma once


// CalDlg 对话框

class CalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CalDlg)

public:
	CalDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CalDlg();

// 对话框数据
	enum { IDD = IDD_CAL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	afx_msg void OnBnClickedCal();
	float GetResult(CString Str);
	char FindOper(CString Str, CString& LStr, CString& RStr);

};
