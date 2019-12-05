#pragma once
#include "pch.h"
#include "CTreeDynamic.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

template <typename T> class CNodeDynamic
{
public:
	CNodeDynamic() {pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(T iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	CNodeDynamic *pcGetParent() { return pc_parent_node; };
	void vAddNewChild();
	void vAddNewChild(T iVal);
	void vAddNewChild(CNodeDynamic* pcNewChildNode);
	bool bDetachChild(CNodeDynamic* pcChild);
	void vGetChildren(vector<CNodeDynamic*>*v_all_nodes);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();
	void vPrintBreadth();
private:
	vector<CNodeDynamic *> v_children;
	CNodeDynamic *pc_parent_node;
	T i_val;
};

template <typename T> class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T> *pcGetRoot() { return(pc_root); }
	void vPrintTree();
	void vPrintByLevel();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T> *pc_root;
};

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		delete pcGetChild(ii);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	CNodeDynamic* pc_new_child = new CNodeDynamic();
	pc_new_child->pc_parent_node = this;
	v_children.push_back(pc_new_child);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(T iVal)
{
	CNodeDynamic* pc_new_child = new CNodeDynamic();
	pc_new_child->pc_parent_node = this;
	pc_new_child->vSetValue(iVal);
	v_children.push_back(pc_new_child);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* pcNewChildNode)
{
	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

template <typename T>
bool CNodeDynamic<T>::bDetachChild(CNodeDynamic<T>* pcChild)
{
	typename vector<CNodeDynamic<T>*>::iterator i_position = find(v_children.begin(), v_children.end(), pcChild);
	if (i_position == v_children.end())return false;
	v_children.erase(i_position);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)return NULL;

	return v_children[iChildOffset];
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		v_children[ii]->vPrintAllBelow();
}

template <typename T>
void CNodeDynamic<T>::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)pc_parent_node->vPrintUp();
}

template <typename T>
void CNodeDynamic<T>::vPrintBreadth()
{
	queue<CNodeDynamic *> q_nodes_to_visit;
	q_nodes_to_visit.push(this);
	while (!q_nodes_to_visit.empty())
	{
		int i_nodes_on_level = q_nodes_to_visit.size();
		while (i_nodes_on_level > 0)
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

template <typename T>
void CNodeDynamic<T>::vGetChildren(vector<CNodeDynamic<T>*>*v_all_nodes)
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
	{
		v_all_nodes->push_back(pcGetChild(ii));
		pcGetChild(ii)->vGetChildren(v_all_nodes);
	}
}

template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

template <typename T>
void CTreeDynamic<T>::vPrintByLevel()
{
	pc_root->vPrintBreadth();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL)return false;

	if (pcNewChildNode->pcGetParent() == NULL) return false;

	pcNewChildNode->pcGetParent()->bDetachChild(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}
