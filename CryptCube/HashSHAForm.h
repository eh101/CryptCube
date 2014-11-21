#pragma once



// CHashSHAForm 窗体视图
#include "Form.h"
class CHashSHAForm : public CForm
{
	DECLARE_DYNCREATE(CHashSHAForm)

public:
	CHashSHAForm();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


