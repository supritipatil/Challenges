#include <stdio.h>
#include <string.h>
#include <ctype.h>
void reverseWords(char *s)
{
    char *words[10000];
    int count = 0, i = 0, n = strlen(s);
    while (i < n && isspace(s[i])) i++;
    while (i < n)
    {
        char *start = s + i;
        while (i < n && !isspace(s[i])) i++;
        s[i] = '\0';
        words[count++] = start;
        while (i < n && isspace(s[i])) i++;
    }
    for (int j = count - 1; j >= 0; j--) 
    {
        printf("%s", words[j]);
        if (j > 0) printf(" ");
    }
}
int main() 
{
    char s[10005];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    reverseWords(s);
    return 0;
}
