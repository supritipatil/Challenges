#include <stdio.h>
void sort012(int a[], int n) 
{
    int low = 0, mid = 0, high = n - 1;
    int temp;
    while (mid <= high) 
    {
        if (a[mid] == 0) 
        {
            temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        }
        else if (a[mid] == 1) 
        {
            mid++;
        }
        else {
            temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
}

int main() 
{
    int arr[100], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements (0, 1, 2 only):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort012(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
