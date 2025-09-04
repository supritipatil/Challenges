#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
} Stack;
Stack* createStack(unsigned capacity)
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(Stack *stack)
{
    return stack->top == (int)stack->capacity - 1;
}
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top];
}
void insertAtBottom(Stack *stack, int item)
{
    if (isEmpty(stack))
    {
        push(stack, item);
        return;
    }
    int temp = pop(stack);
    insertAtBottom(stack, item);
    push(stack, temp);
}
void reverseStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        return;
    }
    int temp = pop(stack);
    reverseStack(stack);
    insertAtBottom(stack, temp);
}
void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d", stack->array[i]);
        if (i < stack->top)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
int main()
{
    Stack *stack = createStack(10000);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    printf("Original Stack: ");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);
    stack->top = -1;
    push(stack, 5);
    printf("\nOriginal Stack: ");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);
    stack->top = -1;
    push(stack, -5);
    push(stack, -10);
    push(stack, -15);
    printf("\nOriginal Stack: ");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);
    stack->top = -1;
    printf("\nOriginal Stack: ");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);
    stack->top = -1;
    push(stack, 3);
    push(stack, 3);
    push(stack, 3);
    printf("\nOriginal Stack: ");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);
    return 0;
}
