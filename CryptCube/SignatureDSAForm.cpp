// SignatureDSAForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "SignatureDSAForm.h"


// CSignatureDSAForm

IMPLEMENT_DYNCREATE(CSignatureDSAForm, CForm)

CSignatureDSAForm::CSignatureDSAForm()
	: CForm(CSignatureDSAForm::IDD)
{

}

CSignatureDSAForm::~CSignatureDSAForm()
{
}

void CSignatureDSAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSignatureDSAForm, CForm)
END_MESSAGE_MAP()


// CSignatureDSAForm 诊断

#ifdef _DEBUG
void CSignatureDSAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CSignatureDSAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CSignatureDSAForm 消息处理程序
