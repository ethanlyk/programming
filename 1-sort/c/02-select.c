#include "lib/utils.h"

/*
 * 在此陣列中搜尋出最小的，放在第一個位置，第二小的放在第二個位置，直至全部都排列完成。
 */
void SelectSort(int iSize, int *aySrc, int *ayOut)
{
	int i, j;
	int min, idx;
	for (i = 0; i < iSize; i++) {
		idx = i;
		min = aySrc[i];
		for (j = i+1; j < iSize; j++) {
			if (aySrc[j] < min) {
				idx = j;
				min = aySrc[j];
			}
		}
		ayOut[i] = aySrc[idx];
		Swap(aySrc+i, aySrc+idx);
	}
}
