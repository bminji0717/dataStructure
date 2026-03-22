#include <stdio.h>

#include "my_math.h"

extern gcd(myInteger x, myInteger y) // y>x, y 나눔받는 수, x 나누는 수
{
	if (x == y)
	{
		return x;
	}
	else if (x > y)
	{
		int t = x;
		x = y;
		y = t;
	}
	else;

	int temp;

	while (x != 0)
	{
		temp = x;
		x = y % x;
		y = temp;
	}
	return y;
}
extern lcm(myInteger x, myInteger y, myInteger g)
{
	return y / g * x;
}