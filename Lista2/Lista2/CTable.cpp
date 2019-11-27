#include "pch.h"
#include "CTable.h"
#include <iostream>

const std::string s_name_default = "CTab";
const int i_length_default = 10;

	CTable::CTable()
	{
		sName = s_name_default;
		iTableLen = i_length_default;
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
		sName = pcOther.sName+"_copy";
		iTableLen = pcOther.iTableLen;
		piTable = new int[iTableLen];
		for (int ii = 0; ii < iTableLen; ii++)
		{
			piTable[ii] = pcOther.piTable[ii];
		}
		std::cout << "kopiuj: '" << sName << "'\n";

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
		piTable = new int(iTableLen);

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
			pcTabRev->piTable[ii] = piTable[iTableLen-1 - ii];
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