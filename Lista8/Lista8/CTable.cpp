#include "pch.h"
#include "CTable.h"
#include <iostream>

CTable::CTable()
{
	sName = S_NAME_DEFAULT;
	iTableLen = I_LENGTH_DEFAULT;
	piTable = new int[iTableLen];
	std::cout << "bezp: '" << sName << "'\n";
}

CTable::CTable(std::string sName, int iTableLen)
{
	this->sName = sName;
	this->iTableLen = iTableLen;
	piTable = new int[iTableLen];
	std::cout << "parametr: '" << this->sName << "'\n";
}

CTable::CTable(const CTable &pcOther)
{
	sName = pcOther.sName + "_copy";
	iTableLen = pcOther.iTableLen;
	piTable = new int[iTableLen];
	for (int ii = 0; ii < iTableLen; ii++)
	{
		piTable[ii] = pcOther.piTable[ii];
	}
	std::cout << "kopiuj: '" << sName << "'\n";
}

CTable::CTable(CTable &&cOther)
{
	piTable = cOther.piTable;
	iTableLen = cOther.iTableLen;
	sName = cOther.sName;

	cOther.piTable = NULL;

	std::cout << "moveConst\n";
}

int CTable::operator+(CTable &pcOther)
{
	int iNewTabLen = iTableLen + pcOther.iTableLen;
	int *piNewTable = new int[iNewTabLen];
	for (int ii = 0; ii < iNewTabLen; ii++)
	{
		if (ii < iTableLen)piNewTable[ii] = piTable[ii];
		else piNewTable[ii] = pcOther.piTable[ii - iTableLen];
	}
	return *piNewTable;
}

CTable CTable::operator+(int iValue)
{
	CTable cTab("+", 10);
	cTab.bSetNewSize(iTableLen + 1);
	for (int ii = 0; ii < iTableLen + 1; ii++)
	{
		if (ii == iTableLen)cTab.piTable[ii] = iValue;
		else cTab.piTable[ii] = piTable[ii];
	}
	return (std::move (cTab));
}

CTable CTable::operator=(const CTable &cOther)
{
	if (piTable != NULL) delete piTable;

	sName = cOther.sName + "_copy";
	iTableLen = cOther.iTableLen;
	piTable = new int[iTableLen];
	for (int ii = 0; ii < iTableLen; ii++)
	{
		piTable[ii] = cOther.piTable[ii];
	}

	std::cout << "move_op=\n";
	return (*this);
}

CTable CTable::operator=(const CTable &&cOther)
{
	if (piTable != NULL) delete piTable;

	sName = cOther.sName + "_moveCopy";
	iTableLen = cOther.iTableLen;
	piTable = new int[iTableLen];
	for (int ii = 0; ii < iTableLen; ii++)
	{
		piTable[ii] = cOther.piTable[ii];
	}

	std::cout << "move_op=\n";
	return std::move(*this);
}

void CTable::vSetName(std::string sName)
{
	this->sName = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen <= 0)return false;

	delete piTable;
	this->iTableLen = iTableLen;
	piTable = new int[iTableLen];

	return true;
}

CTable* CTable::pcClone()
{
	CTable *cClone = new CTable(*this);
	return cClone;
}

CTable::~CTable()
{
	delete piTable;
	std::cout << "usuwam: '" << sName << "'\n";
}

CTable* CTable::pcGetReverted()
{
	CTable *pcTabRev = this->pcClone();
	for (int ii = 0; ii < iTableLen; ii++)
	{
		pcTabRev->piTable[ii] = piTable[iTableLen - 1 - ii];
	}
	return pcTabRev;
}

void CTable::vFillTable()
{
	for (int ii = 0; ii < iTableLen; ii++)
	{
		piTable[ii] = ii;
	}
}

void CTable::vFillTable(int iValue)
{
	for (int ii = 0; ii < iTableLen; ii++)
	{
		piTable[ii] = iValue;
	}
}

void CTable::vSetValueAt(int iOffset, int iValue)
{
	piTable[iOffset] = iValue;
}

void CTable::vPrintAllValues()
{
	std::cout << "\nNazwa: " << sName;
	std::cout << "\n Dlugosc tablicy: " << iTableLen << "\n";
	std::cout << "Wartosci tablicy:\n";
	for (int ii = 0; ii < iTableLen; ii++)
	{
		std::cout << piTable[ii] << " ";
	}
	std::cout << "\n\n";
}