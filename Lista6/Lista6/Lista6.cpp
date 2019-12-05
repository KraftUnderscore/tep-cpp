#include "pch.h"
#include "CTreeDynamic.h"

int main()
{
	CTreeDynamic<int> c_int_tree;
	CTreeDynamic<std::string> c_string_tree;
	CTreeDynamic<CTreeDynamic<int>> c_tree_tree;

	c_int_tree.pcGetRoot()->vAddNewChild(10);
	c_int_tree.vPrintByLevel();

	c_string_tree.pcGetRoot()->vSetValue("Hej!");
	c_string_tree.pcGetRoot()->vAddNewChild("Co");
	c_string_tree.pcGetRoot()->vAddNewChild("tam");
	c_string_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild("?");
	c_string_tree.vPrintByLevel();
}