#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 1000
int isOperator(char *token)
{
    return strlen(token) == 1 && (*token == '+' || *token == '-' || *token == '*' || *token == '/' || *token == '^');
}
int applyOp(int a, int b, char op)
{
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    if(op == '^') return (int)pow(a, b);
    return 0;
}
int evaluatePostfix(char *expr)
{
    int stack[MAX], top = -1;
    char *token = strtok(expr, " ");
    while(token != NULL)
    {
        if(isOperator(token))
        {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOp(a, b, token[0]);
        }
        else
        {
            stack[++top] = atoi(token);
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}
int main()
{
    char input[MAX];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    printf("%d\n", evaluatePostfix(input));
    return 0;
}
