// HashMD5Form.cpp : 实现文件
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


// CHashMD5Form 诊断

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


	// 初始化完成标志位
	m_bInitControl= TRUE;

}


// CHashMD5Form 消息处理程序




// 限制输入框的字符长度
BOOL CHashMD5Form::PreTranslateMessage(MSG* pMsg)
{

	if(WM_CHAR == pMsg->message)
	{
		////////////////////////////////////////////////明文输入框 /////////////////////////////////////////////
		if(GetDlgItem(IDC_EDIT_PLAINTEXT)->GetSafeHwnd() == pMsg->hwnd)
		{

			UpdateData(TRUE);

			bool bDo = true;//是否作处理
			const unsigned int chCharCode =  pMsg->wParam;  


			//允许用户输入两种删除键,故不处理
			if(chCharCode == VK_DELETE || chCharCode == VK_BACK)
				bDo = false;

			//如果选中全部,可以任意输入
			int nStart,nEnd;
			m_ctrlPlainText.GetSel(nStart,nEnd);
			if(0 == nStart && nEnd == m_strPlainText.GetLength())
				bDo = false ;


			//处理输入框的可输入的字节数
			CString strPlainChar;
			strPlainChar.Format(_T("%c"),chCharCode); 	

			if(FALSE == m_stateRadioAnsi)
			{
				// ANSI方式允许输入48个字节
				if(CStrT2CStrA(m_strPlainText).GetLength()+CStrT2CStrA(strPlainChar).GetLength() <= 48)//len -1 才是长度
					bDo = false;	
			}
			else
			{
				// Unicode方式允许输入24个字符
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

	//// 判断编码方式
	//if(FALSE == m_stateRadioAnsi)
	//{
	//	// ANSI方式

	//	// 计算ANSI方式的十六进制编码
	//	m_strPlainTextHex = Text2AnsiHex(m_strPlainText);

	//}
	//else
	//{
	//	// Unicode方式

	//	//计算Unicode方式的十六进制编码
	//	m_strPlainTextHex = Text2UnicodeHex(m_strPlainText);
	//}

	//UpdateData(FALSE);

    // 判断明文和密钥是否为空，为空则不计算。
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

	// 刷新控件的成员变量
	UpdateData(TRUE);


	m_pMD5 = new MD5();

	// 将字符串转换成十六进制
	if(FALSE == m_stateRadioAnsi)
	{

		// 以ANSI方式的转换密文字符串为十六进制
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrA(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
	}
	else
	{
		// 以Unicode方式的转换密文字符串为十六进制
		m_strCipherTextHex = m_pMD5->GetMD5( (BYTE*)(const char*)CStrT2CStrW(m_strPlainText).GetBuffer(), m_strPlainText.GetLength() );
	}



	




	UpdateData(FALSE);

}

void CHashMD5Form::OnBnClickedRadioAnsi()
{
	UpdateData(TRUE);


	// 判断编码方式
	if(FALSE == m_stateRadioAnsi)
	{
		// ANSI方式

		// 重新计算十六进制的值
		OnEnChangeEditPlaintext();

	}
	else
	{
		// Unicode方式

		//选中Unicode方式，截取输入框字符为24个
		m_strPlainText = CStrW2CStrT(CStrT2CStrW(m_strPlainText).Left(24)) ;
		UpdateData(FALSE);

		// 重新计算十六进制的值
		OnEnChangeEditPlaintext();
	}
}

void CHashMD5Form::OnBnClickedRadioUnicode()
{
	// 和点击点击ANSI时相同的操作
	OnBnClickedRadioAnsi();
}
