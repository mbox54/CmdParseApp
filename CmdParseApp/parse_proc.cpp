// parse_proc.c

// implementation file


////////////////////////////////////////////////////////////////////////////////
// include
////////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "framework.h"

#include "parse_proc.h"


////////////////////////////////////////////////////////////////////////////////
// functions
////////////////////////////////////////////////////////////////////////////////

// INFO:
// function: proc line
// clauses:
// # mode 0 = entity
// uses symbols: '\0' - at the end
// # mode 1 = entity value
// uses symbols: ' ' - to separate, '\0' - at the end 
BYTE CmdLine_Proc(char* strCommand)
{
	char strEntity[CMD_ENTITY_LEN];
	char strValue[CMD_VALUE_LEN];

	// > decompose cmd to define clause
	char* pch;
	pch = strchr(strCommand, ' ');
	
	BYTE ucMode = 255;
	if (pch == 0)
	{
		// [MODE 0]

		// get Entity
		strcpy(strEntity, strCommand);			

		ucMode = 0;
	}
	else
	{
		// [MODE 1]

		// get Entity
		BYTE uc_strEntityLen = pch - strCommand;
		strncpy(strEntity, strCommand, uc_strEntityLen);
		strEntity[uc_strEntityLen] = '\0';

		// get Value
		strncpy(strValue, pch + 1, strlen(strCommand) - uc_strEntityLen);

		ucMode = 1;
	}

	// > check Valid Entity
	BYTE ucInvalidCmd = 1;
	for (BYTE k = 0; k < CMD_COUNT; k++)
	{
		if (strcmp(strEntity, gv_cmdLines[k].entity) == 0)
		{
			// [VALID]

			// > activate
			// NOTE: Value can be checked also too
			gv_cmdLines[k].proc(strValue);

			return CMD_RET_SUCCESS;
		}
	}

	return CMD_RET_UNKNOWN; 
}

// commands /service
// show full list of entities with help field
void help(char* strValue)
{
	for (BYTE k = 0; k < CMD_COUNT; k++)
	{
		OutputLog(_T("%02d. %s: %s\n"), k, (CStringW)(CStringA)gv_cmdLines[k].entity, (CStringW)(CStringA)gv_cmdLines[k].info);
	}

}



///////////////////////////////////////////////////////////////////////
// old realisation /type2

// INFO:
// function: proc line
// clauses:
// # mode 0 = parse cmd name
// uses separate symbols: '-', '=', '\0'
// # mode 1 = parse cmp param
// uses separate symbols: '=', '\0'
// # mode 2 = parse cmp value
// uses separate symbols: '\0'
//BYTE GetStrSep(char* strParse, char* strOutput, BYTE* ucSepNum, BYTE mode)
//{
//	const BYTE const_MAX_SEP_CHARS = 8;
//
//	struct
//	{
//		BYTE ucCount;
//		char v_char[const_MAX_SEP_CHARS];
//
//	} v_mode[3] = {
//		// mode 0:
//		{
//			2,
//			{ '-', '=' }
//		},
//		// mode 1:
//		{
//			1,
//			{ '=' }
//		},
//		// mode 2:
//		{
//			0,
//			{  }
//		}
//	};
//
//
//	// NOTE:
//	// cycle proc in next modes:
//	// act = 0: cycle proc end
//	// act = 1: try find Separate symbol op
//	char strTag[MAX_STR_TAG];
//
//	BYTE k = 0;
//	BYTE ucEndPos = 0;
//	char c;
//
//	BYTE act = 1;
//	while (act != 0)
//	{
//		// get iteration Symbol
//		c = strParse[k];
//
//		// check EOL
//		if (c == '\0')
//		{
//			// [EOS]
//
//			// define a Reason
//			if (k == 0)
//			{
//				// [EMPTY LINE]
//
//				return OP_NULL_STR;
//			}
//			else
//			{
//				// [NO SEPARATE SYMBOL FOUND]
//
//				return OP_END_NULL;
//			}
//		}// > Check End of Cycle /EOS
//
//		// > Proceed String
//		else
//		{
//			// [proc find Separate symbol]
//
//			BYTE ucSepNumber = 0;
//			while (ucSepNumber < v_mode[mode].ucCount)
//			{
//				// check separate coincidence
//				if (c == v_mode[mode].v_char[ucSepNumber])
//				{
//					// [COINCIDE]
//
//					// store coincide separate symbol
//					*ucSepNum = ucSepNumber;
//
//					// define End Pos
//					ucEndPos = k;
//
//					// trigger flag
//					act = 0;
//
//					// activate stop search op
//					ucSepNumber = v_mode[mode].ucCount;
//				}
//			}//while ucSepNum
//
//			// next symbol
//			k++;
//		}
//
//	}//while (act != 0)
//
//	// > Form Output String /tag/
//	for (BYTE kk = 0; kk <= ucEndPos; kk++)
//	{
//		strOutput[kk] = strParse[kk];
//	}
//
//	strOutput[ucEndPos + 1] = '\0';
//
//
//	return OP_END_SYMB;
//}
//


