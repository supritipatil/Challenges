#include <stdio.h>
int findDuplicate(int arr[], int n) 
{
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow]; // move (1 step)
        fast = arr[arr[fast]]; // move (2 step)
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) 
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main() 
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter %d integers (range 1 to %d):\n", n+1, n);
    for (int i = 0; i <= n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int duplicate = findDuplicate(arr, n);
    printf("Duplicate number: %d\n", duplicate);
    return 0;
}
