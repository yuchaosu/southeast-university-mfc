#pragma once
#include "afx.h"
#include "atlcomtime.h"
#include "afxtempl.h"
#include"Class.h"
class CTeacher :
	public CObject
{
	DECLARE_SERIAL(CTeacher) 
public:
	CTeacher(void);
	~CTeacher(void);
	int tID;//编号
	CString tName;//姓名
	CString tGender;//性别
	COleDateTime tBirth;//出生日期
	CString tBack;//最后学历
	CString tTitle;//职称
	int tSalary;//工资
	CString tMarry;//婚姻状况
	
	// 集合类型成员，存放教授的课程
	CTypedPtrArray<CObArray, CClass*> tClassArray;
	void Serialize(CArchive& ar);
};

