// CmdParseDlg.cpp : implementation file
//
// NOTE:
// _CRT_SECURE_NO_WARNINGS


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "framework.h"

#include "CmdParseApp.h"
#include "CmdParseDlg.h"

#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void Trace_Custom(CEdit * pEdit, CString str)
{
	CString strWndText;
	pEdit->GetWindowText(strWndText);
	strWndText += str;
	pEdit->SetWindowText(strWndText);

	pEdit->SetSel(str.GetLength() - 1, str.GetLength() - 2, FALSE);
	pEdit->LineScroll(-pEdit->GetLineCount());
	pEdit->LineScroll(pEdit->GetLineCount() - 4);
}


void OutputLog(LPCTSTR szFmt, ...)
{
	// get control from memory
	CWnd* pEditLog = AfxGetApp()->m_pMainWnd->GetDlgItem(IDC_EDIT_LOG);
	HWND hWND = pEditLog->GetSafeHwnd();

	// check control appropriate class
	wchar_t str_buf[256];
	GetClassName(hWND, str_buf, 255);
	if (StrCmpIW(str_buf, _T("Edit")) == 0)
	{
		// [VALID]

		// > perform op
		CEdit* pEdit = static_cast<CEdit*>(pEditLog);		

		// format the message text
		CString str;
		va_list argptr;
		va_start(argptr, szFmt);
		str.FormatV(szFmt, argptr);
		va_end(argptr);

		str.Replace(_T("\n"), _T("\r\n"));

		// output to control
		Trace_Custom(pEdit, str);
	}
}


void pause_thread(int n, int A)
{
	int k = 0;

	while (k < n)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		OutputLog(_T("thread %d : pause of %d seconds ended \n"), A, k);

		k++;
	}

	OutputLog(_T("[ thread %d has ended ] \n"), A);
}


void CallProc1(void)
{
	// get control from memory
	//CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd->GetDlgItem(IDD_CMDPARSEAPP_DIALOG);
	CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd;
	HWND hWND = pDialogWnd->GetSafeHwnd();

	// check control appropriate class
	wchar_t str_buf[256];
	GetClassName(hWND, str_buf, 255);
//	if (StrCmpIW(str_buf, _T("Dialog")) == 0)
	{
		// [VALID]

		// > perform op
		CCmdParseDlg* pDialodParse = static_cast<CCmdParseDlg*>(pDialogWnd);

		pDialodParse->Trace(_T("ParseDlg.Proc()\n"));		
	}
}


void CallProc2(void)
{
	// get control from memory
	//CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd->GetDlgItem(IDD_CMDPARSEAPP_DIALOG);
	CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd;
	HWND hWND = pDialogWnd->GetSafeHwnd();

	// check control appropriate class
	wchar_t str_buf[256];
	GetClassName(hWND, str_buf, 255);
	//	if (StrCmpIW(str_buf, _T("Dialog")) == 0)
	{
		// [VALID]

		// > perform op
		CCmdParseDlg* pDialodParse = static_cast<CCmdParseDlg*>(pDialogWnd);

		pDialodParse->Sample1(0);
	}
}


void CallAfxThread1(void)
{
	// get control from memory
	//CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd->GetDlgItem(IDD_CMDPARSEAPP_DIALOG);
	CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd;
	HWND hWND = pDialogWnd->GetSafeHwnd();

	// check control appropriate class
	wchar_t str_buf[256];
	GetClassName(hWND, str_buf, 255);
	//	if (StrCmpIW(str_buf, _T("Dialog")) == 0)
	{
		// [VALID]

		// > perform op
		CCmdParseDlg* pDialodParse = static_cast<CCmdParseDlg*>(pDialogWnd);

		pDialodParse->ProcThread1();
	}
}


void CallAfxThread2(void)
{
	// get control from memory
	//CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd->GetDlgItem(IDD_CMDPARSEAPP_DIALOG);
	CWnd* pDialogWnd = AfxGetApp()->m_pMainWnd;
	HWND hWND = pDialogWnd->GetSafeHwnd();

	// check control appropriate class
	wchar_t str_buf[256];
	GetClassName(hWND, str_buf, 255);
	//	if (StrCmpIW(str_buf, _T("Dialog")) == 0)
	{
		// [VALID]

		// > perform op
		CCmdParseDlg* pDialodParse = static_cast<CCmdParseDlg*>(pDialogWnd);

		pDialodParse->ProcThread2();
	}
}

// simple tests
void cmd00(char * strValue)
{
	OutputLog(_T("Getting specific window (CEdit) in App main dialog. \n"));	
}


void cmd01(char* strValue)
{
	OutputLog(_T("Getting specific window method in Dialog. \n"));

	CallProc1();
}


