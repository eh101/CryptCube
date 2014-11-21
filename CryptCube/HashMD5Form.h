#pragma once



// CHashMD5Form 窗体视图
#include "Form.h"

#include "HashMD5.h"
#include "afxwin.h"

class CHashMD5Form : public CForm
{
	DECLARE_DYNCREATE(CHashMD5Form)

public:
	CHashMD5Form();           // 动态创建所使用的受保护的构造函数
	virtual ~CHashMD5Form();

public:
	enum { IDD = IDD_HASH_MD5 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
public:
	// ANSI编码方式
	BOOL m_stateRadioAnsi;

	// 密文字符串十六进制
	CString m_strCipherTextHex;
	// 明文字符串
	CString m_strPlainText;
	// 明文字符串十六进制
	CString m_strPlainTextHex;

	BOOL m_bInitControl;
	afx_msg void OnEnChangeEditPlaintext();
	void DoEncrypt();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();
	CEdit m_ctrlPlainText;

	MD5 *m_pMD5;
};


