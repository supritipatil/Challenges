#include <stdio.h>
int findElement(int arr[], int n, int k)
{
    int freq[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] + 50000;
        freq[index]++;
    }
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] + 50000;
        if (freq[index] == k)
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    int arr1[] = {2, 3, 4, 2, 2, 5, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", findElement(arr1, n1, 2));

    int arr2[] = {1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", findElement(arr2, n2, 1));
    int arr3[] = {10};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", findElement(arr3, n3, 1));
    int arr4[] = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("%d\n", findElement(arr4, n4, 3));
    int arr5[] = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("%d\n", findElement(arr5, n5, 2));
    return 0;
}
