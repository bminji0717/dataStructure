// 방법2
// 1의 보수에는 -0이 존재하고, 2의 보수에는 없음을 이용
#include <stdio.h>

int main()
{
	int a = 0;
	int b = ~0;

	int compareA, compareB;
	for (int i = 0; i < 8; i++)
	{
		compareA = (a >> i) & 1;
		compareB = (b >> i) & 1;

		if (compareA != compareB)	// a와 b의 비트를 비교
		{
			printf("two's complement.\n");
			break;
		}
	}
	if (compareA == compareB)
	{
		printf("one's complement.\n");
	}

	return 0;
}