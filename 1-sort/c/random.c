#include <time.h>
#include <stdlib.h>

void GenerateRandom(int iSize, int *ay, int iRange) 
{
	srand(time(NULL));

	int i;
	for (i = 0; i < iSize; i++) {
		//printf(" %d,", rand()%1000);
		ay[i] = rand()%iRange;
	}
}


