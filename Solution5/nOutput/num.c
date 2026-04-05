#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main()
{
    srand(time(NULL));

	int ary[SIZE];
	int max, min, totalAdd;
	
	totalAdd = 0;

	for (int i = 0; i < SIZE; i++)
	{
		ary[i] = rand() % (SIZE + 1);
		printf("%d ", ary[i]);
		totalAdd += ary[i];
	}

	printf("\n");

	for (int i = SIZE-1; i >= 0; i--)
	{
		printf("%d ", ary[i]);
	}

	printf("\n");

	max = ary[0];
	min = ary[0];

	for (int i = 1; i < SIZE; i++)
	{
		if (max < ary[i])
			max = ary[i];
		if (min > ary[i])
			min = ary[i];
	}

	printf("MAX = %d\nMIN = %d\nADD = %d\n", max, min, totalAdd);

	return 0;
}