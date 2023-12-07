#include <stdio.h>

void swap(char *a[], char *b[]) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void sort_words(char *words[], int count)
{
    for (int i = 0; i < count - 1; ++i)
        for (int j = 0; j < count - i - 1; ++j)
            if (words[j][0] < words[j + 1][0])
                swap(&words[j], &words[j + 1]);
}
#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };
    sort_words(words, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif