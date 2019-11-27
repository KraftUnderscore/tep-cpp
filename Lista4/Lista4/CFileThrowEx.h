#include "pch.h"
#include <iostream>
#include <vector>
#pragma once

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(std::string sFileName);
	~CFileThrowEx();

	CFileThrowEx operator=(CFileThrowEx &sFileThrowEx);

	void vOpenFile(std::string sFileName);
	void vCloseFile();
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);

private:
	FILE *pf_file;
	std::string s_file_name;
};
