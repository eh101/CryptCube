#pragma once



// CHashSHAForm ������ͼ
#include "Form.h"
class CHashSHAForm : public CForm
{
	DECLARE_DYNCREATE(CHashSHAForm)

public:
	CHashSHAForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CHashSHAForm();

public:
	enum { IDD = IDD_HASH_SHA };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


