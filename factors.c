#include <stdio.h>
#include <stdlib.h>

void factorize(int num);

int primes[][8] = {
    {2, 3, 5, 7, 11, 13, 17, 19},
    /* Add more prime numbers here if needed */
};

int primes2[] = {23, 29, 31, 37, 41, 43, 47, 53};

int primes3[] = {59, 61, 67, 71, 73, 79, 83, 89, 97};

int main(int argc, char* argv[])
{
    FILE* file;
    char line[256];
    int num;

    if (argc != 2)
    {
        printf("USAGE: factors <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        num = atoi(line);
        factorize(num);
    }

    fclose(file);

    return 0;
}

void factorize(int num)
{
    size_t j;  
    int i;
    int p;

    printf("%d=", num);

    for (i = 0; i < 1; i++)
    {
      for (j = 0; j < sizeof(primes[i]) / sizeof(primes[i][0]); j++)
        {
            p = primes[i][j];
            if ((unsigned int)num % p == 0)
            {
                if (p > num / p)
                    printf("%d=%d*%d\n", num, p, num / p);
                else
                    printf("%d=%d*%d\n", num, num / p, p);
                return;
            }
        }
    }
       for (i = 0; i < (int)(sizeof(primes2) / sizeof(primes2[0])); i++)
     {
        p = primes2[i];
        if ((unsigned int)num % p == 0)
        {
            if (p > num / p)
                printf("%d=%d*%d\n", num, p, num / p);
            else
                printf("%d=%d*%d\n", num, num / p, p);
            return;
        }
    }

    for (i = 0; i < (int)(sizeof(primes3) / sizeof(primes3[0])); i++)
    {
        p = primes3[i];
        if ((unsigned int)num % p == 0)
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
