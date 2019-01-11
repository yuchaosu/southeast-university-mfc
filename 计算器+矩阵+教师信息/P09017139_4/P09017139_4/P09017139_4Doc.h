
// P09017139_4Doc.h : CP09017139_4Doc 类的接口
//


#pragma once
#include "afxtempl.h"
#include"Teacher.h"
#include"Matrix.h"

class CP09017139_4Doc : public CDocument
{
protected: // 仅从序列化创建
	CP09017139_4Doc();
	DECLARE_DYNCREATE(CP09017139_4Doc)

// 特性
public:

	CMatrix<float> mMat1;
	CMatrix<float> mMat2;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CP09017139_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 存放教师
	CTypedPtrArray<CObArray, CTeacher*> mTeacherArray;
	afx_msg void OnIputtsignup();
	afx_msg void OnInputcSignup();
	// 存放课程
	CTypedPtrArray<CObArray, CClass*> mClassArray;


	afx_msg void OnCal();
	afx_msg void OnEditteacher();
	afx_msg void OnDelete();
	afx_msg void OnNew();
	afx_msg void Oncdelete();
	afx_msg void OnEditClass();
};
