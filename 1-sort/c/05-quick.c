#include <stdlib.h>

/*
 * 先找一個指標（為求方便，通常是第一個數），將，數列中大於這個指標的數，都放在右邊，反之則放在左邊。
 */
void QuickSort(int iSize, int *aySrc, int *ayOut)
{
	if (iSize == 0) {
		return;
	} else if (iSize == 1) {
		*ayOut = *aySrc;
	} else {
		int iLeftSize = 0;
		int *ayLeft = malloc(iSize*sizeof(int));
		int iRightSize = 0;
		int *ayRight = malloc(iSize*sizeof(int));

		int iPivot = aySrc[0];
		int i;
		for (i = 1; i < iSize; i++) {
			if (aySrc[i] < iPivot) {
				ayLeft[iLeftSize++] = aySrc[i];
			} else {
				ayRight[iRightSize++] = aySrc[i];
			}
		}

		int *ayLeftOut = malloc(iLeftSize*sizeof(int));
		QuickSort(iLeftSize, ayLeft, ayLeftOut);
		for (i = 0; i < iLeftSize; i++) {
			ayOut[i] = ayLeftOut[i];
		}

		ayOut[iLeftSize] = iPivot;

		int *ayRightOut = malloc(iRightSize*sizeof(int));
		QuickSort(iRightSize, ayRight, ayRightOut);
		for (i = 0; i < iRightSize; i++) {
			ayOut[i+(iLeftSize+1)] = ayRightOut[i];
		}

		free(ayLeftOut);
		free(ayRightOut);
		free(ayLeft);
		free(ayRight);
	}
}

#ifdef __SELF_TEST__

#include <stdio.h>
void PrintArray(int *ay, int count) {
	int i;
	for (i = 0; i < count; i++) {
		if (i != 0 && (i % 10) == 0) {
			printf("\n");
		}
		printf("%4d", ay[i]);
	}
}

void main(void)
{
	int aySrc[] = { 19, 911, 93, 16 };
	int ayOut[4] = {0};

	QuickSort(4, aySrc, ayOut);
	PrintArray(ayOut, 4);
	printf("\n\n");

	int aySrc4[] = { 93, 911, 19, 16 };
	int ayOut4[4] = {0};

	QuickSort(4, aySrc4, ayOut4);
	PrintArray(ayOut4, 4);
	printf("\n\n");

	int aySrc5[] = { 93, 911, 19, 16, 270 };
	int ayOut5[5] = {0};

	QuickSort(5, aySrc5, ayOut5);
	PrintArray(ayOut5, 5);
	printf("\n\n");

	int aySrc6[] = { 93, 911, 19, 16, 270, 961 };
	int ayOut6[6] = {0};

	QuickSort(6, aySrc6, ayOut6);
	PrintArray(ayOut6, 6);
	printf("\n\n");

	int aySrc6a[] = { 93, 16, 270, 961, 911, 19 };
	int ayOut6a[6] = {0};

	QuickSort(6, aySrc6a, ayOut6a);
	PrintArray(ayOut6a, 6);
	printf("\n\n");
}

#endif
