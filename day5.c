#include <stdio.h>
int main() 
{
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int leaders[n];
    int count = 0;
    int maxFromRight = arr[n - 1];
    leaders[count++] = maxFromRight;

    for (i = n - 2; i >= 0; i--) 
    {
        if (arr[i] >= maxFromRight) 
        {
            maxFromRight = arr[i];
            leaders[count++] = arr[i];
        }
    }
    printf("Leaders: ");
    for (i = count - 1; i >= 0; i--) 
    {
        printf("%d ", leaders[i]);
    }
    printf("\n");
    return 0;
}
