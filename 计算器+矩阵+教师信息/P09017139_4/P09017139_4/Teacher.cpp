#include "StdAfx.h"
#include "Teacher.h"


CTeacher::CTeacher(void)
	: tID(0)
	, tName(_T(""))
	, tGender(_T(""))
	, tBirth(COleDateTime::GetCurrentTime())
	, tBack(_T(""))
	, tTitle(_T(""))
	, tSalary(0)
	, tMarry(_T(""))
{
}
IMPLEMENT_SERIAL(CTeacher,CObject,0)

CTeacher::~CTeacher(void)
{
}


void CTeacher::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar << tID;
		ar << tName;
		ar << tGender;
        ar << tBirth;
		ar << tBack;
		ar << tTitle;
		ar << tSalary;
		ar << tMarry;

	}
	else
	{
		ar >> tID;
		ar >> tName;
		ar >> tGender;
        ar >> tBirth;
		ar >> tBack;
		ar >> tTitle;
		ar >> tSalary;
		ar >> tMarry;
	}
	tClassArray.Serialize(ar);

}
