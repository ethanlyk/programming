#include <stdlib.h>
#include <string.h>

/*
 * 將整數按位數切割成不同的數字，然後按每個位數分別比較
 */
void RadixSort(int iSize, int *aySrc, int *ayOut)
{
	// Use 0~9 bucket to store iSize elements for each bucket
	int *ayBucket = malloc(10*iSize*sizeof(int));
	int ayBucketCount[10] = {0};

	int iMax = -1;
	int i, j;
	for (i = 0; i < iSize; i++) {
			if (iMax < aySrc[i]) {
				iMax = aySrc[i];
			}
	}
	
	int iRadix = 1;
	do {
		int iBucketIdx;
		for (i = 0; i < iSize; i++) {
			iBucketIdx = (aySrc[i] / iRadix) % 10;
			int iIdxWithinBucket = ayBucketCount[iBucketIdx];
			ayBucket[iBucketIdx*iSize+iIdxWithinBucket] = aySrc[i];
			ayBucketCount[iBucketIdx]++;
		}

		// Use original array to store sorted data
		int idx = 0;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < ayBucketCount[i]; j++) {
				aySrc[idx++] = ayBucket[i*iSize+j];
			}
		}

		memset(ayBucket, 0, 10*iSize*sizeof(int));
		memset(ayBucketCount, 0, 10*sizeof(int));

		iRadix *= 10;
		iMax /= 10;
	} while (iMax);

	for (i = 0; i < iSize; i++) {
		ayOut[i] = aySrc[i];
	}

	free(ayBucket);
}

#ifdef __SELF_TEST__

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *ay, int count) {
	int i;
	for (i = 0; i < count; i++) {
		if (i != 0 && (i % 10) == 0) {
			printf("\n");
		}
		printf("%4d", ay[i]);
	}
}

#define DARRAY_SIZE(ay)	((sizeof(ay))/(sizeof(ay[0])))

void main()
{
	int aySrc[] = { 14, 51, 92, 79, 45, 2, 75, 70, 3, 57 };
	int iSize = DARRAY_SIZE(aySrc);

	int *ayOut = malloc(iSize*sizeof(int));

	PrintArray(aySrc, iSize);

	RadixSort(iSize, aySrc, ayOut);
	printf("\n\n");

	free(ayOut);
}
#endif

