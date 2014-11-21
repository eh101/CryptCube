// CodeHashForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeHashForm.h"
#include "CStringConvert.h"

//���ø����㷨���б���λ��
#define HASH_MD5		0
#define HASH_CRC32		1
#define HASH_SHA1		2
#define HASH_SHA256		3
#define HASH_SHA512		4

// CCodeHashForm

IMPLEMENT_DYNCREATE(CCodeHashForm, CForm)

CCodeHashForm::CCodeHashForm()
	: CForm(CCodeHashForm::IDD)
	, m_strFilePath(_T(""))
{

}

CCodeHashForm::~CCodeHashForm()
{
}

void CCodeHashForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HASH, m_ctrlListHash);
	DDX_Text(pDX, IDC_EDIT_FILE_PATH, m_strFilePath);
	DDV_MaxChars(pDX, m_strFilePath, 255);
}

BEGIN_MESSAGE_MAP(CCodeHashForm, CForm)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CCodeHashForm::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// CCodeHashForm ���

#ifdef _DEBUG
void CCodeHashForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeHashForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeHashForm ��Ϣ�������

void CCodeHashForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	InitListCtrl();
}


void CCodeHashForm::InitListCtrl()
{
	m_ctrlListHash.SetExtendedStyle(LVS_EX_CHECKBOXES);
	LONG lStyle = m_ctrlListHash.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	m_ctrlListHash.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);

	
	m_ctrlListHash.InsertColumn(0,_T("�㷨����"),LVCFMT_CENTER,80,-1);
	m_ctrlListHash.InsertColumn(1,_T("��ϣֵ"),LVCFMT_CENTER,500,-1);


    m_ctrlListHash.InsertItem(HASH_MD5, _T("MD5"));
    m_ctrlListHash.SetCheck(HASH_MD5, TRUE);
	m_ctrlListHash.SetItemText(HASH_MD5,1,_T(""));

    m_ctrlListHash.InsertItem(HASH_CRC32, _T("CRC32"));
    m_ctrlListHash.SetCheck(HASH_CRC32, TRUE);
	m_ctrlListHash.SetItemText(HASH_CRC32,1,_T(""));
 
    m_ctrlListHash.InsertItem(HASH_SHA1, _T("SHA1"));
    m_ctrlListHash.SetCheck(HASH_SHA1, TRUE);
	m_ctrlListHash.SetItemText(HASH_SHA1,1,_T(""));

	m_ctrlListHash.InsertItem(HASH_SHA256, _T("SHA256"));
    m_ctrlListHash.SetCheck(HASH_SHA256, TRUE);
	m_ctrlListHash.SetItemText(HASH_SHA256,1,_T(""));

    m_ctrlListHash.InsertItem(HASH_SHA512, _T("SHA512"));
    m_ctrlListHash.SetCheck(HASH_SHA512, TRUE);
	m_ctrlListHash.SetItemText(HASH_SHA512,1,_T(""));



}

void CCodeHashForm::OnDropFiles(HDROP hDropInfo) 
{
	UpdateData();
    TCHAR szFileName[255];
    ZeroMemory(szFileName,255);
    DragQueryFile(hDropInfo,0,szFileName,254);
    if(lstrlen(szFileName)!=0 && PathIsDirectory(szFileName) == FALSE)
    {
        m_strFilePath=szFileName;
		UpdateData(FALSE);
		DoHash();
		
    }
    DragFinish(hDropInfo); 
	
	
	
}
void CCodeHashForm::OnBnClickedButtonOpen()
{
	CFileDialog* pFileDialog = new CFileDialog(TRUE,NULL,NULL,OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_READONLY,
       _T("�����ļ�(*.*)|*.*||"),this);

	pFileDialog->m_ofn.lpstrTitle = _T("��Ҫ�����ϣֵ���ļ�");

	//���ļ����桱�Ի�������ʾ
	if (pFileDialog->DoModal() == IDOK)
	{
		m_strFilePath = pFileDialog->GetPathName();
		UpdateData(FALSE);
		DoHash();
	}

	delete 	pFileDialog;
}

void CCodeHashForm::DoHash()
{
	UpdateData();
	if(PathFileExists(m_strFilePath) && !PathIsDirectory(m_strFilePath))
	{

		BOOL bCheckMD5 = m_ctrlListHash.GetCheck(HASH_MD5);
		BOOL bCheckCRC32 = m_ctrlListHash.GetCheck(HASH_CRC32);
		BOOL bCheckSHA1 = m_ctrlListHash.GetCheck(HASH_SHA1);
		BOOL bCheckSHA256 = m_ctrlListHash.GetCheck(HASH_SHA256);
		BOOL bCheckSHA512 = m_ctrlListHash.GetCheck(HASH_SHA512);

		if(bCheckMD5) 
			CWinThread *pMD5GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashMD5,this);
		if(bCheckCRC32)
			CWinThread *pCRC32GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashCRC32,this);
		if(bCheckSHA1) 
			CWinThread *pSHA1GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA1,this);
		if(bCheckSHA256) 
			CWinThread *pSHA256GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA256,this);
		if(bCheckSHA512) 
			CWinThread *pSHA512GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA512,this);

	}

}

UINT CCodeHashForm::DoHashMD5(LPVOID param)
{
	//�õ�Formָ�롣
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;

	pThisForm->m_ctrlListHash.SetItemText(HASH_MD5,1,GetFileHashMD5(pThisForm->m_strFilePath));

	return 0;
}

UINT CCodeHashForm::DoHashCRC32(LPVOID param)
{
	//�õ�Formָ�롣
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	pThisForm->m_ctrlListHash.SetItemText(HASH_CRC32,1,GetFileHashCRC32(pThisForm->m_strFilePath));


	return 0;
}


UINT CCodeHashForm::DoHashSHA1(LPVOID param)
{
	//�õ�Formָ�롣
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA1,1,GetFileHashSHA1(pThisForm->m_strFilePath));



	return 0;
}


UINT CCodeHashForm::DoHashSHA256(LPVOID param)
{
	//�õ�Formָ�롣
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA256,1,GetFileHashSHA256(pThisForm->m_strFilePath));



	return 0;
}


UINT CCodeHashForm::DoHashSHA512(LPVOID param)
{
	//�õ�Formָ�롣
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	pThisForm->m_strFilePath;
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA512,1,GetFileHashSHA512(pThisForm->m_strFilePath));

	return 0;
}