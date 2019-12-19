#include "pch.h"
#include "CTab.h"
#include <iostream>

CTab::CTab(const CTab &cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab::CTab(CTab &&cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	std::cout << "MOVE ";
}

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}

CTab CTab::operator=(const CTab &cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}

CTab CTab::operator=(const CTab &&cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "move_op= ";
	return std::move(*this);
}

bool CTab::bSetSize(int iNewSize)
{
	if (iNewSize <= 0)return false;

	delete pi_tab;
	this->i_size = iNewSize;
	pi_tab = new int[iNewSize];

	return true;
}

void CTab::v_copy(const CTab &cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}