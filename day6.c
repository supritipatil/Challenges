#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    long long sum;
    int index;
    struct Node* next;
};
#define SIZE 200003
struct Node* hashTable[SIZE];
int hashFunc(long long sum) 
{
    if (sum < 0) sum = -sum;
    return (int)(sum % SIZE);
}
void insert(long long sum, int index) 
{
    int key = hashFunc(sum);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[key];
    hashTable[key] = newNode;
}
void findZeroSumSubarrays(int arr[], int n) 
{
    long long prefixSum = 0;
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
    insert(0, -1);
    for (int i = 0; i < n; i++) 
    {
        prefixSum += arr[i];
        int key = hashFunc(prefixSum);
        struct Node* temp = hashTable[key];
        while (temp) {
            if (temp->sum == prefixSum) 
            {
                printf("(%d, %d)\n", temp->index + 1, i);
            }
            temp = temp->next;
        }
        insert(prefixSum, i);
    }
}
int main() 
{
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findZeroSumSubarrays(arr, n);
    return 0;
}
