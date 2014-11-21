// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#include "RibbonBar.h"  

class CMainFrame : public CFrameWndEx
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

	//CString m_strClassicKaisa;
	//CString m_strClassicDaihuan;
	//CString m_strBlockDES;
	//CString m_strBlockAES;
	//CString m_strStreamRC4;
	//CString m_strPublicKeyRSA;
	//CString m_strPublicKeyDH;
	//CString m_strPublicKeyElGamal;
	//CString m_strPublicKeyECC;
	//CString m_strHashMD5;
	//CString m_strHashSHAForm;
	//CString m_strSignatureDSA;

// ����
public:
	void SwitchToForm(int nForm);

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnGetMinMaxInfo( MINMAXINFO FAR* lpMMI );

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CKofMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	void InitializeRibbon();
	BOOL CreateCaptionBar();
public:
	afx_msg void OnAppAbout();
	afx_msg void OnClassicKaisa();
	afx_msg void OnClassicDaihuan();
	afx_msg void OnBlockDes();
	afx_msg void OnBlockAes();
	afx_msg void OnBlockIdea();
	afx_msg void OnStreamRc4();
	afx_msg void OnPublickeyRsa();
	afx_msg void OnPublickeyElgamal();
	afx_msg void OnHashMd5();
	afx_msg void OnHashSha();
	afx_msg void OnWelcome();
	afx_msg void OnPublickeyDh();
	afx_msg void OnPublickeyEcc();
	afx_msg void OnAppDonate();
	afx_msg void OnAppWebsite();
	afx_msg void OnSignatureDsa();
	afx_msg void OnCodeRandom();
	afx_msg void OnEncryptString();
	afx_msg void OnCodeCalc();
	afx_msg void OnEncryptFile();
	afx_msg void OnCodeHash();
	afx_msg void OnCodeBase64();
	afx_msg void OnCodeString();
	afx_msg void OnCodeUrl();
	afx_msg void OnCodeColor();
	afx_msg void OnCodeQr();
	afx_msg void OnAppHelp();
};


