#pragma once



// CPublicKeyECCForm 窗体视图
#include "Form.h"

#include "PublicKeyECC.h"

class CPublicKeyECCForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyECCForm)

public:
	CPublicKeyECCForm();           // 动态创建所使用的受保护的构造函数
	virtual ~CPublicKeyECCForm();

public:
	enum { IDD = IDD_PUBLICKEY_ECC };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	LRESULT  OnUpdateMyData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:

	static UINT InitComboBox(LPVOID param);
	CString m_strComboA;
	CComboBox m_ctrlComboA;
	CString m_strComboB;
	CComboBox m_ctrlComboB;
	CString m_strComboQ;
	CComboBox m_ctrlComboQ;


	ECC *m_pECC;

	// 多线程标志
	BOOL m_bInThread;
};


