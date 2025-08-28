#include <stdio.h>
#include <string.h>
int countSubstringsAtMostK(char *s, int k)
{
    int n = strlen(s);
    int freq[26] = {0};
    int start = 0, end, result = 0;
    for (end = 0; end < n; end++)
    {
        if (freq[s[end] - 'a'] == 0)
            k--;
        freq[s[end] - 'a']++;
        while (k < 0)
        {
            freq[s[start] - 'a']--;
            if (freq[s[start] - 'a'] == 0)
                k++;
            start++;
        }
        result += end - start + 1;
    }
    return result;
}
int countSubstringsExactlyK(char *s, int k)
{
    return countSubstringsAtMostK(s, k) - countSubstringsAtMostK(s, k - 1);
}
int main()
{
    char s[10005];
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    printf("%d\n", countSubstringsExactlyK(s, k));
    return 0;
}
