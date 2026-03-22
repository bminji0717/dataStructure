// 방법1
#include <stdio.h>

int main()
{
	int a = 5;	// a에 임의의 값

	int b = ~a;	// b에 a의 모든 비트 반전한 값

	if (b==-a)	// 만약 b(a 비트 반전) 값이 -a와 같다 (-a == ~a)
	{
		printf("one's complement.\n");
	}
	else		// 비트 반전한 값이 -a가 아니라면
				// 2의 보수 표현에서 -a == ~a+1
	{
		printf("two's complement.\n");
	}

	return 0;
}
