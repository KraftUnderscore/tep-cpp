#include "pch.h"
#include "CTreeDynamic.h"
#include <iostream>
#include <vector>

using namespace std;

CNodeDynamic::~CNodeDynamic()
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		delete pcGetChild(ii);
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* pc_new_child = new CNodeDynamic();
	pc_new_child->pc_parent_node = this;
	v_children.push_back(pc_new_child);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= iGetChildrenNumber())return NULL;

	return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		v_children[ii]->vPrintAllBelow();
}

void CNodeDynamic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)pc_parent_node->vPrintUp();
}

CTreeDynamic::CTreeDynamic()
{

}

CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
}

void CTreeDynamic::vPrintTree()
{
	pc_root->vPrintAllBelow();
}