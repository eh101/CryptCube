#pragma once

#include "Form.h"

// CSignatureDSAForm ������ͼ

class CSignatureDSAForm : public CForm
{
	DECLARE_DYNCREATE(CSignatureDSAForm)

public:
	CSignatureDSAForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSignatureDSAForm();

public:
	enum { IDD = IDD_SIGNATURE_DSA };
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


