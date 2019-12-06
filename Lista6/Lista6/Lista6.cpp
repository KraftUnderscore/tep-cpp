#include "pch.h"
#include "CTreeDynamic.h"

int main()
{
	CTreeDynamic<int> c_int_tree;

	c_int_tree.pcGetRoot()->vSetValue(2);
	c_int_tree.pcGetRoot()->vAddNewChild(3);
	c_int_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(5);
	c_int_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(6);

	c_int_tree.pcGetRoot()->vAddNewChild(4);
	c_int_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild(7);
	c_int_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild(8);

	c_int_tree.vPrintByLevel();
	std::cout<<c_int_tree.tSumByLvl();
}