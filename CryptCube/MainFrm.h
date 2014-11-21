// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// MainFrm.h : CMainFrame 类的接口
//

#pragma once

#include "RibbonBar.h"  

class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
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

// 操作
public:
	void SwitchToForm(int nForm);

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnGetMinMaxInfo( MINMAXINFO FAR* lpMMI );

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CKofMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;

// 生成的消息映射函数
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


