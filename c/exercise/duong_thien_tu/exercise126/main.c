#include "main.h"

int main()
{
    char *str1 = NULL, ch1;
    int *str2 = NULL;

    printf("\nInput char: ");
    ch1 = inputChar();

    printf("\nInput string: ");
    str1 = inputString();

    printf("\nChar input: %c", ch1);
    printf("\nString input: %s", str1);

    str2 = findCharInString(ch1, str1);

    printf("\nPosition: ");
    for (int i = 0; str2[i] != '\0'; i++)
        printf("%d  ", str2[i]);

    free(str1);
    str1 = NULL;

    free(str2);
    str2 = NULL;

    return 0;
}

char *inputString()
{
    char *str = NULL;
    char *t;
    int length = 100;

    str = (char *)malloc(length * sizeof(char));
    if (!str)
        return NULL;

    fflush(stdin);
    fgets(str, length, stdin);
    if ((strrchr(str, '\n')) != NULL)
        *t = '\0';

    return str;
}

char inputChar()
{
    char ch;

    fflush(stdin);
    scanf("%c", &ch);

    return ch;
}

int *findCharInString(char chars, char *strings)
{
    int *str = NULL;
    int counter = 0;
    size_t len = strlen(strings);

    int i, k;

    for (i = 0; i < len; i++)
        if (strings[i] == chars)
            counter++;

    str = (int *)malloc((counter) * sizeof(int));
    if(!str)
        return NULL;

    for (i = 0, k = 0; i < len; i++)
        if (strings[i] == chars)
            str[k++] = i + 1;

    str[k] = '\0';

    return str;
}