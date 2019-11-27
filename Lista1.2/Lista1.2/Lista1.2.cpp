#include "pch.h"
#include <iostream>
#include "Functions.h"

int main()
{
	std::cout << "Alloc 1d table\n";
	v_alloc_table_add_5(5);
	int** piTable;
	std::cout << "Alloc 2d table\n";
	std::cout << b_alloc_table_2_dim(&piTable, 5, 3) << "\n";
	std::cout << "Dealloc 2d table\n";
	std::cout << b_dealloc_table_2_dim(piTable, 5, 3) << "\n";

	int** piTableP;
	std::cout << "Alloc p table\n";
	std::cout << b_alloc_table_p(&piTableP, 10, 4, 7) << "\n";
	std::cout << "Dealloc p table\n";
	std::cout << b_dealloc_table_p(piTableP, 10);
}
