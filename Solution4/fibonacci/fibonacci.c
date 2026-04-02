#include <stdio.h>

long long fibonacci(int n);
int gcd(long long x, long long y);

int main()
{
	int g, n;
	long long f1, f2;
	
	n = 40;

	f1 = fibonacci(n-1);
	f2 = fibonacci(n);
	
	g = gcd(f1, f2);

	printf("Fibonacci Number: %lld, %lld\n", f1, f2);
	printf("GCD: %d\n", g);

	return 0;
}

long long fibonacci(int n)
{
	if (n < 0)
	{
		printf("ERROR");
		return -1;
	}
	if (n <= 1) return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(long long x, long long y)
{
	long long temp;
	
	while (x != 0)
	{
		temp = x;
		x = y % x;
		y = temp;
	}

	return y;
}