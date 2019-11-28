#include "pch.h"
#include "CTreeStatic.h"
#include <iostream>
#include <vector>

using namespace std;

CNodeStatic::~CNodeStatic()
{

}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic c_new_child;
	c_new_child.pc_parent_node = this;
	v_children.push_back(c_new_child);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)return NULL;

	return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		v_children[ii].vPrintAllBelow();
}

void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)pc_parent_node->vPrintUp();
}

CTreeStatic::CTreeStatic()
{

}

CTreeStatic::~CTreeStatic()
{

}

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
}