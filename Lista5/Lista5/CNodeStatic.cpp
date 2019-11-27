#include "pch.h"
#include "CNodeStatic.h"
#include <iostream>
#include <vector>

using namespace std;

CNodeStatic::~CNodeStatic()//cos nie tak :////
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		delete pcGetChild(ii);
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic c_new_child;
	c_new_child.pc_parent_node = this;
	v_children.push_back(c_new_child);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= iGetChildrenNumber())return NULL;

	return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		v_children[ii].vPrintAllBelow();
}