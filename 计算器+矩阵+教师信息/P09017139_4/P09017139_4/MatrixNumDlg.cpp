// MatrixNumDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "MatrixNumDlg.h"
#include "afxdialogex.h"


// CMatrixNumDlg 对话框

IMPLEMENT_DYNAMIC(CMatrixNumDlg, CDialogEx)

CMatrixNumDlg::CMatrixNumDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMatrixNumDlg::IDD, pParent)
	,flag(0)
{

	m_Num = 0.0f;
	m_ColNum1 = 0;
	m_RowNum1 = 0;
	m_MatrixNum = 0;
}

CMatrixNumDlg::~CMatrixNumDlg()
{
}

void CMatrixNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLNUM, m_ColNum);
	DDX_Text(pDX, IDC_NUM, m_Num);
	DDX_Control(pDX, IDC_ROWNUM, m_RowNum);
	DDX_CBIndex(pDX, IDC_COLNUM, m_ColNum1);
	DDX_CBIndex(pDX, IDC_ROWNUM, m_RowNum1);
	DDX_Radio(pDX, IDC_MATRIXNUM1, m_MatrixNum);
}


BEGIN_MESSAGE_MAP(CMatrixNumDlg, CDialogEx)
	ON_BN_CLICKED(ID_CHANGE, &CMatrixNumDlg::OnBnClickedChange)
	ON_BN_CLICKED(IDC_MATRIXNUM1, &CMatrixNumDlg::OnBnClickedMatrixnum1)
	ON_BN_CLICKED(IDC_MATRIXNUM2, &CMatrixNumDlg::OnBnClickedMatrixnum2)
END_MESSAGE_MAP()


// CMatrixNumDlg 消息处理程序



void CMatrixNumDlg::OnBnClickedChange()
{
	UpdateData(true);
	flag=0;
	switch(m_MatrixNum)
	{
	case 0:
		p->mMat1[m_RowNum1][m_ColNum1]=m_Num;
		flag=1;
		break;
	case 1:
		p->mMat2[m_RowNum1][m_ColNum1]=m_Num;
		flag=1;
		break;
	}// TODO: 在此添加控件通知处理程序代码
}


void CMatrixNumDlg::OnBnClickedMatrixnum1()
{
	CString Str1;
	m_ColNum.ResetContent();
	m_RowNum.ResetContent();
	for(int i=0; i < p->mMat1.mCol;i++)
	{
		Str1.Format(_T("%d"),i+1);
		m_ColNum.AddString(Str1);

	}
	for(int i=0; i < p->mMat1.mRow;i++)
	{
		Str1.Format(_T("%d"),i+1);
		m_RowNum.AddString(Str1);

	}
}


void CMatrixNumDlg::OnBnClickedMatrixnum2()
{
	CString Str2;
	m_ColNum.ResetContent();
	m_RowNum.ResetContent();
	for(int i=0; i < p->mMat2.mCol;i++)
	{
		Str2.Format(_T("%d"),i+1);
		m_ColNum.AddString(Str2);

	}
	for(int i=0; i < p->mMat2.mRow;i++)
	{
		Str2.Format(_T("%d"),i+1);
		m_RowNum.AddString(Str2);

	}
}


BOOL CMatrixNumDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString Str1;
	for(int i=0; i < p->mMat1.mCol;i++)
	{
		Str1.Format(_T("%d"),i+1);
		m_ColNum.AddString(Str1);

	}
	for(int i=0; i < p->mMat1.mRow;i++)
	{
		Str1.Format(_T("%d"),i+1);
		m_RowNum.AddString(Str1);

	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
