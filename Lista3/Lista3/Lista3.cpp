#include "pch.h"
#include "CTable.h"
#include <iostream>
#include <vector>

int main()
{
	/*int i_size_0 = 2, i_size_1 = 3;

	CTable c_tab0("Tab0", i_size_0);
	CTable c_tab1("Tab1", i_size_1);

	c_tab0.vFillTable(1);
	c_tab1.vFillTable(9);

	int *pi_tab = c_tab0 + c_tab1;

	for (int ii = 0; ii < i_size_0 + i_size_1; ii++)
	{
		std::cout << pi_tab[ii] << " ";
	}
	std::cout << "\n";

	delete pi_tab;*/

	CTable c_arg;
	c_arg.vFillTable(1);
	CTable c_sum = c_arg +9;
	c_sum.vPrintAllValues();

	/*----------zad1

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;

	*/
	/*-----------zad3

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrintAllValues();
	c_tab_1.vPrintAllValues();

	*/

	/*------test
	std::vector<CTable> v_list;
	CTable c_tab;
	for (int ii = 0; ii < 100; ii++)
	{
		v_list.push_back(c_tab);
	}
	*/
}
