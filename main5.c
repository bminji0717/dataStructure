#include <stdio.h>

int main()
{
	char word[100];

	fgets(word, 100, stdin);

	int i = 0;
	while (word[i] != '\0')
	{
		if ('A' <= word[i] && word[i] <= 'Z')
			printf("%c", word[i] + 32);
		else if ('a' <= word[i] && word[i] <= 'z')
			printf("%c", word[i] - 32);
		else
			printf("%c", word[i]);

		i++;
	}
	return 0;
}