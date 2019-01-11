// cSignupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "cSignupDlg.h"
#include "afxdialogex.h"


// cSignupDlg 对话框

IMPLEMENT_DYNAMIC(cSignupDlg, CDialogEx)

cSignupDlg::cSignupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(cSignupDlg::IDD, pParent)
{

	m_Class = 0;
	m_Code = 0;
	m_ID = 0;
	m_Name = _T("");
	m_Room = _T("");
	m_Semester = _T("");
	m_Time = 0;
}

cSignupDlg::~cSignupDlg()
{
}

void cSignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_cCLASS, m_Class);
	DDX_Text(pDX, IDC_cCODE, m_Code);
	DDX_Text(pDX, IDC_cID, m_ID);
	DDX_Text(pDX, IDC_cNAME, m_Name);
	DDX_Text(pDX, IDC_cROOM, m_Room);
	DDX_Text(pDX, IDC_cSEMESTER, m_Semester);
	DDX_Text(pDX, IDC_cTIME, m_Time);
}


BEGIN_MESSAGE_MAP(cSignupDlg, CDialogEx)
END_MESSAGE_MAP()


// cSignupDlg 消息处理程序
