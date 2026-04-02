typedef struct
{
	int numer;
	int denom;
}fraction;

typedef struct
{
	fraction per;
	fraction ar;
}square;

extern fraction toFrac(char str[]);

extern square squareCal(fraction h, fraction w);

extern fraction irreducible(fraction i);

extern fraction rcd(fraction a, int l);