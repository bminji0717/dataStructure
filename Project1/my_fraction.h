typedef struct
{	int numer;
	int denom;}myFraction;

extern myFraction toFrac(char str[]);

extern myFraction add(myFraction a, myFraction b);
extern myFraction minus(myFraction a, myFraction b);
extern myFraction mult(myFraction a, myFraction b);
extern myFraction divide(myFraction a, myFraction b);

extern myFraction irreducible(myFraction i);

extern myFraction rcd(myFraction a, int l); // 통분