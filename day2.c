#include <stdio.h>
int main() 
{
    int n, i;
    int sum = 0;
    int expectedSum, missing;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n-1];
    printf("Enter %d elements from 1 to %d (one number will be missing):\n", n-1, n);
    for(i = 0; i < n-1; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n-1; i++) 
    {
        sum = sum + arr[i];
    }
    expectedSum = n * (n + 1) / 2;
    missing = expectedSum - sum;
    printf("The missing number is: %d\n", missing);
    return 0;
}
