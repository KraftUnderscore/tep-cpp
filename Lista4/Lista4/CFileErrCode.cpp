#include "pch.h"
#include <iostream>
#include <vector>
#include "CFileErrCode.h"
#pragma warning(disable : 4996)

CFileErrCode::CFileErrCode()
{

}

CFileErrCode::CFileErrCode(std::string sFileName, int &iFlag)
{
	if (vOpenFile(sFileName)) iFlag = 1;
	else iFlag = -1;
}

CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL)
		fclose(pf_file);
}

bool CFileErrCode::vOpenFile(std::string sFileName)
{
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL) return false;
	return true;
}

bool CFileErrCode::vCloseFile()
{
	if (pf_file == NULL) return false;
	fclose(pf_file);
	return true;
}

bool CFileErrCode::vPrintLine(std::string sText)
{
	if (pf_file == NULL) return false;
	fprintf(pf_file, sText.c_str());
	return true;
}

bool CFileErrCode::vPrintManyLines(std::vector<std::string> sText)
{
	for (std::vector<std::string>::iterator iit = sText.begin(); iit != sText.end(); ++iit)
	{
		if(!vPrintLine(*iit))return false;
	}
	return true;
}