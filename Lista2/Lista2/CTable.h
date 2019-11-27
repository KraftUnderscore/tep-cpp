#include <string>
#pragma once

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(const CTable &pcOther);
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable *pcClone();
	CTable *pcGetReverted();
	void vFillTable();
	~CTable();
	void vPrintAllValues();
private:
	std::string sName;
	int iTableLen;
	int *piTable;
};