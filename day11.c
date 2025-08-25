#include <stdio.h>
#include <string.h>
void swap(char *a, char *b) 
{
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char *s, int l, int r) 
{
    if (l == r) {
        printf("%s\n", s);
        return;
    }
    int used[256] = {0};
    for (int i = l; i <= r; i++) 
    {
        if (used[(int)s[i]]) continue;
        used[(int)s[i]] = 1;
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}
int main() 
{
    char s[20];
    scanf("%s", s);
    permute(s, 0, strlen(s) - 1);
    return 0;
}