void cmd02(char * strValue)
{
	OutputLog(_T("Spawning 3 std::thread's...\n"));

	std::thread t1(pause_thread, 5, 1);
	Sleep(10);
	std::thread t2(pause_thread, 10, 2);
	Sleep(10);
	std::thread t3(pause_thread, 15, 3);
	Sleep(10);

	OutputLog(_T("Done spawning threads. (not waiting for them to join)\n"));
	t1.detach();
	t2.detach();
	t3.detach();
	OutputLog(_T("All threads detached!\n"));
}


void cmd03(char* strValue)
{
	OutputLog(_T("Calling Dialog function with Sleep()\n"));

	CallProc2();
}


void cmd04(char* strValue)
{
	OutputLog(_T("Spawning AfxThread(void) with Sleep()\n"));

	CallAfxThread1();
}


void cmd05(char* strValue)
{
	OutputLog(_T("Spawning AfxThread(pointer) with Sleep()\n"));

	CallAfxThread2();
}

// thread complex test
void thread1(char* strValue)
{

}

void thread2(char* strValue)
{

}


////////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
////////////////////////////////////////////////////////////////////////////////
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


////////////////////////////////////////////////////////////////////////////////
// MESSAGE_MAP CAboutDlg
////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



////////////////////////////////////////////////////////////////////////////////
// CCmdParseDlg dialog
////////////////////////////////////////////////////////////////////////////////
CCmdParseDlg::CCmdParseDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CMDPARSEAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CCmdParseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CMD, m_ctrlEdit_Cmd);
	DDX_Control(pDX, IDC_EDIT_LOG, m_ctrlEdit_Log);
}


////////////////////////////////////////////////////////////////////////////////
// MESSAGE_MAP CCmdParseDlg
////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CCmdParseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCmdParseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CCmdParseDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCmdParseDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


////////////////////////////////////////////////////////////////////////////////
// CCmdParseDlg message handlers
BOOL CCmdParseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CCmdParseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CCmdParseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCmdParseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCmdParseDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	// CDialog::OnOK();
}


void CCmdParseDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void CCmdParseDlg::ExecuteCommand(void)
{
	CString strWndText;	

	// get command string
	m_ctrlEdit_Cmd.GetWindowText(strWndText);

	// output comment
	Trace(_T("command: %s\n"), strWndText);

	// parse command

	// Define CString charT instance
	CStringA string_buf = (CStringA)strWndText;
	char str_buf[64];
	sprintf(str_buf, "%s", string_buf);

	BYTE ucResult = CmdLine_Proc(str_buf);

	if (ucResult == 0)
	{
		// [SUCCESS]

		Trace(_T("command executed\n"));
	}
	else
	{
		// [FAIL]

		Trace(_T("bad command\n"));
	}
}


void CCmdParseDlg::Trace(LPCTSTR szFmt, ...)
{
	CString str;

	// Format the message text
	va_list argptr;
	va_start(argptr, szFmt);
	str.FormatV(szFmt, argptr);
	va_end(argptr);

	str.Replace(_T("\n"), _T("\r\n"));

	CString strWndText;
	m_ctrlEdit_Log.GetWindowText(strWndText);
	strWndText += str;
	m_ctrlEdit_Log.SetWindowText(strWndText);

	m_ctrlEdit_Log.SetSel(str.GetLength() - 1, str.GetLength() - 2, FALSE);
	m_ctrlEdit_Log.LineScroll(-m_ctrlEdit_Log.GetLineCount());
	m_ctrlEdit_Log.LineScroll(m_ctrlEdit_Log.GetLineCount() - 4);
}

// test proc
void CCmdParseDlg::ProcThread1(void)
{
	// create new thread with no params
	AfxBeginThread(Sample1, NULL);
}


void CCmdParseDlg::ProcThread2(void)
{
	// create new thread with param
	int* input = new int;
	*input = 9001;

	// NOTE: var 'input' desroys in threadProc
	AfxBeginThread(Sample2, input);
}


UINT CCmdParseDlg::Sample1(LPVOID rawInput)
{
	for (BYTE k = 0; k < 10; k++)
	{
		OutputLog(_T("Second number %d \n"), k);

		Sleep(1500);
	}

	return 0;
}


UINT __cdecl CCmdParseDlg::Sample2(LPVOID rawInput)
{
	// convert it to the correct data type. It's common to pass entire structures this way.
	int * input = (int*)rawInput;

	// avoid memory leak
	delete input;


	return 0;
}

// Clear Log control
void CCmdParseDlg::OnBnClickedButton1()
{
	//m_ctrlEdit_Log.SetWindowText(_T(""));
	//cmd00();
}


void CCmdParseDlg::OnBnClickedButton2()
{
	//
}
