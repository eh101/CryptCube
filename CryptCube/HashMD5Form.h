#pragma once



// CHashMD5Form ������ͼ
#include "Form.h"

#include "HashMD5.h"
#include "afxwin.h"

class CHashMD5Form : public CForm
{
	DECLARE_DYNCREATE(CHashMD5Form)

public:
	CHashMD5Form();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
public:
	// ANSI���뷽ʽ
	BOOL m_stateRadioAnsi;

	// �����ַ���ʮ������
	CString m_strCipherTextHex;
	// �����ַ���
	CString m_strPlainText;
	// �����ַ���ʮ������
	CString m_strPlainTextHex;

	BOOL m_bInitControl;
	afx_msg void OnEnChangeEditPlaintext();
	void DoEncrypt();
	afx_msg void OnBnClickedRadioAnsi();
	afx_msg void OnBnClickedRadioUnicode();
	CEdit m_ctrlPlainText;

	MD5 *m_pMD5;
};


