#include <stdio.h>
#include <string.h>
#define MAX_CHARS 128
int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    if (len == 0)
    {
        return 0;
    }
    int maxLength = 0;
    int start = 0;
    int lastSeen[MAX_CHARS] = {0};
    for (int end = 0; end < len; end++)
    {
        char currentChar = s[end];
        if (lastSeen[currentChar] > 0)
        {
            if (start < lastSeen[currentChar])
            {
                start = lastSeen[currentChar];
            }
        }
        lastSeen[currentChar] = end + 1;
        int currentLength = end - start + 1;
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
int main()
{
    char *testStrings[] =
    {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "abcdefgh",
        "a",
        "",
        "tmmzuxt"
    };
    int expected[] = {3, 1, 3, 8, 1, 0, 5};
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);
    for (int i = 0; i < numTests; i++)
    {
        char *s = testStrings[i];
        int result = lengthOfLongestSubstring(s);
        printf("String: \"%s\"\n", s);
        printf("Result: %d\n", result);
        printf("Expected: %d\n", expected[i]);
        if (result == expected[i])
        {
            printf("Status: Passed ✅\n");
        }
        else
        {
            printf("Status: Failed ❌\n");
        }
        printf("--------------------\n");
    }
    return 0;
}
