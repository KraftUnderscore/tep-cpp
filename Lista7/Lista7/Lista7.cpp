#include "pch.h"
#include <iostream>
#include "CMySmartPointer.h"

using namespace std;

int main()
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
	cout << *pi_test<<"\n";
}