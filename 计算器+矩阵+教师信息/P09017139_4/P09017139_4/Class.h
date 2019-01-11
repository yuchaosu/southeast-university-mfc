#pragma once
#include "afx.h"
class CClass :
	public CObject
{
	DECLARE_SERIAL(CClass)
public:
	CClass(void);
	~CClass(void);
	// 课程编号
	int cID;

	// 课程名称
	CString cName;
	// 课时
	int cTime;
	// 教室
	CString cRoom;
	// 授课班级
	int cClass;
	// 学分
	int cCode;
	// 学期
	CString cSemester;
	void Serialize(CArchive& ar);
};

