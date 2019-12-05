#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL;};
	~CNodeDynamic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	CNodeDynamic *pcGetParent() { return pc_parent_node; };
	void vAddNewChild();
	void vAddNewChild(int iVal);
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
	int i_val;
};

class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic *pcGetRoot() { return(pc_root); }
	void vPrintTree();
	void vPrintByLevel();
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
private:
	CNodeDynamic *pc_root;
};