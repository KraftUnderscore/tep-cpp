#include "pch.h"
#include <iostream>
#include "CTable.h"
#include "Functions.h"
int main()
{
	/*CTable c_tab0;
	CTable *pc_tab1 = new CTable();
	CTable *pc_tab2 = new CTable("Tabliczka", 7);
	CTable *pc_tab3 = new CTable(*pc_tab2);

	CTable c_tab;
	CTable *pc_new_tab;
	pc_new_tab = pc_tab3->pcClone();

	c_tab.vPrintAllValues();
	pc_new_tab->vPrintAllValues();

	v_mod_tab(c_tab, 4);
	v_mod_tab(pc_new_tab, 5);

	c_tab.vPrintAllValues();
	pc_new_tab->vPrintAllValues();*/

	CTable *pc_org = new CTable("Tab", 5);
	pc_org->vFillTable();
	pc_org->vPrintAllValues();
	CTable *pc_rev = pc_org->pcGetReverted();
	pc_rev->vPrintAllValues();
}