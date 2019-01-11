#pragma once
#include"P09017139_4Doc.h"

// SearchDlg 对话框

class SearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDlg)

public:
	SearchDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SearchDlg();

// 对话框数据
	enum { IDD = IDD_Search };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

//	int m_IDS;
	virtual BOOL OnInitDialog();
	CP09017139_4Doc* p;
	CComboBox m_Name;
	CString m_Name1;
};
