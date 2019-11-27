#include "pch.h"
#include <iostream>
#include <vector>
#include "CFileThrowEx.h"
#pragma warning(disable : 4996)

CFileThrowEx::CFileThrowEx()
{
	s_file_name = "";
}

CFileThrowEx::CFileThrowEx(std::string sFileName)
{
	vOpenFile(sFileName);
}

CFileThrowEx::~CFileThrowEx()
{
	if(pf_file!=NULL)
		fclose(pf_file);
}

CFileThrowEx CFileThrowEx::operator=(CFileThrowEx &cFileThrowEx)
{
	std::string sFileName = cFileThrowEx.s_file_name;
	if (sFileName == "") throw 4;
	return CFileThrowEx(sFileName + "_copy.txt");
}

void CFileThrowEx::vOpenFile(std::string sFileName)
{
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL) throw 1;
	s_file_name = sFileName;
}

void CFileThrowEx::vCloseFile()
{
	if (pf_file == NULL) throw 2;
	fclose(pf_file);
	s_file_name = "";
}

void CFileThrowEx::vPrintLine(std::string sText)
{
	if (pf_file == NULL) throw 3;
	fprintf(pf_file, sText.c_str());
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText)
{
	for (std::vector<std::string>::iterator iit = sText.begin(); iit != sText.end(); ++iit)
	{
		vPrintLine(*iit);
	}
}