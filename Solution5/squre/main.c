//홀수 마방진
// 위 방식으로 홀수 N을 선언하고, N ^ 2 크기의 2차원 배열을 생성한다.
// 모든칸에 중복되지 않게 1~N ^ 2까지 정수를 사용하여 배열 전체를 채운다.
// 이때, 가로 N칸, 세로 N칸, 대각선 N칸의 합은 항상 같아야한다.
// 출력은 1) 정수 배열 전체를 출력하고, 2) 존재 가능한 모든 가로 / 세로 / 대각선 세트들의 합 또한 출력하여 이를 검증한다.
// 예를들어, 3 * 3 배열이라면 가로 3세트, 세로 3세트, 대각선 방향별 하나(총 2개)가 되어 8세트를 출력하여야 한다.

#include <stdio.h>

#define N 9

int main()
{
	int x, y;
	int arr[N][N] = { 0, };

	int target = 0;
	int sum = 0;

	x = 0;
	y = N / 2;

	for (int i = 1; i <= N*N; i++) // 마방진 배열 생성
	{
		arr[x][y] = i;
		if (i % N == 0) // N의 배수를 넣은 직후에 오른쪽 위로 가면 안 됨 (값이 이미 입력돼 있음)
			x++;
		else
		{
			x--;
			y++;
		}
		if (x < 0) // x나 y가 음수면 맨 마지막 행 또는 열로 이동
			x = N - 1;
		if (y >= N)
			y = 0;
	}

	for (int i = 0; i < N; i++) // 배열 출력
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < N; i++) // 기준합 (우하향 대각선)
	{
		target += arr[i][i];
	}

	printf("top-left to bottom-right diagonal sum = %d\n", target);

	for (int i = N-1; i >= 0; i--) // 좌하향 대각선 검증
	{
			sum += arr[N-i-1][i];
	}

	printf("top-right to bottom-left diagonal sum = %d\n", sum);

	if (sum != target)
	{
		printf("ERROR");
		return 1;
	}
	else
	{
		sum = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) // 행 검사
			{
				sum += arr[i][j];
			}

			printf("row %d sum = %d\n", i, sum);

			if (sum == target)
				sum = 0;
			else
			{
				printf("ERROR");
				return 1;
			}
		}
		for (int i = 0; i < N; i++) // 열 검사
		{
			for (int j = 0; j < N; j++)
			{
				sum += arr[j][i];
			}
			printf("column %d sum = %d\n", i, sum);
			if (sum == target)
				sum = 0;
			else
			{
				printf("ERROR");
				return 1;
			}
		}
	}


	return 0;
}