#include "pch.h"
#include "CTab.h"
#include "CTable.h"
#include "CMyStr.h"
#include <iostream>
int main()
{
	/*CTab c_tab;
	CTab c_other;
	c_tab.bSetSize(2);
	c_other.bSetSize(5);
	std::cout << "\nwithout\n";
	c_tab = c_other;
	std::cout << "\nwith\n";
	c_tab = std::move(c_other);

	std::cout << "\n\n=====TEST2\n";
	CTable c_table("t1", 3);
	CTable c_other_table("t2", 5);
	
	std::cout << "\nwithout\n";
	c_table = c_other_table;
	std::cout << "\nwith\n";
	c_table = std::move(c_other_table);*/

	CMyStr c_str_1;
	CMyStr c_str_2;
	CMyStr c_str_3;

	c_str_1.vSet("test");
	c_str_2.vSet("test2");
	c_str_3.vSet("test3");

	c_str_1 = c_str_2;
	c_str_1.vPrint();
	c_str_2.vPrint();
	c_str_1 = std::move(c_str_3);
	c_str_1.vPrint();
	c_str_3.vPrint();
}