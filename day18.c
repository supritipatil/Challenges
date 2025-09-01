#include <stdio.h>
#include <math.h>
long long countDivisors(int n)
{
    if (n == 1)
    {
        return 1;
    }
    long long count = 1;  
    int exponent = 0;
    while (n % 2 == 0)
    {
        exponent++;
        n /= 2;
    }
    if (exponent > 0)
    {
        count *= (exponent + 1);
    }   
    for (int i = 3; i * i <= n; i += 2)
    {
        exponent = 0;
        while (n % i == 0)
        {
            exponent++;
            n /= i;
        }
        if (exponent > 0)
        {
            count *= (exponent + 1);
        }
    }    
    if (n > 2)
    {
        count *= 2;
    }    
    return count;
}
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);    
    if (n < 1)
    {
        printf("Please enter a positive integer.\n");
    }
    else
    {
        printf("The total number of divisors of %d is: %lld\n", n, countDivisors(n));
    } 
    return 0;
}
