#pragma once

void v_alloc_table_add_5(int iSize);

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY);

bool b_alloc_table_p(int ***piTable, int iLen, int iPairSize, int iImpairSize);

bool b_dealloc_table_p(int **piTable, int iLen);
