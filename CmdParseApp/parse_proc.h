// parse_proc.h 

// interface file
#pragma once


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
// Extern prototypes
#include "CmdParseDlg.h"

// externs
void help(char* strValue);
void cmd00(char* strValue);
void cmd01(char* strValue);
void cmd02(char* strValue);
void cmd03(char* strValue);
void cmd04(char* strValue);
void cmd05(char* strValue);
void thread1(char* strValue);
void thread2(char* strValue);

void OutputLog(LPCTSTR szFmt, ...);


////////////////////////////////////////////////////////////////////////////////
// define
////////////////////////////////////////////////////////////////////////////////
#define OP_END_SYMB			0
#define OP_END_NULL			1
#define OP_NULL_STR			2

#define MODE_CMD_NAME		0
#define MODE_CMD_PAR		1
#define MODE_CMD_VAL		2
#define MODE_CMD_PVAL		3

#define MODE_CMD_SEP_PAR	0
#define MODE_CMD_SEP_VAL	1

#define MAX_STR_TAG			8
//

#define CMD_RET_SUCCESS		0
#define CMD_RET_UNKNOWN		1
#define CMD_RET_BAD_PAR		2


////////////////////////////////////////////////////////////////////////////////
// Function
////////////////////////////////////////////////////////////////////////////////

// type#00
struct stCommand
{
	// description
	const char* entity;
	const char* info;

	// function
	void(*proc)(char * strValue);

};


// defined commands
static const stCommand gv_cmdLines[9] =
{
	{
		"help",
		"Show full list of entities with short description.",
		help
	},

	{
		"cmd00",
		"Getting specific window (CEdit) in App main dialog.",
		cmd00
	},

	{
		"cmd01",
		"Getting specific window method in Dialog.",
		cmd01
	},

	{
		"cmd02",
		"Spawning 3 std::thread's...",
		cmd02
	},

	{
		"cmd03",
		"Calling Dialog function with Sleep()",
		cmd03
	},

	{
		"cmd04",
		"Spawning AfxThread(void) with Sleep()",
		cmd04
	},

	{
		"cmd05",
		"Spawning AfxThread(pointer) with Sleep()",
		cmd05
	},

	{
		"thread1",
		"Thread1 test ops.",
		thread1
	},

	{
		"thread2",
		"Thread2 test ops.",
		thread2
	}

};

// new method #0
BYTE CmdLine_Proc(char* strCommand);


/////////////////////////////////////////////////////////////////////////
// old type 2
//struct stCommandLine_type2
//{
//	// description
//	const char* name;
//	const char* help;
//
//	// parameters
//	BYTE ucPars_count;
//	const char* v_pars[6];
//
//	// function
//	void(*proc)(void);
//
//};


// old type cmd
//static const stCommandLine_type2 mv_cmdLines[2] =
//{
//	{
//		"cmd00",
//		"cmd0_help",
//		6,
//		{ "00", "01", "02", "03", "04", "05" },
//				cmd00
//			},
//
//		{
//			"cmd01",
//			"cmd1_helphelp",
//			6,
//			{ "10", "11", "12", "13", "14", "15" },
//				cmd01
//			}
//
//};
// old method #2
//BYTE Proc_CommandLine_type2(char* strInput);
