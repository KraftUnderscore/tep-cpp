#include <string>
#pragma once
#define S_NAME_DEFAULT "CTab"
#define I_LENGTH_DEFAULT 10

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(const CTable &pcOther);
	int* operator +(CTable &pcOther);
	CTable operator +(int iValue);
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable *pcClone();
	CTable *pcGetReverted();
	void vFillTable();
	void vFillTable(int iValue);
	~CTable();
	void vPrintAllValues();
	void vSetValueAt(int iOffset, int iValue);

private:
	std::string sName;
	int iTableLen;
	int *piTable;
};