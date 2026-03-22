#include <stdio.h>
#include <string.h>

#include "my_fraction.h"

int gcd(int x, int y);
int lcm(int x, int y, int g);

extern myFraction toFrac(char str[])
{
	char* opFindSl = strchr(str, '/');
	char* opFindDot = strchr(str, '.');

	myFraction a = { 0, 1 };

	if (opFindSl != NULL)
	{
		a.numer = atoi(str);
		a.denom = atoi(opFindSl + 1);
	}
	else if (opFindDot != NULL)
	{
		int length = strlen(opFindDot + 1);
		for (int i = 0; i < length; i++)
			a.denom *= 10;
		a.numer = atoi(str) * a.denom + atoi(opFindDot + 1);
	}
	else
	{
		a.numer = atoi(str);
		a.denom = 1;
	}
	return a;
}

extern myFraction add(myFraction a, myFraction b)
{
	a = irreducible(a);
	b = irreducible(b);
	
	int g = gcd(a.denom, b.denom);
	int l = lcm(a.denom, b.denom, g);

	a = rcd(a, l);
	b = rcd(b, l);

	a.numer += b.numer;

	a = irreducible(a);
	
	return a;
}
extern myFraction minus(myFraction a, myFraction b)
{
	a = irreducible(a);
	b = irreducible(b);

	int g = gcd(a.denom, b.denom);
	int l = lcm(a.denom, b.denom, g);

	a = rcd(a, l);
	b = rcd(b, l);

	a.numer -= b.numer;

	a = irreducible(a);

	return a;
}
extern myFraction mult(myFraction a, myFraction b)
{
	a.denom *= b.denom;
	a.numer *= b.numer;

	a = irreducible(a);

	return a;
}
extern myFraction divide(myFraction a, myFraction b)
{
	if (b.numer == 0)
	{
		myFraction err = { 0, 0 };
		return err;
	}

	a.denom *= b.numer;
	a.numer *= b.denom;

	a = irreducible(a);

	return a;
}

extern myFraction irreducible(myFraction i) //기약분수
{
	if (i.denom < 0)
	{
		i.denom = -i.denom;
		i.numer = -i.numer;
	}

	int iG;

	iG = gcd(i.denom, i.numer);
	i.denom /= iG;
	i.numer /= iG;
	return i;
}

extern myFraction rcd(myFraction a, int l) // 통분
{
	l /= a.denom;
	a.denom *= l;
	a.numer *= l;

	return a;
}

int gcd(int x, int y) // y>x이어야 함. y 나눔받는 수, x 나누는 수
{
	if (x < 0) x = -x;
	if (y < 0) y = -y;

	if (x > y)
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
int lcm(int x, int y, int g)
{
	return y / g * x; // g는 공약수이기 때문에 나누어 떨어짐
}