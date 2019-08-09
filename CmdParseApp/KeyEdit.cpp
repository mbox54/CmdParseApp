// KeyEdit.cpp 

// implementation file


#include "pch.h"
#include "framework.h"

#include "CmdParseApp.h"
#include "CmdParseDlg.h"

#include "KeyEdit.h"


////////////////////////////////////////////////////////////////////////////////
// CKeyEdit
////////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CKeyEdit, CEdit)

CKeyEdit::CKeyEdit()
{

}

CKeyEdit::~CKeyEdit()
{
}


////////////////////////////////////////////////////////////////////////////////
// MESSAGE_MAP
////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CKeyEdit, CEdit)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


////////////////////////////////////////////////////////////////////////////////
// CKeyEdit message handlers
void CKeyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RETURN)
		return;


	CEdit::OnChar(nChar, nRepCnt, nFlags);
}


void CKeyEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RETURN)
	{
		// ������������, ��� ������������ ���� ����-����� -
		// ������ ������ CVCPThreadDlg, ������� ����� ����� ��������
		// ���������� ������ m_strCommand ���� CString.

		CCmdParseDlg* pDlg = (CCmdParseDlg*)GetParent();
		//GetWindowText(pDlg->m_strCommand);
		pDlg->ExecuteCommand();


		//pDlg->GetNextDlgTabItem(this)->SetFocus();
		return;   // ������ ��������� ��-���������
	}

	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}
