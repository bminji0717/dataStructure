/*
홀수 마방진
- 홀수 N을 입력받아 N^2 크기의 2차원 배열을 동적 할당으로 선언 및 생성한다.
- 모든칸에 중복되지 않게 1~N^2까지 정수를 사용하여 배열 전체를 채운다.
- 이때, 가로 N칸, 세로 N칸, 대각선 N칸의 합은 항상 같아야한다.
- 출력은 1) 정수 배열 전체를 출력하고, 2) 존재 가능한 모든 가로/세로/대각선 세트들의 합 또한 출력하여 이를 검증한다.
- 예를 들어, 3*3 배열이라면 가로 3세트, 세로 3세트, 대각선 방향별 하나(총 2개)가 되어 8세트를 출력하여야 한다.

+ 주의사항: 본 과제에서 배열의 모든 접근은 인덱스 연산자(arr[x])대신 포인터 기법(*(arr+x))를 사용하여 접근 및 수정해야 한다.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, a;

	int N;
	scanf_s("%d", &N);

	if (N <= 0 || N % 2 == 0)
	{
		printf("ERROR");
		return 1;
	}

	int target = 0;
	int sum = 0;

	int* arrPtr = malloc(sizeof(int) * N * N);

	if (arrPtr == NULL)
	{
		printf("ERROR");
		return 1;
	}

	x = 0; // 행
	y = N / 2; // 열

	for (int i = 1; i <= N * N; i++) // 마방진 배열 생성
	{
		*(arrPtr + x * N + y) = i;
		if (i % N == 0) // N의 배수를 넣은 직후에 오른쪽 위로 가면 안 됨 (값이 이미 입력돼 있음)
			x++;
		else
		{
			x--;
			y++;
		}
		if (x < 0) // x나 y가 음수면 맨 마지막 행 또는 열로 이동
			x = N - 1;
		else if (x >= N)
			x = 0;
		if (y >= N)
			y = 0;
	}

	for (int i = 0; i < N; i++) // 배열 출력
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d", *(arrPtr + i * N + j));
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < N; i++) // 기준합 (우하향 대각선)
	{
		a = i * N + i;
		target += *(arrPtr + a);
	}

	printf("top-left to bottom-right diagonal sum = %d\n", target);

	for (int i = 0; i < N; i++) // 좌하향 대각선 검증
	{
		a = i * N + N - i - 1;
		sum += *(arrPtr + a);
	}

	printf("top-right to bottom-left diagonal sum = %d\n", sum);

	if (sum != target)
	{
		printf("ERROR1");
		free(arrPtr);
		return 1;
	}
	sum = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) // 행 검사
			{
				sum += *(arrPtr + i* N + j);
			}

			printf("row %d sum = %d\n", i, sum);

			if (sum == target)
				sum = 0;
			else
			{
				printf("ERROR2");
				free(arrPtr);
				return 1;
			}
		}
		for (int i = 0; i < N; i++) // 열 검사
		{
			for (int j = 0; j < N; j++)
			{
				sum += *(arrPtr + j * N + i);
			}
			printf("column %d sum = %d\n", i, sum);
			if (sum == target)
				sum = 0;
			else
			{
				printf("ERROR3");
				free(arrPtr);
				return 1;
			}
		}

	free(arrPtr);

	return 0;
}