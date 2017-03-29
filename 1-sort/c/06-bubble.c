#include "lib/utils.h"

/*
 * 由左到右，相鄰兩兩比較，較大者往右挪，最後最大值會出現在陣列右端。
 */
void BubbleSort(int iSize, int *aySrc, int *ayOut)
{
	int i, j;
	for (i = 0; i < iSize; i++) {
		for (j = 0; j < iSize-i-1; j++) {
			if (aySrc[j] > aySrc[j+1]) {
				Swap(aySrc+j, aySrc+j+1);
			}
		}
	}

	for (i = 0; i < iSize; i++) {
		ayOut[i] = aySrc[i];
	}
}
