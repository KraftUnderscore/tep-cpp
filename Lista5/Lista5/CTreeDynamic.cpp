#include "pch.h"
#include "CTreeDynamic.h"
#include <iostream>
#include <vector>
#include <queue>
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

void CNodeDynamic::vPrintBreadth()
{
	queue<CNodeDynamic *> q_nodes_to_visit;
	q_nodes_to_visit.push(this);
	while (!q_nodes_to_visit.empty())
	{
		int i_nodes_on_level = q_nodes_to_visit.size();
		while (i_nodes_on_level>0)
		{
			CNodeDynamic* pc_current_node = q_nodes_to_visit.front();
			for (int ii = 0; ii < pc_current_node->iGetChildrenNumber(); ii++)
			{
				q_nodes_to_visit.push(pc_current_node->pcGetChild(ii));
			}
			q_nodes_to_visit.front()->vPrint();
			q_nodes_to_visit.pop();
			i_nodes_on_level--;
		}
		cout << "\n";
	}
}

void CNodeDynamic::vGetChildren(vector<CNodeDynamic*>*v_all_nodes)
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
	{
		v_all_nodes->push_back(pcGetChild(ii));
		pcGetChild(ii)->vGetChildren(v_all_nodes);
	}
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

void CTreeDynamic::vPrintByLevel()
{
	pc_root->vPrintBreadth();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL)return false;

	if (pcNewChildNode->pcGetParent() == NULL) return false;

	pcNewChildNode->pcGetParent()->bDetachChild(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}
