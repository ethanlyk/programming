#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int s_ayRand[] = {
	19, 911, 93, 16, 270, 961, 959, 938, 581, 960, 47, 792, 464, 423, 497, 7, 177, 16, 940, 924, 649, 523, 580, 486, 258, 63, 292, 679, 119, 167, 185, 138, 430, 631, 507, 701, 592, 466, 991, 173, 426, 39, 317, 242, 462, 167, 602, 991, 535, 542, 916, 184, 417, 848, 22, 675, 912, 315, 355, 383, 834, 892, 873, 264, 523, 380, 317, 115, 199, 309, 640, 977, 700, 958, 220, 514, 125, 822, 506, 660, 716, 774, 196, 133, 622, 218, 808, 886, 885, 515, 269, 719, 408, 495, 984, 931, 875, 653, 47, 426
};

void PrintArray(int *ay, int count) {
	int i;
	for (i = 0; i < count; i++) {
		if (i != 0 && (i % 25) == 0) {
			printf("\n");
		}
		printf("%4d", ay[i]);
	}
}

void ExchangeSort(int iSize, int *aySrc, int *ayOut);
void SelectSort(int iSize, int *aySrc, int *ayOut);
void InsertSort(int iSize, int *aySrc, int *ayOut);
void MergeSort(int iSize, int *aySrc, int *ayOut);
void QuickSort(int iSize, int *aySrc, int *ayOut);
void BubbleSort(int iSize, int *aySrc, int *ayOut);
void HeapSort(int iSize, int *aySrc, int *ayOut);
void RadixSort(int iSize, int *aySrc, int *ayOut);

#define DARRAY_SIZE(ay)	((sizeof(ay))/(sizeof(ay[0])))

struct {
	char *sName;
	void (*Sort)(int iSize, int *aySrc, int *ayOut);
} s_aySort[] = {
	{ "Exchange sort", ExchangeSort },
	{ "Selection sort", SelectSort },
	{ "Insertion sort", InsertSort },
	{ "Merge sort", MergeSort },
	{ "Quick sort", QuickSort },
	{ "Bubble sort", BubbleSort },
	{ "Heap sort", HeapSort },
	{ "Radix sort", RadixSort },
};

//void (*Sort[])(int iSize, int *aySrc, int *ayOut) = { ExchangeSort, SelectionSort };


int main(int argc, char *argv[])
{
	/*
	int ay[100];
 	GenerateRandom(20, ay, 3000);
	PrintArray(ay, 20);
	printf("\n\n");
	*/

	printf("Original data:\n");
	PrintArray(s_ayRand, 100);
	printf("\n\n");

	if (argc != 2) {
		//ExchangeSort(100, s_ayRand, ayOut);
		//Sort[0](100, s_ayRand, ayOut);
		int i;
		for (i = 0; i < DARRAY_SIZE(s_aySort); i++) {
			int aySrc[100] = {0};
			memcpy(aySrc, s_ayRand, 100*sizeof(int));

			int ayOut[100] = {0};
			printf("%d: %s\n", i, s_aySort[i].sName);
			s_aySort[i].Sort(100, aySrc, ayOut);
			PrintArray(ayOut, 100);
			printf("\n\n");
		}
	} else {
		// Function pointer assigment test
		int idx = (argv[1] != NULL) ? atoi(argv[1]) : 1000;
		if (idx < DARRAY_SIZE(s_aySort)) {
			void (*fn)(int, int *, int*) = s_aySort[idx].Sort;

			int ayOut[100] = {0};
			fn(100, s_ayRand, ayOut);

			printf("%s\n", s_aySort[idx].sName);
			PrintArray(ayOut, 100);
		} else {
			printf("No sort applied\n");
		}
		printf("\n\n");
	}
}
