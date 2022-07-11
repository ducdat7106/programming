#include "main.h"

int main()
{
    char s[80], s1[80];
    unsigned long position_insert;

    printf("\ninput string root: ");
    inputString(s);

    printf("\ninput string insert: ");
    inputString(s1);

    printf("\nPosition insert string: ");
    scanf("%lu", &position_insert);

    printf("\nString result: %s\n", insertString(s, s1, (size_t)position_insert));

    return 0;
}

char *insertString(char *s, char *s1, size_t k)
{
    char *s2 = strdup(s);

    if (k > strlen(s))
        k = strlen(s);

    strcpy(&s2[k], s1);
    strcpy(&s2[k + strlen(s1)], &s[k]);

    return s2;
}

void inputString(char *str)
{
    char *t;
    fgets(str, 80, stdin);

    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';
}
