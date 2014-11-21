// CodeCalcForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeCalcForm.h"


// CCodeCalcForm

IMPLEMENT_DYNCREATE(CCodeCalcForm, CForm)

CCodeCalcForm::CCodeCalcForm()
	: CForm(CCodeCalcForm::IDD)
{

}

CCodeCalcForm::~CCodeCalcForm()
{
}

void CCodeCalcForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeCalcForm, CForm)
END_MESSAGE_MAP()


// CCodeCalcForm 诊断

#ifdef _DEBUG
void CCodeCalcForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeCalcForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeCalcForm 消息处理程序
