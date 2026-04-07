/*
배열 알아보기
- 정수 N을 입력받아 동적 할당으로 배열을 선언하고, 크기가 N인 정수 배열을 생성한다.
- 배열 전체를 0~N의 임의의 수로 채운 뒤, 배열을 포인터를 사용하며 순회하며 다음을 수행한다.
- 처음부터 끝까지 출력해본다.
- 뒤에서부터 처음까지 출력해본다.
- 배열 전체의 총합, 최대값, 최소값을 출력해본다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int N, int* arrPtr, int mood);
int value(int N, int* arrPtr, int mood);

int main()
{
	srand(time(NULL));

	int N;
	scanf_s("%d", &N);

	int total = 0;
	int max, min;

	int* arrPtr = malloc(sizeof(int) * N);

	if (N <= 0)
		printf("ERROR");

	for (int i = 0; i < N; i++)
	{
		*(arrPtr+i) = rand() % N + 1;
		total += *(arrPtr + i);
	}

	printArr(N, arrPtr, 0);
	printArr(N, arrPtr, 1);

	printf("sum: %d\n", total);
	printf("max: %d\n", value(N, arrPtr, 1));
	printf("min: %d\n", value(N, arrPtr, 0));


	free(arrPtr);

	return 0;
}

void printArr(int N, int* arrPtr, int mood)
{
	if (mood == 0) // 정방향 출력
	{
		for (int i = 0; i < N; i++)
		{
			printf("%d ", *(arrPtr + i));
		}
		printf("\n");
	}
	else if (mood == 1) // 역순 출력
	{
		for (int i = N-1; i >= 0; i--)
		{
			printf("%d ", *(arrPtr + i));
		}
		printf("\n");
	}
}

int value(int N, int* arrPtr, int mood)
{
	int result = *arrPtr;

	if (mood == 0) // min
	{
		for (int i = 1; i < N; i++)
		{
			if (result > *(arrPtr + i))
			{
				result = *(arrPtr + i);
			}
		}
	}
	else if (mood == 1) // max
	{
		for (int i = 1; i < N; i++)
		{
			if (result < *(arrPtr + i))
			{
				result = *(arrPtr + i);
			}
		}
	}

	return result;
}