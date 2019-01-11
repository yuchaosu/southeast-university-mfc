// CalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "CalDlg.h"
#include "afxdialogex.h"


// CalDlg 对话框

IMPLEMENT_DYNAMIC(CalDlg, CDialogEx)

CalDlg::CalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CalDlg::IDD, pParent)
{

	//  m_Input = _T("");
	//  m_Output = _T("");
}

CalDlg::~CalDlg()
{
}

void CalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_INPUT, m_Input);
	//  DDX_Text(pDX, IDC_OUTPUT, m_Output);
}


BEGIN_MESSAGE_MAP(CalDlg, CDialogEx)

	ON_BN_CLICKED(IDC_CAL, &CalDlg::OnBnClickedCal)
END_MESSAGE_MAP()


// CalDlg 消息处理程序




void CalDlg::OnBnClickedCal()
{
	CString Str;
	GetDlgItemText(IDC_INPUT,Str);
	float Val=GetResult(Str);
	Str.Format(_T("%f"),Val);
	SetDlgItemText(IDC_OUTPUT,Str);// TODO: 在此添加控件通知处理程序代码
}


float CalDlg::GetResult(CString Str)
{
	
	CString LStr, RStr;
	char Oper = FindOper(Str, LStr, RStr);
	if(Oper == '+')
	{
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))>0)
			return GetResult(LStr) + GetResult(RStr);
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))>0)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("), _T(""));
			return _ttof(LStr.GetBuffer(20)) + GetResult(RStr);
		}
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("),_T(""));
			return  GetResult(LStr) + _ttof(RStr.GetBuffer(20));
		}
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("),_T(""));
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("), _T(""));
			return  _ttof(LStr.GetBuffer(20)) + _ttof(RStr.GetBuffer(20));
		}
	}
	else if (Oper == '-')
	{
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))>0)
			return GetResult(LStr) - GetResult(RStr);
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))>0)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("), _T(""));
			return _ttof(LStr.GetBuffer(20)) - GetResult(RStr);
		}
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("),_T(""));
			return  GetResult(LStr) - _ttof(RStr.GetBuffer(20));
		}
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("),_T(""));
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("), _T(""));
			return  _ttof(LStr.GetBuffer(20)) - _ttof(RStr.GetBuffer(20));
		}
	}
	else if(Oper == '*')
	{
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))>0)
			return GetResult(LStr) * GetResult(RStr);
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))>0)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("), _T(""));
			return _ttof(LStr.GetBuffer(20)) * GetResult(RStr);
		}
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("),_T(""));
			return  GetResult(LStr) * _ttof(RStr.GetBuffer(20));
		}
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("),_T(""));
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("), _T(""));
			return  _ttof(LStr.GetBuffer(20)) * _ttof(RStr.GetBuffer(20));
		}
	}
	else if(Oper == '/')
	{
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))>0)
			return GetResult(LStr) / GetResult(RStr);
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))>0)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("), _T(""));
			return _ttof(LStr.GetBuffer(20)) / GetResult(RStr);
		}
		if(LStr.FindOneOf(_T("+-*/"))>0 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("),_T(""));
			return  GetResult(LStr) / _ttof(RStr.GetBuffer(20));
		}
		if(LStr.FindOneOf(_T("+-*/"))==-1 && RStr.FindOneOf(_T("+-*/"))==-1)
		{
			LStr.Replace(_T("("), _T(""));
			LStr.Replace(_T("("),_T(""));
			RStr.Replace(_T("("), _T(""));
			RStr.Replace(_T("("), _T(""));
			return  _ttof(LStr.GetBuffer(20)) / _ttof(RStr.GetBuffer(20));
		}
	}
	else return _ttof(Str.GetBuffer(20));
}



char CalDlg::FindOper(CString Str, CString& LStr, CString& RStr)
{
	int carrier = 1;
	int a[100]={0};
	for(int i=0; i<Str.GetLength(); i++)
	{
		if(Str[i]=='(')
			{
				carrier +=2;
				a[i]=0;
			}
		else if(Str[i]==')')
			{
				carrier -=2;
				a[i]=0;
			}
		else if(Str[i]=='-' || Str[i]=='+')
			a[i]=carrier;
		else if(Str[i]=='*' || Str[i]=='/')
			a[i]=carrier+1;
		else a[i]=0;
	}



	for (int j =1; j <= 30; j++)
	{
		for (int i = 0; i<Str.GetLength(); i++)
		{
			if (a[i] == j)
			{
				LStr = Str.Left(i);
				RStr = Str.Right(Str.GetLength()-i-1);
				return Str[i];
			}
		}
	}

	return 0;
	
}


