#include <stdio.h>
#include <string.h>

#include "my.h"

int gcd(int x, int y);
int lcm(int x, int y, int g);

extern fraction toFrac(char str[])
{
	char* opFindSl = strchr(str, '/');
	char* opFindDot = strchr(str, '.');

	fraction a = { 0, 1 };

	if (opFindSl != NULL)
	{
		a.numer = atoi(str);
		a.denom = atoi(opFindSl + 1);
	}
	else if (opFindDot != NULL)
	{
		int range = strlen(opFindDot + 1);
		for (int i = 0; i < range; i++)
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

extern square squareCal(fraction h, fraction w)
{
	fraction circum = { 1, 1 };
	fraction width = { 1, 1 };

	h = irreducible(h);
	w = irreducible(w); // 약분

	int g = gcd(h.denom, w.denom);
	int l = lcm(h.denom, w.denom, g); // 각 분모 사이의 최대공약수 최소공배수

	h = rcd(h, l);
	w = rcd(w, l); // 통분


	// 둘레 2*(h + w)
	circum.denom = h.denom; // 통분됐으니 분모 같음
	circum.numer = 2 * (h.numer + w.numer);

	// 넓이 밑변*높이
	width.denom *= h.denom * w.denom;
	width.numer *= h.numer * w.numer; // 분자 분모 각각 곱

	circum = irreducible(circum);
	width = irreducible(width); // 다시 약분

	square value = { circum, width };
	
	return value;
}

extern fraction irreducible(fraction i)
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



extern fraction rcd(fraction a, int l)
{
	l /= a.denom;
	a.denom *= l;
	a.numer *= l;

	return a;
}

int gcd(int x, int y) // y>x이어야 함. y 나눔받는 수, x 나누는 수
{
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