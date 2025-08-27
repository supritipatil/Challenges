#include <stdio.h>
#include <string.h>
int expand(char *s, int l, int r) 
{
    int n = strlen(s);
    while (l >= 0 && r < n && s[l] == s[r]) 
    {
        l--;
        r++;
    }
    return r - l - 1;
}
char* longestPalindrome(char *s) 
{
    int n = strlen(s);
    int start = 0, maxLen = 1;
    for (int i = 0; i < n; i++) 
    {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = len1 > len2 ? len1 : len2;
        if (len > maxLen) 
        {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }
    static char ans[1001];
    strncpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    return ans;
}
int main() 
{
    char s1[] = "babad";
    char s2[] = "cbbd";
    char s3[] = "a";
    char s4[] = "aaaa";
    char s5[] = "abc";
    printf("%s\n", longestPalindrome(s1));
    printf("%s\n", longestPalindrome(s2));
    printf("%s\n", longestPalindrome(s3));
    printf("%s\n", longestPalindrome(s4));
    printf("%s\n", longestPalindrome(s5));
    return 0;
}
