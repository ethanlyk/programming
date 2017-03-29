#include "lib/utils.h"

/*
 * 陣列當作是 heap(二元樹資料結構) ，將數列轉換成Max Heap。
 * 逐一由最後節點依序與 Root 交換，再調整為 Max Heap，達到排序功效。
 * 
 */
#define DLEFT_CHILD(idx) 	(((idx)+1)*2-1)
#define DRIGHT_CHILD(idx) (((idx)+1)*2)
#define DPARENT(idx) 			(((idx)-1)/2)

typedef enum { false, true } bool;

bool Exist(int idx, int iSize) {
	return (idx < iSize);
}

bool TestAndSwap(int *ay, int iMax, int iMin)
{
	bool bSwap = false;

	if (ay[iMax] > ay[iMin]) {
		Swap(ay+iMax, ay+iMin);
		bSwap = true;
	}

	return bSwap;
}

bool IsLeaf(int i, int iSize)
{
	return (Exist(DLEFT_CHILD(i), iSize)==false && Exist(DRIGHT_CHILD(i), iSize)==false);
}

void MaxHeapify(int iSize, int *aySrc)
{
	int i;
	for (i = iSize-1; i >= 0; i--) {
		if (!IsLeaf(i, iSize)) {
			// Adjust max-heap from current node down to leaf
			int iCurrent = i;
			bool bContinue = true;
			while (bContinue) {
				int iMaxChild;
				if (Exist(DRIGHT_CHILD(iCurrent), iSize)) {
					iMaxChild = (aySrc[DLEFT_CHILD(iCurrent)] > aySrc[DRIGHT_CHILD(iCurrent)]) ? 
												DLEFT_CHILD(iCurrent) : DRIGHT_CHILD(iCurrent);
				} else if (Exist(DLEFT_CHILD(iCurrent), iSize)) {
					// Left child only
					iMaxChild = DLEFT_CHILD(iCurrent);
				} else {
					// Left node
					bContinue = false;
				}

				if (bContinue == true) {
					if (TestAndSwap(aySrc, iMaxChild, iCurrent) == true) {
						iCurrent = iMaxChild;
					} else {
						bContinue = false;
					}
				}
			}
		}
	}
}

void HeapSort(int iSize, int *aySrc, int *ayOut)
{
	MaxHeapify(iSize, aySrc);

	int i, iDone;
	for (i = iSize-1; i > 0; i--) {
		Swap(aySrc+0, aySrc+i);
		// 'i' means the size of un-sorted array after swap
		MaxHeapify(i, aySrc);
	}

	for (i = 0; i < iSize; i++) {
		ayOut[i] = aySrc[i];
	}
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
	HeapSort(iSize, aySrc, ayOut);
	printf("\n\n");
	PrintArray(ayOut, iSize);
	printf("\n\n");

	free(ayOut);
}
#endif

