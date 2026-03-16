#include <stdio.h>

int main()
{
	union
	{
		float f;
		unsigned int bit;
	} a;

	scanf_s("%f", &a.f);
	
	for (int i = 31; i >= 0; i--)
	{
		unsigned int b;
		b = (a.bit >> i) & 1;

		printf("%u", b);
	}

	return 0;
}