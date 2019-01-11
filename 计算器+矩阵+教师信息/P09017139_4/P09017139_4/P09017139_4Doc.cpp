
// P09017139_4Doc.cpp : CP09017139_4Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "P09017139_4.h"
#endif
#include"tSignupDlg.h"
#include "P09017139_4Doc.h"
#include"cSignupDlg.h"
#include"SearchDlg.h"
#include <propkey.h>
#include"CalDlg.h"
#include"NewDlg.h"
#include"Matrix.h"
#include"CSearchDlg.h"
#include"MatrixNumDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CP09017139_4Doc

IMPLEMENT_DYNCREATE(CP09017139_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CP09017139_4Doc, CDocument)
	ON_COMMAND(ID_IPUT_tSIGNUP, &CP09017139_4Doc::OnIputtsignup)
	ON_COMMAND(ID_INPUT_SIGNUP, &CP09017139_4Doc::OnInputcSignup)
	ON_COMMAND(ID_CAL, &CP09017139_4Doc::OnCal)
	ON_COMMAND(ID_EditTeacher, &CP09017139_4Doc::OnEditteacher)
	ON_COMMAND(ID_DELETE, &CP09017139_4Doc::OnDelete)
	ON_COMMAND(ID_NEW, &CP09017139_4Doc::OnNew)
	ON_COMMAND(ID_cDELETE, &CP09017139_4Doc::Oncdelete)
	ON_COMMAND(ID_EditClass, &CP09017139_4Doc::OnEditClass)
END_MESSAGE_MAP()


// CP09017139_4Doc 构造/析构

CP09017139_4Doc::CP09017139_4Doc()
{
	// TODO: 在此添加一次性构造代码

}

CP09017139_4Doc::~CP09017139_4Doc()
{
}

BOOL CP09017139_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CP09017139_4Doc 序列化

void CP09017139_4Doc::Serialize(CArchive& ar)
{
	mTeacherArray.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CP09017139_4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CP09017139_4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CP09017139_4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CP09017139_4Doc 诊断

#ifdef _DEBUG
void CP09017139_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CP09017139_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CP09017139_4Doc 命令


void CP09017139_4Doc::OnIputtsignup()
{
	CtSignupDlg Dlg;
	if(Dlg.DoModal() == IDOK)
	{
		CTeacher* pTeacher = new CTeacher;
		//用new生成CSportMan对象
        pTeacher->tBirth = Dlg.m_Date;
		pTeacher->tID = Dlg.m_tID;
		pTeacher->tName = Dlg.m_Name;
		pTeacher->tGender = Dlg.m_Gender;
		pTeacher->tBack = Dlg.m_Back;
		pTeacher->tTitle = Dlg.m_Title;
		pTeacher->tSalary = Dlg.m_Salary;
		pTeacher->tMarry = Dlg.m_Marry;
		mTeacherArray.Add(pTeacher);
	}

// TODO: 在此添加命令处理程序代码
}


void CP09017139_4Doc::OnInputcSignup()
{
	SearchDlg Dlg;
	Dlg.p=this;
	if(Dlg.DoModal()==IDOK)
	{
		CTeacher* pTeacher = new CTeacher;
		for(int i=0; i<mTeacherArray.GetSize();i++)
		{
			pTeacher = mTeacherArray[i];
			if(pTeacher->tName==Dlg.m_Name1)
			{
				cSignupDlg ItemDlg;
				if(ItemDlg.DoModal()==IDOK)
				{
					CClass* pItem = new CClass;
					pItem->cID = ItemDlg.m_ID;
					pItem->cName = ItemDlg.m_Name;
					pItem->cTime = ItemDlg.m_Time;
					pItem->cRoom = ItemDlg.m_Room;
					pItem->cClass = ItemDlg.m_Class;
					pItem->cCode = ItemDlg.m_Code;
					pItem->cSemester = ItemDlg.m_Semester;
					pTeacher->tClassArray.Add(pItem);
					return;
				}
			}
		}
	}
}

	
	
void CP09017139_4Doc::OnCal()
{
	CalDlg Dlg;
	Dlg.DoModal();// TODO: 在此添加命令处理程序代码
}


void CP09017139_4Doc::OnEditteacher()
{
	SearchDlg IDDlg;  
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //上面两行代码用来获取m_ID的值
{
	CTeacher* pTeacher = NULL;
	for(int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_Name1) //根据m_ID查找对象
	{  //找到要修改的对象了
		CtSignupDlg Dlg; //下面5行代码让对话框显示修改前的信息
		Dlg.m_tID = pTeacher->tID;
        Dlg.m_Name = pTeacher->tName;
        Dlg.m_Date = pTeacher->tBirth;
        Dlg.m_Salary = pTeacher->tSalary;
        Dlg.m_Gender = pTeacher->tGender;
		Dlg.m_Back = pTeacher->tBack;
		Dlg.m_Title = pTeacher->tTitle;
		Dlg.m_Marry = pTeacher->tMarry;
		if(Dlg.DoModal() == IDOK) //下面的代码完成修改
		{
            pTeacher->tBirth = Dlg.m_Date;
		    pTeacher->tID = Dlg.m_tID;
		    pTeacher->tName = Dlg.m_Name;
		    pTeacher->tGender = Dlg.m_Gender;
		    pTeacher->tBack = Dlg.m_Back;
		    pTeacher->tTitle = Dlg.m_Title;
		    pTeacher->tSalary = Dlg.m_Salary;
		    pTeacher->tMarry = Dlg.m_Marry;
			//以上4行修改数据，只需重新赋值就行了，ID不要赋值
			return; //修改结束，退出程序；
         }
         AfxMessageBox(_T("查到教师，但按了取消按钮！"));
         return;
     }
}
AfxMessageBox(_T("按提供的ID号，没查到教师！"));
	return;
}
AfxMessageBox(_T( "不想提供ID号了！"));
}



