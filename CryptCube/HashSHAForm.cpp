// HashSHA1Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSHAForm.h"


// CHashSHAForm

IMPLEMENT_DYNCREATE(CHashSHAForm, CForm)

CHashSHAForm::CHashSHAForm()
	: CForm(CHashSHAForm::IDD)
{

}

CHashSHAForm::~CHashSHAForm()
{
}

void CHashSHAForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHashSHAForm, CForm)
END_MESSAGE_MAP()


// CHashSHAForm ���

#ifdef _DEBUG
void CHashSHAForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CHashSHAForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CHashSHAForm ��Ϣ�������
