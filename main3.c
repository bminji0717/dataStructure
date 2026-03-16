// 방법2
// 1의 보수에는 -0이 존재하고, 2의 보수에는 없음을 이용
#include <stdio.h>

int main()
{
	int a = 0;
	int b = ~0;

	b += 1;

	if (a==b)
	{
		printf("two's complement.\n");
    }
	else printf("one's complement.\n");

	return 0;
}
