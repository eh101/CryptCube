// HashMD5Form.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashMD5Form.h"

#include "CStringConvert.h"
// CHashMD5Form

IMPLEMENT_DYNCREATE(CHashMD5Form, CForm)

CHashMD5Form::CHashMD5Form()
	: CForm(CHashMD5Form::IDD)
	, m_stateRadioAnsi(FALSE)
{

}

CHashMD5Form::~CHashMD5Form()
{
}

void CHashMD5Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PLAINTEXT, m_strPlainText);
	DDX_Text(pDX, IDC_EDIT_CIPHERTEXT_HEX, m_strCipherTextHex);
	DDX_Radio(pDX, IDC_RADIO_ANSI, m_stateRadioAnsi);
	DDX_Control(pDX, IDC_EDIT_PLAINTEXT, m_ctrlPlainText);
}

BEGIN_MESSAGE_MAP(CHashMD5Form, CForm)
	ON_EN_CHANGE(IDC_EDIT_PLAINTEXT, &CHashMD5Form::OnEnChangeEditPlaintext)
	ON_BN_CLICKED(IDC_RADIO_ANSI, &CHashMD5Form::OnBnClickedRadioAnsi)
	ON_BN_CLICKED(IDC_RADIO_UNICODE, &CHashMD5Form::OnBnClickedRadioUnicode)
END_MESSAGE_MAP()


// CHashMD5Form ���

#ifdef _DEBUG
void CHashMD5Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CHashMD5Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG



void CHashMD5Form::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();


	// ��ʼ����ɱ�־λ
	m_bInitControl= TRUE;

}


// CHashMD5Form ��Ϣ�������




// �����������ַ�����
BOOL CHashMD5Form::PreTranslateMessage(MSG* pMsg)
{

	if(WM_CHAR == pMsg->message)
	{
		////////////////////////////////////////////////��������� /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_PLAINTEXT)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//�Ƿ�������
			const unsigned int chCharCode =  pMsg->wParam;  


			//�����û���������ɾ����,�ʲ�����
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//���ѡ��ȫ��,������������
			int nStart,nEnd;
			m_ctrlPlainText.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strPlainText.GetLength())
				bDo = false ;


			//���������Ŀ�������ֽ���
			CString strPlainChar;
			strPlainChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI��ʽ��������48���ֽ�
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 48)//len -1 ���ǳ���
					bDo = false;	
			}
			else
			{
				// Unicode��ʽ��������24���ַ�
				if(CStrT2CStrW(m_strPlainText).GetLength()+CStrT2CStrW(strPlainChar).GetLength() <= 24)
					bDo = false;	
			}

			if(bDo)
				return true;

		}


	}

	return CForm::PreTranslateMessage(pMsg);
}





void CHashMD5Form::OnEnChangeEditPlaintext()
{
	UpdateData(TRUE);

	//// �жϱ��뷽ʽ
	//if(FALSE == m_stateRadioAnsi)
	//{
	//	// ANSI��ʽ

	//	// ����ANSI��ʽ��ʮ�����Ʊ���
	//	m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	//}
	//else
	//{
	//	// Unicode��ʽ

	//	//����Unicode��ʽ��ʮ�����Ʊ���
	//	m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	//}

	//UpdateData(FALSE);

    // �ж����ĺ���Կ�Ƿ�Ϊ�գ�Ϊ���򲻼��㡣
	if((!m_strPlainText.GetLength())) 
	{

		m_strCipherTextHex.Empty();

		UpdateData(FALSE);
		return;
	}

	DoEncrypt();
}


void CHashMD5Form::DoEncrypt()
{

	// ˢ�¿ؼ��ĳ�Ա����
	UpdateData(TRUE);


	m_pMD5 = new MD5();

	// ���ַ���ת����ʮ������
	if(FALSE == m_stateRadioAnsi)
	{

		// ��ANSI��ʽ��ת�������ַ���Ϊʮ������
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrA(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
	}
	else
	{
		// ��Unicode��ʽ��ת�������ַ���Ϊʮ������
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrW(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
	}



	




	UpdateData(FALSE);

}

void CHashMD5Form::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// �жϱ��뷽ʽ
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI��ʽ

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();

	}
	else
	{
		// Unicode��ʽ

		//ѡ��Unicode��ʽ����ȡ������ַ�Ϊ24��
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(24)) ;
		UpdateData(FALSE);

		// ���¼���ʮ�����Ƶ�ֵ
		OnEnChangeEditPlaintext();
	}
}

void CHashMD5Form::OnBnClickedRadioUnicode()
{
	// �͵�����ANSIʱ��ͬ�Ĳ���
	OnBnClickedRadioAnsi();
}
