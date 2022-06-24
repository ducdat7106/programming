#include "main.h"

int main()
{
    char ch1;
    char *str1 = NULL;

    // printf("\nInput char: ");
    // ch1 = inputChar();
    // printf("\nChar input: %c", ch1);

    printf("\nInput string: ");
    str1 = inputString();
    printf("\nerror1");
    printf("\nString input: %s", str1);
    printf("\nerror2");


    free(str1);
    str1 = NULL;

    return 0;
}

char *inputString()
{
    char *str = NULL;
    char *t = NULL;
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