#include <stdio.h>

static
int count_occurrences(const char *haystack, const char *needle)
{
    int count = 0;
    for (int i = 0; haystack[i] != '\0'; i++)
    {
        int j;
        for (j = 0; needle[j] != '\0' && needle[j] == haystack[i+j]; j++)
            ;
        if (needle[j] == '\0')
            count++;
    }
    return count;
}

int main(void)
{
    {
    const char haystack[] = "house houuse househousehous";
    const char needle[] = "house";

    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+0, needle+0, count_occurrences(haystack+0, needle+0));
    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+1, needle+1, count_occurrences(haystack+1, needle+1));
    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+1, needle+0, count_occurrences(haystack+1, needle+0));
    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+1, needle+2, count_occurrences(haystack+1, needle+2));
    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+6, needle+4, count_occurrences(haystack+6, needle+4));
    }

    {
    char *haystack = "pencil pencil penciil pen penc pe pen55cil penci9llppencil55 pencillip peplic pencilrpencilpe";
    char *needle = "pencil"; 
    printf("Haystack <<%s>> vs needle <<%s>> = %d\n",
           haystack+0, needle+0, count_occurrences(haystack+0, needle+0));
    }

    return 0;
}