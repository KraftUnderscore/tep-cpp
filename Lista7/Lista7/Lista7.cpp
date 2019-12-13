#include "pch.h"
#include <iostream>
#include "CMySmartPointer.h"
#include "CTabSmartPointer.h"

using namespace std;

void v_test()
{
	cout << "1 pointer\n";
	CMySmartPointer<int> pc_sp1(new int(10));
	cout << *pc_sp1 << "\n";
	int *pi_test;
	pi_test = new int(20);
	CMySmartPointer<int> pc_sp2(pi_test);
	cout << "2 pointer: ";
	cout << *pc_sp2 << "\n";
	cout << "operator=\n";
	pc_sp2 = pc_sp1;
	cout << "2 pointer: ";
	*pc_sp2 = 15;
	cout << *pc_sp1;
	cout << "\norig 2 pointer: ";
	cout << *pi_test << "\n";
	cout << "smart pointer to static: ";
	int i_int = 100;
	CMySmartPointer<int> pc_sp3(&i_int);
}

int main()
{
	//v_test();
	int** pi_tab;
	pi_tab = new int*[10];
	for (int ii = 0; ii < 10; ii++)
	{
		pi_tab[ii] = new int[10];
		for (int ij = 0; ij < 10; ij++)
		{
			pi_tab[ii][ij] = 10;
		}
	}
	CTabSmartPointer<int> pc_tp(pi_tab, 10);
	for (int ii = 0; ii < 10; ii++)
	{
		for (int ij = 0; ij < 10; ij++)
		{
			cout << pi_tab[ii][ij] <<" ";
		}
		cout << "\n";
	}
	int** pi_tab_2;
	pi_tab_2 = new int*[10];
	for (int ii = 0; ii < 10; ii++)
	{
		pi_tab_2[ii] = new int[10];
		for (int ij = 0; ij < 10; ij++)
		{
			pi_tab_2[ii][ij] = 9;
		}
	}
	CTabSmartPointer<int> pc_tp2(pi_tab_2, 10);
	pc_tp = pc_tp2;
	for (int ii = 0; ii < 10; ii++)
	{
		for (int ij = 0; ij < 10; ij++)
		{
			cout << pi_tab[ii][ij] << " ";
		}
		cout << "\n";
	}
}