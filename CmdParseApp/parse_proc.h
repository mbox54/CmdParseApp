// parse_proc.h 

// interface file
#pragma once


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
// Extern prototypes
#include "CmdParseDlg.h"

// externs
void cmd00(void);
void cmd01(void);


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

#define CMD_MAX_LENGTH		64
#define CMD_ENTITY_LEN		16
#define CMD_VALUE_LEN		48

#define CMD_COUNT			20


////////////////////////////////////////////////////////////////////////////////
// Function
////////////////////////////////////////////////////////////////////////////////

// type#00
struct stCommand
{
	// description
	const char* entity;
	const char* help;

	// function
	void(*proc)(void);

};


// defined commands
static const stCommand gv_cmdLines[2] =
{
	{
		"cmd00",
		"cmd0_help",
		cmd00
	},

	{
		"cmd01",
		"cmd1_helphelp",
		cmd01
	}

};

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




// new method #0
BYTE CmdLine_Proc(char* strCommand);

// old method #2
//BYTE Proc_CommandLine_type2(char* strInput);
