#ifndef CTPKTOOL_H_
#define CTPKTOOL_H_

#include "utility.h"

class CCtpkTool
{
public:
	enum EParseOptionReturn
	{
		kParseOptionReturnSuccess,
		kParseOptionReturnIllegalOption,
		kParseOptionReturnNoArgument,
		kParseOptionReturnOptionConflict
	};
	enum EAction
	{
		kActionNone,
		kActionExport,
		kActionImport,
		kActionHelp
	};
	struct SOption
	{
		const char* Name;
		int Key;
		const char* Doc;
	};
	CCtpkTool();
	~CCtpkTool();
	int ParseOptions(int a_nArgc, char* a_pArgv[]);
	int CheckOptions();
	int Help();
	int Action();
	static SOption s_Option[];
private:
	EParseOptionReturn parseOptions(const char* a_pName, int& a_nIndex, int a_nArgc, char* a_pArgv[]);
	EParseOptionReturn parseOptions(int a_nKey, int& a_nIndex, int a_nArgc, char* a_pArgv[]);
	bool exportFile();
	bool importFile();
	EAction m_eAction;
	const char* m_pFileName;
	const char* m_pDirName;
	bool m_bVerbose;
};

#endif	// CTPKTOOL_H_