#include "pch.h"
#include "CMyStr.h"
#include <iostream>

CMyStr::CMyStr(const CMyStr &cOther)
{
	v_copy(cOther);
}

CMyStr::CMyStr(CMyStr &&cOther) 
{
	pc_str = cOther.pc_str;
	i_size = cOther.i_size;
	cOther.pc_str = NULL;
	cOther.i_size = 0;
}

CMyStr::~CMyStr() {
	if(pc_str!=NULL) delete pc_str;
}

void CMyStr::operator=(const CMyStr &cOther) 
{
	v_copy(cOther);
}

void CMyStr::operator=(CMyStr && cOther)
{
	if (pc_str != NULL) delete pc_str;

	pc_str = cOther.pc_str;
	i_size = cOther.i_size;
	cOther.pc_str = NULL;
	cOther.i_size = 0;
}

void CMyStr::vSet(std::string sValue)
{
	if(pc_str!=NULL) delete pc_str;

	i_size = sValue.length();
	pc_str = new char[i_size];
	for (int ii = 0; ii < i_size; ii++)
		pc_str[ii] = sValue[ii];
}

void CMyStr::vPrint()
{
	if(pc_str==NULL) std::cout << "NULL\n";
	else std::cout << pc_str<<"\n";
}

void CMyStr::v_copy(const CMyStr &cOther)
{
	if (pc_str != NULL) delete pc_str;

	i_size = cOther.i_size;
	pc_str = new char[i_size];
	for (int ii = 0; ii < i_size; ii++)
		pc_str[ii] = cOther.pc_str[ii];
}