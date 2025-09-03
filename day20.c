#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int stack[MAX];
int top = -1;
void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int peek()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
int isEmpty()
{
    return top == -1;
}
void sortedInsert(int val)
{
    if (isEmpty() || peek() <= val)
    {
        push(val);
        return;
    }
    int temp = pop();
    sortedInsert(val);
    push(temp);
}
void sortStack()
{
    if (!isEmpty())
    {
        int temp = pop();
        sortStack();
        sortedInsert(temp);
    }
}
void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    push(3);
    push(1);
    push(4);
    push(2);
    printf("Original Stack: ");
    printStack();
    sortStack();
    printf("Sorted Stack: ");
    printStack();
    return 0;
}
