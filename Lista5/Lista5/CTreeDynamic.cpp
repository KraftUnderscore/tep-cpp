#include "pch.h"
#include "CTreeDynamic.h"
#include <iostream>
#include <vector>
#include <algorithm>

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

void CNodeDynamic::vAddNewChild(int iVal)
{
	CNodeDynamic* pc_new_child = new CNodeDynamic();
	pc_new_child->pc_parent_node = this;
	pc_new_child->vSetValue(iVal);
	v_children.push_back(pc_new_child);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic* pcNewChildNode)
{
	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

bool CNodeDynamic::bDetachChild(CNodeDynamic* pcChild)
{
	vector<CNodeDynamic*>::iterator i_position = find(v_children.begin(), v_children.end(), pcChild);
	if (i_position == v_children.end())return false;
	v_children.erase(i_position);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)return NULL;

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
	pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
}

void CTreeDynamic::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL)return false;

	if (pcNewChildNode->pcGetParent() == NULL) return false;

	pcNewChildNode->pcGetParent()->bDetachChild(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}
