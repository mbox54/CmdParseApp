
// CmdParseDlg.h : header file
//

#pragma once


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
#include "KeyEdit.h"

// cmd parse proc
#include "parse_proc.h"
// thread
#include <thread>         // std::thread, std::this_thread::sleep_for
// support
#include <chrono>         // std::chrono::seconds


////////////////////////////////////////////////////////////////////////////////
// define
////////////////////////////////////////////////////////////////////////////////
#define CMD_MAX_LENGTH		64
#define CMD_ENTITY_LEN		16
#define CMD_VALUE_LEN		48


// support
void Trace_Custom(CEdit* pEdit, CString str);
void OutputLog(LPCTSTR szFmt, ...);
void pause_thread(int n, int A);
void CallProc1(void);
void CallAfxThread1(void);
void CallAfxThread2(void);


// cmds
void cmd00(char* strValue);
void cmd01(char* strValue);
void cmd02(char* strValue);
void cmd03(char* strValue);
void cmd04(char* strValue);
void cmd05(char* strValue);
void thread1(char* strValue);
void thread2(char* strValue);


////////////////////////////////////////////////////////////////////////////////
// CCmdParseDlg dialog
////////////////////////////////////////////////////////////////////////////////
class CCmdParseDlg : public CDialog
{
// Construction
public:
	CCmdParseDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CMDPARSEAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();


	DECLARE_MESSAGE_MAP()
	virtual void OnOK();


public:

	static UINT __cdecl Sample1(LPVOID rawInput);
	static UINT __cdecl Sample2(LPVOID rawInput);

	void ExecuteCommand(void);
	void Trace(LPCTSTR szFmt, ...);
	void ProcThread1(void);
	void ProcThread2(void);

	afx_msg void OnBnClickedOk();

	CEdit m_ctrlEdit_Log;
	CKeyEdit m_ctrlEdit_Cmd;
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
};
