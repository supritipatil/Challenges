#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10000
char stack[MAX];
int top = -1;
void push(char c) 
{
    if (top < MAX - 1) stack[++top] = c;
}
char pop() 
{
    return (top >= 0) ? stack[top--] : '\0';
}
char peek() 
{
    return (top >= 0) ? stack[top] : '\0';
}
bool isValid(char *s) 
{
    int len = strlen(s);
    if (len % 2 != 0) return false;
    top = -1;
    for (int i = 0; i < len; i++) 
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') 
        {
            push(c);
        } else {
            char last = peek();
            if ((c == ')' && last == '(') ||
                (c == '}' && last == '{') ||
                (c == ']' && last == '[')) 
            {
                pop();
            } else {
                return false;
            }
        }
    }
    return top == -1;
}
int main() 
{
    char *tests[] = {"()", "([)]", "[{()}]", "", "{[}"};
    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) 
    {
        printf("Input: \"%s\" -> Output: %s\n", tests[i], isValid(tests[i]) ? "true" : "false");
    }
    return 0;
}
