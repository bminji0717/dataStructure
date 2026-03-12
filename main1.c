#include <stdio.h>

int main()
{
	float f;

	scanf_s(" %f", &f);

	int a;

	a = f * 256;				// 자릿수 (2^8)

	int b;
	for (int i = 15; i >= 0; i--)
	{		
		b = (a >> i) & 1;		// << 왼쪽, >> 오른쪽
								// x & 1 : LSB 제외 모두 0으로 변환

		printf("%d", b);
		if (i == 8) printf(".");
	}

	return 0;
}