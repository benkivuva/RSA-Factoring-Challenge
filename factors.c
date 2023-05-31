#include <stdio.h>
#include <stdlib.h>

/**
 * Checks if a number is prime.
 * Returns 1 if the number is prime, 0 otherwise.
 */
int is_prime(int num)
{
	int i;
	/* Corner cases */
	if (num <= 1)
		return 0;

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return 0;
	}

	return 1;
}

/**
 * Factorizes a number into two smaller numbers.
 * Prints the factorization in the format: num=factor1*factor2
 * If no factorization is found, prints "No factorization found."
 */
void factorize(int num)
{
	int i;
	int factor = 0;

	printf("%d=", num);

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0 && is_prime(i) && is_prime(num / i))
		{
			factor = i;
			break;
		}
	}

	if (factor != 0)
	{
		printf("%d*%d\n", factor, num / factor);
	}
	else
	{
		printf("No factorization found.\n");
	}
}

int main(void)
{
	FILE *file;
	char line[100];

	file = fopen("tests/test00", "r");

	if (file == NULL)
	{
		printf("Failed to open the file.\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file))
	{
		int num = atoi(line);
		factorize(num);
	}

	fclose(file);

	return 0;
}
