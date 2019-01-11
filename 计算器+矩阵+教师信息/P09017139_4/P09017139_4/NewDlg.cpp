// NewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// NewDlg 对话框

IMPLEMENT_DYNAMIC(NewDlg, CDialogEx)

NewDlg::NewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(NewDlg::IDD, pParent)
{

	m_mRow = 0;
	m_mCol = 0;
}

NewDlg::~NewDlg()
{
}

void NewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ROW, m_mRow);
	DDX_Text(pDX, IDC_COL, m_mCol);
	DDX_Check(pDX, IDC_MAT2, m_Mat2);
}


BEGIN_MESSAGE_MAP(NewDlg, CDialogEx)
END_MESSAGE_MAP()


// NewDlg 消息处理程序
