#include "pch.h"
#include <iostream>
#include <vector>
#pragma once

class CFileErrCode
{
public:
	CFileErrCode();
	CFileErrCode(std::string sFileName, int &iFlag);
	~CFileErrCode();

	bool vOpenFile(std::string sFileName);
	bool vCloseFile();
	bool vPrintLine(std::string sText);
	bool vPrintManyLines(std::vector<std::string> sText);

private:
	FILE *pf_file;
};
