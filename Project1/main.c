#include <stdio.h>
#include <stdlib.h>

#include "my_fraction.h"

int main()
{
	char frac1[100], op, frac2[100];
	scanf_s("%s %c %s", frac1, 100, &op, 1, frac2, 100);

	myFraction fr1 = toFrac(frac1);
	myFraction fr2 = toFrac(frac2);
	myFraction a = { 0, 1 };

	if (fr1.denom == 0 || fr2.denom == 0) {
		printf("divide by zero");
		return 1;
	}


	if (op == '+')
		a = add(fr1, fr2);
	else if (op == '-')
		a= minus(fr1, fr2);
	else if (op == '*')
		a = mult(fr1, fr2);
	else if (op == '/')
		a = divide(fr1, fr2);

	if (a.denom == 0)
	{
		printf("divide by zero");
		return 1;
	}

	if (a.denom == 1)
		printf("%d", a.numer);
	else
		printf("%d/%d", a.numer, a.denom);

	return 0;
}

