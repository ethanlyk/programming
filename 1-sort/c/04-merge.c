#include <stdlib.h>

/*
 * （1）將數列分成（divide）兩個子數列，每一個數列擁有n/2個數字。 直到只剩一個數字
 * （2）結合（merge）每一個子數列做排序使之成為單一數列。
 */
void MergeSort(int iSize, int *aySrc, int *ayOut)
{
	if (iSize == 1) {
		*ayOut = *aySrc;
	} else {
		int iLeftSize = iSize / 2;
		int *ayLeft = malloc(iLeftSize*sizeof(int));
		MergeSort(iLeftSize, aySrc, ayLeft);

		int iRightSize = iSize - iLeftSize;
		int *ayRight = malloc(iRightSize*sizeof(int));
		MergeSort(iRightSize, aySrc+iLeftSize, ayRight);

		int i, j, k;
		int idx = 0, idxRight = 0;
		for (i = 0; i < iLeftSize; i++) {
			j = idxRight;
			for ( ; j < iRightSize; j++) {
				if (ayLeft[i] <= ayRight[j]) {
					ayOut[idx++] = ayLeft[i];
					if (i == iLeftSize-1) {
						// Copy the rest of right array
						for (k = j; k < iRightSize; k++) {
							ayOut[idx++] = ayRight[k];
						}
					}
					break;
				} else {
					ayOut[idx++] = ayRight[j];
					idxRight = j+1;
					if (j == iRightSize-1) {
						// Copy the rest of left array
						for (k = i; k < iLeftSize; k++) {
							ayOut[idx++] = ayLeft[k];
						}
						i = iLeftSize;
					}
				}
			}
		}


		free(ayLeft);
		free(ayRight);
	}
}

/*
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

	MergeSort(4, aySrc, ayOut);
	PrintArray(ayOut, 4);
	printf("\n\n");

	int aySrc4[] = { 93, 911, 19, 16 };
	int ayOut4[4] = {0};

	MergeSort(4, aySrc4, ayOut4);
	PrintArray(ayOut4, 4);
	printf("\n\n");

	int aySrc5[] = { 93, 911, 19, 16, 270 };
	int ayOut5[5] = {0};

	MergeSort(5, aySrc5, ayOut5);
	PrintArray(ayOut5, 5);
	printf("\n\n");

	int aySrc6[] = { 93, 911, 19, 16, 270, 961 };
	int ayOut6[6] = {0};

	MergeSort(6, aySrc6, ayOut6);
	PrintArray(ayOut6, 6);
	printf("\n\n");

	int aySrc6a[] = { 93, 16, 270, 961, 911, 19 };
	int ayOut6a[6] = {0};

	MergeSort(6, aySrc6a, ayOut6a);
	PrintArray(ayOut6a, 6);
	printf("\n\n");
}
*/
