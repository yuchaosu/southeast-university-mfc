#pragma once

#include"P09017139_4Doc.h"
// CMatrixNumDlg 对话框

class CMatrixNumDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMatrixNumDlg)

public:
	CMatrixNumDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMatrixNumDlg();

// 对话框数据
	enum { IDD = IDD_MATRIXNUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CP09017139_4Doc* p;
	CComboBox m_ColNum;
	float m_Num;
	CComboBox m_RowNum;
	int m_ColNum1;
	int m_RowNum1;
	int m_MatrixNum;
	int flag;
	afx_msg void OnBnClickedChange();
	afx_msg void OnBnClickedMatrixnum1();
	afx_msg void OnBnClickedMatrixnum2();
	virtual BOOL OnInitDialog();
};
