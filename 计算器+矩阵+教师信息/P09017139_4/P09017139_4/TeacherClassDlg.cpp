// TeacherClassDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "TeacherClassDlg.h"
#include "afxdialogex.h"


// CTeacherClassDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherClassDlg, CDialogEx)

CTeacherClassDlg::CTeacherClassDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherClassDlg::IDD, pParent)
{

	m_ClassADate = COleDateTime::GetCurrentTime();
	//  m_ClassBack = _T("");
	m_ClassBDate = COleDateTime::GetCurrentTime();
	//  m_ClassGender = _T("");
	//  m_ClassMarry = _T("");
	//  m_ClassTitle = _T("");
	m_Flag = 0;
	m_ClassBack = _T("");
	m_ClassGender = _T("");
	m_ClassMarry = _T("");
	m_ClassTitle = _T("");
}

CTeacherClassDlg::~CTeacherClassDlg()
{
}

void CTeacherClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_ClassADate, m_ClassADate);
	//  DDX_Text(pDX, IDC_ClassBack, m_ClassBack);
	DDX_DateTimeCtrl(pDX, IDC_ClassBDate, m_ClassBDate);
	//  DDX_Text(pDX, IDC_ClassGender, m_ClassGender);
	//  DDX_Text(pDX, IDC_ClassMarry, m_ClassMarry);
	//  DDX_Text(pDX, IDC_ClassTitle, m_ClassTitle);
	DDX_Radio(pDX, IDC_RADIO1, m_Flag);
	DDX_CBString(pDX, IDC_ClassBack, m_ClassBack);
	DDX_CBString(pDX, IDC_ClassGender, m_ClassGender);
	DDX_CBString(pDX, IDC_ClassMarry, m_ClassMarry);
	DDX_CBString(pDX, IDC_ClassTitle, m_ClassTitle);
}


BEGIN_MESSAGE_MAP(CTeacherClassDlg, CDialogEx)
END_MESSAGE_MAP()



