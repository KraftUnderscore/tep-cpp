#include "pch.h"
#include <iostream>
#include "CMySmartPointer.h"

using namespace std;

int main()
{
	int* pi_test;
	CMySmartPointer<int> c_sp_1(pi_test);
}