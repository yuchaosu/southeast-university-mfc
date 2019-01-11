// MatrixChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "MatrixChooseDlg.h"
#include "afxdialogex.h"


// CMatrixChooseDlg 对话框

IMPLEMENT_DYNAMIC(CMatrixChooseDlg, CDialogEx)

CMatrixChooseDlg::CMatrixChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMatrixChooseDlg::IDD, pParent)
{

	m_Matrix = 0;
}

CMatrixChooseDlg::~CMatrixChooseDlg()
{
}

void CMatrixChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Matrix2, m_Matrix);
}


BEGIN_MESSAGE_MAP(CMatrixChooseDlg, CDialogEx)
END_MESSAGE_MAP()


// CMatrixChooseDlg 消息处理程序
