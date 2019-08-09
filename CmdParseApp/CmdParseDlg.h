
// CmdParseDlg.h : header file
//

#pragma once


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
#include "KeyEdit.h"

// cmd parse proc
#include "parse_proc.h"

// support
void Trace_Custom(CEdit* pEdit, LPCTSTR szFmt, ...);

// cmds
void cmd00(void);
void cmd01(void);


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
	void ExecuteCommand(void);
	void Trace(LPCTSTR szFmt, ...);


	afx_msg void OnBnClickedOk();


	CKeyEdit m_ctrlEdit_Cmd;
	CEdit m_ctrlEdit_Log;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
