#include "pch.h"
#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

using namespace std;

int main()
{
	/*cout << "Static tree test\n";

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
	cout << "\n";
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

	cout << "\nDynamic tree test\n";
	CTreeDynamic c_dynamic_tree1;
	CTreeDynamic c_dynamic_tree2;
	CTreeDynamic c_dynamic_tree3;

	cout << "Dynamic tree 1: ";
	c_dynamic_tree1.pcGetRoot()->vSetValue(1);
	c_dynamic_tree1.pcGetRoot()->vAddNewChild(2);
	c_dynamic_tree1.pcGetRoot()->vAddNewChild(3);
	c_dynamic_tree1.vPrintTree();

	cout << "\nDynamic tree 2: ";
	c_dynamic_tree2.pcGetRoot()->vSetValue(4);
	c_dynamic_tree2.pcGetRoot()->vAddNewChild(5);
	c_dynamic_tree2.pcGetRoot()->vAddNewChild(6);
	c_dynamic_tree2.vPrintTree();

	cout << "\nDynamic tree 3: ";
	c_dynamic_tree3.pcGetRoot()->vSetValue(7);
	c_dynamic_tree3.pcGetRoot()->vAddNewChild(8);
	c_dynamic_tree3.pcGetRoot()->vAddNewChild(9);
	c_dynamic_tree3.pcGetRoot()->pcGetChild(0)->vAddNewChild(10);
	c_dynamic_tree3.pcGetRoot()->pcGetChild(0)->vAddNewChild(11);
	c_dynamic_tree3.vPrintTree();

	cout << "\nMove subtree of 3 to 1";
	if (c_dynamic_tree1.bMoveSubtree(c_dynamic_tree1.pcGetRoot()->pcGetChild(0), c_dynamic_tree3.pcGetRoot()->pcGetChild(0)))
	{
		cout << "\nDynamic tree 1: ";
		c_dynamic_tree1.vPrintTree();
		cout << "\nDynamic tree 3: ";
		c_dynamic_tree3.vPrintTree();
	}
	else
	{
		cout << "\nMove failed.";
	}

	cout << "\nMove tree 2 to 1";
	if (c_dynamic_tree1.bMoveSubtree(c_dynamic_tree1.pcGetRoot()->pcGetChild(1), c_dynamic_tree2.pcGetRoot()))
	{
		cout << "\nDynamic tree 1: ";
		c_dynamic_tree1.vPrintTree();
		cout << "\nDynamic tree 2: ";
		c_dynamic_tree2.vPrintTree();
	}
	else
	{
		cout << "\nMove failed\n.";
	}
	*/
	CTreeDynamic c_test_tree;
	c_test_tree.pcGetRoot()->vSetValue(1);
	c_test_tree.pcGetRoot()->vAddNewChild(3);
	c_test_tree.pcGetRoot()->vAddNewChild(8);
	c_test_tree.pcGetRoot()->vAddNewChild(11);
	c_test_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(5);
	c_test_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(28);
	c_test_tree.pcGetRoot()->pcGetChild(2)->vAddNewChild(6);
	c_test_tree.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vAddNewChild(7);

	c_test_tree.vPrintByLevel();
}
