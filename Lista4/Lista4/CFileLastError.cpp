#include "pch.h"
#include <iostream>
#include <vector>
#include "CFileLastError.h"
#pragma warning(disable : 4996)

bool CFileLastError::b_last_error;

CFileLastError::CFileLastError()
{

}

CFileLastError::CFileLastError(std::string sFileName)
{
	vOpenFile(sFileName);
}

CFileLastError::~CFileLastError()
{
	if (pf_file != NULL)
		fclose(pf_file);
}

void CFileLastError::vOpenFile(std::string sFileName)
{
	b_last_error = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL) b_last_error = true;	
}

void CFileLastError::vCloseFile()
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	fclose(pf_file);
}

void CFileLastError::vPrintLine(std::string sText)
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	fprintf(pf_file, sText.c_str());
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText)
{
	b_last_error = false;
	for (std::vector<std::string>::iterator iit = sText.begin(); iit != sText.end(); ++iit)
	{
		vPrintLine(*iit);
		if (bGetLastError())
		{
			b_last_error = true;
			return;
		}
	}
}