//BYTE Proc_CommandLine_type2(char* strInput)
//{
//	BYTE ucOpState;
//	BYTE ucSepType;
//	BYTE ucOpMode;
//
//	char strBuf[64];
//	char strCmdName[16];
//	char strCmdPar[16];
//	char strCmdVal[32];	
//
//	// > Stage 1: Get Cmd Config
//	// > Get Name
//	ucOpState = GetStrSep(strInput, strBuf, &ucSepType, MODE_CMD_NAME);
//
//	if (ucOpState == OP_NULL_STR)
//	{
//		// [EMPTY CMD]
//
//		return 1;
//	}
//	else if (ucOpState == OP_END_NULL)
//	{
//		// [CMD WITH NO VALUE]
//
//		// Set Name
//		strcpy(strCmdName, strInput);
//		// Set Mode
//		ucOpMode = MODE_CMD_NAME;
//	}
//	else if (ucOpState == OP_END_SYMB)
//	{
//		// [CMD HAS SOMETHING]
//
//		// Set Name
//		strcpy(strCmdName, strBuf);
//
//		// Shift CmdLine
//		BYTE ucPos = strlen(strBuf);
//		strcpy(strBuf, strInput + ucPos);
//
//		if (ucSepType == MODE_CMD_SEP_VAL)
//		{
//			// [CMD WITH VALUE]
//
//			// Set Value
//			ucOpState = GetStrSep(strBuf, strCmdVal, &ucSepType, MODE_CMD_VAL);
//
//			// check NULL
//			if (ucOpState != OP_NULL_STR)
//			{
//				// [NOT NULL]
//
//				// Set Mode
//				ucOpMode = MODE_CMD_VAL;
//			}
//			else
//			{
//				// [EMPTY CMD]
//
//				return 1;
//			}
//		}
//		else if (ucSepType == MODE_CMD_SEP_PAR)
//		{
//			// [CMD HAS PAR]
//
//			// Set Parameter
//			ucOpState = GetStrSep(strBuf, strCmdPar, &ucSepType, MODE_CMD_PAR);
//
//			// check NULL
//			if (ucOpState != OP_NULL_STR)
//			{
//				// [NOT NULL]
//
//				// check Par only clause
//				if (ucOpState == OP_END_NULL)
//				{
//					// [CMD WITH PAR ONLY]
//
//					// Set Mode
//					ucOpMode = MODE_CMD_PAR;
//				}
//				else
//				{
//					// [CMD WITH PAR AND VALUE]
//
//					// Shift CmdLine
//					BYTE ucPos = strlen(strCmdPar);
//					strcpy(strBuf, strBuf + ucPos);
//
//					// Set Value
//					ucOpState = GetStrSep(strBuf, strCmdVal, &ucSepType, MODE_CMD_VAL);
//
//					// check NULL
//					if (ucOpState != OP_NULL_STR)
//					{
//						// [NOT NULL]
//
//						// Set Mode
//						ucOpMode = MODE_CMD_PVAL;
//					}
//					else
//					{
//						// [EMPTY CMD]
//
//						return 1;
//					}
//				}//check Par only clause
//			}
//			else
//			{
//				// [EMPTY CMD]
//
//				return 1;
//			}
//		}//[CMD HAS PAR]
//	}//[CMD HAS SOMETHING]
//
//
//	// > Stage 2: Check Cmd Config
//	BYTE ucCmdName;
//	BYTE ucCmdPar;
//	BYTE bValidCmdLine = 0;
//
//	// check Cmd Valid Name
//	for (BYTE k = 0; k < CMD_COUNT; k++)
//	{
//		if ((strcmp(strInput, mv_cmdLines[k].name)) == 0)
//		{
//			// set Cmd Config
//			ucCmdName = k;
//			bValidCmdLine = 1;
//
//			break;
//		}
//	}
//
//
//	// > Stage 3: Execute Cmd
//	// check Valid
//	if (bValidCmdLine != 1)
//	{
//		// [NO SUCH CMD]
//
//		return 1;
//	}
//
//	// Call specific Proc()
//	mv_cmdLines[ucCmdName].proc();
//
//	return 0;
//}
