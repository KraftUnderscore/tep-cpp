#include "pch.h"
#include <iostream>

void v_alloc_table_add_5(int iSize)
{
	if (iSize <= 0)
	{
		return;
	}
	else
	{
		int *piTable;
		piTable = new int[iSize];
		for (int ii = 0; ii < iSize; ii++)
		{
			piTable[ii] = ii + 5;
		}
		for (int ii = 0; ii < iSize; ii++)
		{
			std::cout << piTable[ii] << "\n";
		}
		delete piTable;
	}
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
	if (iSizeX <= 0 || iSizeY <= 0)return false;
	*piTable = new int*[iSizeX];
	for (int ii = 0; ii < iSizeX; ii++)
	{
		(*piTable)[ii] = new int[iSizeY];
	}
	return true;
}

bool b_alloc_table_p(int ***piTable, int iLength, int iPairSize, int iImpairSize)
{
	if (iLength<=0 || iPairSize <= 0 || iImpairSize <= 0)return false;
	*piTable = new int*[iLength];
	for (int ii = 0; ii < iLength; ii++)
	{
		if(ii%2==0)(*piTable)[ii] = new int[iPairSize];
		else (*piTable)[ii] = new int[iImpairSize];
	}
	return true;
}

bool b_dealloc_table_p(int **piTable, int iLength)
{
	if (iLength <= 0)return false;
	for (int ii = 0; ii < iLength; ii++)
	{
		delete piTable[ii];
	}
	delete piTable;
	return true;
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
	if (iSizeX <= 0)return false;
	for (int ii = 0; ii < iSizeX; ii++)
	{
		delete piTable[ii];
	}
	delete piTable;
	return true;
}
