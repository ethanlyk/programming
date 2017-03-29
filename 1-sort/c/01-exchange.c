#include "lib/utils.h"

/*
 * 拿第一個數與其他數做比較，只要數字比第一個小，
 * 則兩數交換，那麼，當全部的數都比過之後，
 * 最小數即找出，且放在第一個位置。
 */
void ExchangeSort(int iSize, int *aySrc, int *ayOut)
{
	int i, j;
	int min;
	for (i = 0; i < iSize; i++) {
		min = aySrc[i];
		for (j = i+1; j < iSize; j++) {
			if (aySrc[j] < min) {
				Swap(&min, aySrc+j);
			}
		}
		ayOut[i] = min;
	}
}

