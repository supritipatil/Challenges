#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
void sortString(char *s) 
{
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (s[i] > s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}
typedef struct 
{
    char **list;
    int size;
    int cap;
    char key[MAX];
} Group;
void add(Group *g, char *word) 
{
    if (g->size == g->cap) 
    {
        g->cap *= 2;
        g->list = realloc(g->list, g->cap * sizeof(char *));
    }
    g->list[g->size] = malloc(strlen(word) + 1);
    strcpy(g->list[g->size], word);
    g->size++;
}
int main() 
{
    char *arr[] = {"eat","tea","tan","ate","nat","bat"};
    int n = sizeof(arr) / sizeof(arr[0]);
    Group *groups = malloc(n * sizeof(Group));
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        char key[MAX];
        strcpy(key, arr[i]);
        sortString(key);
        int found = 0;
        for (int g = 0; g < count; g++) 
        {
            if (strcmp(groups[g].key, key) == 0) 
            {
                add(&groups[g], arr[i]);
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            strcpy(groups[count].key, key);
            groups[count].size = 0;
            groups[count].cap = 2;
            groups[count].list = malloc(2 * sizeof(char *));
            add(&groups[count], arr[i]);
            count++;
        }
    }
    printf("[");
    for (int g = 0; g < count; g++) 
    {
        printf("[");
        for (int w = 0; w < groups[g].size; w++) 
        {
            printf("\"%s\"", groups[g].list[w]);
            if (w < groups[g].size - 1) printf(", ");
        }
        printf("]");
        if (g < count - 1) printf(", ");
    }
    printf("]\n");
    for (int g = 0; g < count; g++) 
    {
        for (int w = 0; w < groups[g].size; w++) 
        {
            free(groups[g].list[w]);
        }
        free(groups[g].list);
    }
    free(groups);
    return 0;
}
