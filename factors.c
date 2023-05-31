#include <stdio.h>
#include <stdlib.h>

int primes[][10] = {{2, 3, 5, 7, 11, 13, 17, 19, 23, 29},
                    {31, 37, 41, 43, 47, 53, 59, 61, 67, 71},
                    {73, 79, 83, 89, 97, 101, 103, 107, 109, 113}};
int primes2[] = {127, 131, 137, 139, 149, 151, 157, 163, 167, 173};
int primes3[] = {179, 181, 191, 193, 197, 199, 211, 223, 227, 229};

/**
 * factorize - Factors a given number into primes
 * @num: The number to be factorized
 */
void factorize(int num)
{
    int i, j;
    int p;

    for (i = 0; i < sizeof(primes) / sizeof(primes[0]); i++)
    {
        for (j = 0; j < sizeof(primes[i]) / sizeof(primes[i][0]); j++)
        {
            p = primes[i][j];
            if (num % p == 0)
            {
                if (p > num / p)
                    printf("%d=%d*%d\n", num, p, num / p);
                else
                    printf("%d=%d*%d\n", num, num / p, p);
                return;
            }
        }
    }

    for (i = 0; i < sizeof(primes2) / sizeof(primes2[0]); i++)
    {
        p = primes2[i];
        if (num % p == 0)
        {
            if (p > num / p)
                printf("%d=%d*%d\n", num, p, num / p);
            else
                printf("%d=%d*%d\n", num, num / p, p);
            return;
        }
    }

    for (i = 0; i < sizeof(primes3) / sizeof(primes3[0]); i++)
    {
        p = primes3[i];
        if (num % p == 0)
        {
            if (p > num / p)
                printf("%d=%d*%d\n", num, p, num / p);
            else
                printf("%d=%d*%d\n", num, num / p, p);
            return;
        }
    }

    printf("%d=%d*%d\n", num, num, 1);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF)
    {
        factorize(num);
    }

    fclose(file);

    return 0;
}
