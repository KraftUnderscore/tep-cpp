#include "pch.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"
#include <iostream>

#define LAST_ERROR 0
#define THROW_EX 1
#define ERROR_CODE 2

void v_test_function(int iClassType, std::string sFileName)
{
	CFileLastError c_file_last_err;
	CFileThrowEx c_file_throw_ex;
	CFileErrCode c_file_err_code;

	switch (iClassType)
	{
	case LAST_ERROR:
		for (int ii = 0; ii < 10; ii++)
		{
			c_file_last_err.vOpenFile(sFileName);
			if (c_file_last_err.bGetLastError()) std::cout << "Cannot open file.\n";
			else break;
		}
		c_file_last_err.vPrintLine("LAST_ERROR");
		c_file_last_err.vCloseFile();
		break;
	case THROW_EX:
		for (int ii = 0; ii < 10; ii++) {
			try
			{
				c_file_throw_ex.vOpenFile(sFileName);
				break;
			}
			catch (int e)
			{
				std::cout << "An exception #" << e << "\n";
			}
		}
		c_file_throw_ex.vPrintLine("THROW_EX");
		c_file_throw_ex.vCloseFile();
		break;
	case ERROR_CODE:
		for (int ii = 0; ii < 10; ii++)
			if (!c_file_err_code.vOpenFile(sFileName)) std::cout << "Cannot open file.\n";
			else break;
		c_file_err_code.vPrintLine("ERR_CODE");
		c_file_err_code.vCloseFile();
		break;
	default:
		break;
	}
}
int main()
{
	std::string s_filename = "test.txt";
	//v_test_function(THROW_EX, s_filename);
	int i_flag = 0;
	CFileErrCode(s_filename, i_flag);
	std::cout << "Error code: " << i_flag;
	/*CFileThrowEx c_origi;
	c_origi.vOpenFile("test.txt");
	CFileThrowEx c_oth;
	try {
		c_oth = c_origi;
	}
	catch (int e)
	{
		std::cout << "An exception #" << e << "\n";
	}*/
}
