// PublicKeyECC.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "PublicKeyECCForm.h"


// CPublicKeyECCForm

IMPLEMENT_DYNCREATE(CPublicKeyECCForm, CForm)

CPublicKeyECCForm::CPublicKeyECCForm()
	: CForm(CPublicKeyECCForm::IDD)
{

}

CPublicKeyECCForm::~CPublicKeyECCForm()
{
}

void CPublicKeyECCForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CRTST_A, m_ctrlComboA);
	DDX_CBString(pDX, IDC_CRTST_A, m_strComboA);
	DDX_Control(pDX, IDC_CRTST_B, m_ctrlComboB);
	DDX_CBString(pDX, IDC_CRTST_B, m_strComboB);
	DDX_Control(pDX, IDC_CRTST_Q, m_ctrlComboQ);
	DDX_CBString(pDX, IDC_CRTST_Q, m_strComboQ);
}

BEGIN_MESSAGE_MAP(CPublicKeyECCForm, CForm)
END_MESSAGE_MAP()


// CPublicKeyECCForm 诊断

#ifdef _DEBUG
void CPublicKeyECCForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPublicKeyECCForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPublicKeyECCForm 消息处理程序


void CPublicKeyECCForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();

	m_ctrlComboQ.AddString(_T("127"));
	m_strComboQ=_T("127");
	m_ctrlComboQ.SetCurSel(0);

	m_bInThread=FALSE;

	m_pECC = new ECC();

	CWinThread *pThread= AfxBeginThread((AFX_THREADPROC)InitComboBox,this);// 初始化素数Q、A
	UpdateData(FALSE);	

}


// 多线程方式初始化素数Q、本原元素A下拉框和私钥X的下拉框
UINT CPublicKeyECCForm::InitComboBox(LPVOID param)
{

	srand((unsigned)time(NULL)*1000); 
	CPublicKeyECCForm * pThisForm = (CPublicKeyECCForm *) param; 

	// 开始子线程时禁用下拉框
	pThisForm->m_ctrlComboA.EnableWindow(FALSE);
	pThisForm->m_ctrlComboB.EnableWindow(FALSE);
	pThisForm->m_ctrlComboQ.EnableWindow(FALSE);

	int i= 0;

	// 填充Q下拉框的数据为127-10000的素数
	CString strTemp;
	for(i=131;i<=10000;i++)
	{
		if(pThisForm->m_pECC->testprime(i))
		{
			strTemp.Format(_T("%d"),i);
			pThisForm->m_ctrlComboQ.AddString(strTemp);
		}
	}

	for(i=0;i<=256;i++)
	{
		if(pThisForm->m_pECC->testprime(i))
		{
			strTemp.Format(_T("%d"),i);
			pThisForm->m_ctrlComboA.AddString(strTemp);
			pThisForm->m_ctrlComboB.AddString(strTemp);
		}
	}


//	pThisForm->SetComboBoxAX(127);

//	pThisForm->DoDH();


	// 恢复下拉框
	pThisForm->m_ctrlComboA.EnableWindow(TRUE);
	pThisForm->m_ctrlComboB.EnableWindow(TRUE);
	pThisForm->m_ctrlComboQ.EnableWindow(TRUE);
	return 0; 
}
