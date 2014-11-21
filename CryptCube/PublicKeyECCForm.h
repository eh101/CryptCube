#pragma once



// CPublicKeyECCForm ������ͼ
#include "Form.h"

#include "PublicKeyECC.h"

class CPublicKeyECCForm : public CForm
{
	DECLARE_DYNCREATE(CPublicKeyECCForm)

public:
	CPublicKeyECCForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
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

	// ���̱߳�־
	BOOL m_bInThread;
};


