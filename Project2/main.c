#include <stdio.h>

#include "my_math.h"

int main()
{
	int a, b, result1, result2;
	scanf_s("%d %d", &a, &b);

	result1 = gcd(a, b);
	result2 = lcm(a, b, result1);

	printf("GCD: %d, LCM: %d", result1, result2);
	
	return 0;
}