void CP09017139_4Doc::OnDelete()
{
	
	SearchDlg IDDlg; 
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //上面两行代码用来获取m_ID的值
{
	CTeacher* pTeacher = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_Name1) //根据m_ID查找对象
	{ 
		mTeacherArray.RemoveAt(i);//找到要修改的对象了
	}
	return;
}
AfxMessageBox(_T( "不想提供ID号了！"));// TODO: 在此添加命令处理程序代码
}
}


void CP09017139_4Doc::Oncdelete()
{
	CCSearchDlg IDDlg; 
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //上面两行代码用来获取m_ID的值
{
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_CTName1) //根据m_ID查找对象
	{ 
		for( int j = 0; j<pTeacher->tClassArray.GetSize();j++)
		{
			pClass=pTeacher->tClassArray[j];
			if(pClass->cName==IDDlg.m_cName1)
				pTeacher->tClassArray.RemoveAt(j);//找到要修改的对象了
			else
				AfxMessageBox(_T( "未查到课程！"));return;
		}
	}
}
}
else
	AfxMessageBox(_T( "未查到教师！"));return;// TODO: 在此添加命令处理程序代码
}


void CP09017139_4Doc::OnNew()
{
	NewDlg Dlg;
	Dlg.m_mCol = 2;
	Dlg.m_mRow = 3;
	if(Dlg.DoModal()==IDOK)
	{
		if(Dlg.m_Mat2)
			mMat2.Create(Dlg.m_mRow,Dlg.m_mCol);
		else
			mMat1.Create(Dlg.m_mRow,Dlg.m_mCol);
	}// TODO: 在此添加命令处理程序代码
}






void CP09017139_4Doc::OnEditClass()
{
	CCSearchDlg IDDlg;  
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //上面两行代码用来获取m_ID的值
{
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_CTName1) //根据m_ID查找对象
	{ 
		for( int j = 0; j<pTeacher->tClassArray.GetSize();j++)
		{
			pClass=pTeacher->tClassArray[j];
			if(pClass->cName==IDDlg.m_cName1)
			{
				cSignupDlg Dlg1;
				    Dlg1.m_ID=pClass->cID;
					Dlg1.m_Name=pClass->cName;
					Dlg1.m_Time=pClass->cTime;
					Dlg1.m_Room=pClass->cRoom  ;
					Dlg1.m_Class=pClass->cClass ;
					Dlg1.m_Code=pClass->cCode;
					Dlg1.m_Semester=pClass->cSemester;
					if(Dlg1.DoModal()==IDOK)
					{
						pClass->cID = Dlg1.m_ID;
					pClass->cName = Dlg1.m_Name;
					pClass->cTime = Dlg1.m_Time;
					pClass->cRoom = Dlg1.m_Room;
					pClass->cClass = Dlg1.m_Class;
					pClass->cCode = Dlg1.m_Code;
					pClass->cSemester = Dlg1.m_Semester;
					}

			}//找到要修改的对象了
			else
				AfxMessageBox(_T( "未查到课程！"));return;
		}
	}
	else
	AfxMessageBox(_T( "未查到教师！"));return;
}
}
AfxMessageBox(_T( "不想提供ID号了！"));// TODO: 在此添加命令处理程序代码
}
