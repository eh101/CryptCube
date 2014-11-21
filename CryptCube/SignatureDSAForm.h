#pragma once

#include "Form.h"

// CSignatureDSAForm 窗体视图

class CSignatureDSAForm : public CForm
{
	DECLARE_DYNCREATE(CSignatureDSAForm)

public:
	CSignatureDSAForm();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


