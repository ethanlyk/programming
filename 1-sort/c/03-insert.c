#include <string.h>

#include "lib/utils.h"

/*
 * 將數字插入已排序的數列中
 */
void InsertSort(int iSize, int *aySrc, int *ayOut)
{
	int i, j;
	for (i = 0; i < iSize-1; i++) {
		int candidate = aySrc[i+1];
		for (j = i; j > -1; j--) {
			if (candidate < aySrc[j]) {
				Swap(aySrc+j, aySrc+(j+1));
			}
		}
	}

	memcpy(ayOut, aySrc, sizeof(int)*iSize);
}

