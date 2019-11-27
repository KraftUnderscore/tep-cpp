#include "pch.h"
#include <iostream>
#include "CTreeStatic.h"

int main()
{
	CTreeStatic c_tree;

	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_tree.vPrintTree();
	std::cout << "\n";
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}
