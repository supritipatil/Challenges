#include <stdio.h>
#include <string.h>
char* longestCommonPrefix(char words[][200], int n) 
{
    static char prefix[200];  
    strcpy(prefix, words[0]);   
    for (int i = 1; i < n; i++) 
    {
        while (strncmp(prefix, words[i], strlen(prefix)) != 0) 
        {
            prefix[strlen(prefix) - 1] = '\0';  
            if (strlen(prefix) == 0) 
            {
                return "";
            }
        }
    }
    return prefix;
}
int main() 
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    if (n == 0) 
    {
        printf("Longest Common Prefix: \"\"\n");
        return 0;
    }
    char words[n][200];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", words[i]);
    }
    char *result = longestCommonPrefix(words, n);
    if (strlen(result) == 0)
        printf("Longest Common Prefix: \"\"\n");
    else
        printf("Longest Common Prefix: \"%s\"\n", result);

    return 0;
}
