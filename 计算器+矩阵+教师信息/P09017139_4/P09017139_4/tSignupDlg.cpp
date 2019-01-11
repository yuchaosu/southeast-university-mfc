// tSignupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "tSignupDlg.h"
#include "afxdialogex.h"


// tSignupDlg 对话框

IMPLEMENT_DYNAMIC(CtSignupDlg, CDialogEx)

CtSignupDlg::CtSignupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtSignupDlg::IDD, pParent)
{

	//  m_tID = _T("");
	m_tID = 0;
	m_Salary = 0;
	//  m_Marry = _T("");
	//  m_Gender = _T("");
	m_Date = COleDateTime::GetCurrentTime();
	//  m_Back = _T("");
	//  m_Title = _T("");
	m_Name = _T("");
	//  m_BACK = _T("");
	m_Back = _T("");
	m_Gender = _T("");
	m_Marry = _T("");
	m_Title = _T("");
}

CtSignupDlg::~CtSignupDlg()
{
}

void CtSignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  D//  DX_Text(p//  DX, I//  DC_tI//  D, m_tI//  D);
	DDX_Text(pDX, IDC_tID, m_tID);
	DDX_Text(pDX, IDC_SALARY, m_Salary);
	//  DDX_Control(pDX, IDC_MARRY, m_Marry、);
	//  DDX_Text(pDX, IDC_MARRY, m_Marry);
	//  DDX_Text(pDX, IDC_Gender, m_Gender);
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_Date);
	//  DDX_Text(pDX, IDC_BACK, m_Back);
	//  DDX_Text(pDX, IDC_TITLE, m_Title);
	DDX_Text(pDX, IDC_tName, m_Name);
	//  DDX_CBString(pDX, IDC_BACK, m_BACK);
	//  DDX_Control(pDX, IDC_Gender, m_GENDER);
	DDX_CBString(pDX, IDC_BACK, m_Back);
	DDX_CBString(pDX, IDC_Gender, m_Gender);
	DDX_CBString(pDX, IDC_MARRY, m_Marry);
	DDX_CBString(pDX, IDC_TITLE, m_Title);
}


BEGIN_MESSAGE_MAP(CtSignupDlg, CDialogEx)

END_MESSAGE_MAP()


// tSignupDlg 消息处理程序


