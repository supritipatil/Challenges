#include <stdio.h>
#include <math.h>
void primeFactorization(int n)
{
    while (n % 2 == 0)
    {
        printf("2 ");
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        printf("%d ", n);
    }
    printf("\n");
}
int main()
{
    int N;
    N = 18;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    N = 30;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    N = 49;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    N = 19;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    N = 64;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    N = 123456;
    printf("Prime factors of %d are: ", N);
    primeFactorization(N);
    return 0;
}
