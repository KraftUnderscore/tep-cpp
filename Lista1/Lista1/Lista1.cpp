#include "pch.h"
#include <iostream>

void v_alloc_table_add_5(int i_size)
{
	//zabezpieczenie przed zlym rozmiarem
	if (i_size < 0)
	{
		std::cout << "Niepoprawny rozmiar tablicy.";
	}
	else
	{
		//alokacja
		int *pi_table;
		pi_table = new int[i_size];
		for (int ii; ii < i_size; ii++)
		{
			pi_table[ii] = ii + 5;
		}
		//wypisz wartosci
		for (int ii; ii < i_size; ii++)
		{
			std::cout << pi_table[ii]<<"\n";
		}
		//dealokacja
		delete pi_table;
	}
}

int main()
{
	v_alloc_table_add_5(5);
}