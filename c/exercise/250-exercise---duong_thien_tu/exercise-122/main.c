#include "main.h"

#define true 1
#define false 0

int main()
{
    char string_root[80];
    unsigned long result = 0;

    printf("\nInput string root: ");
    inputStrings(string_root);

    printf("\nString root: %s", string_root);
    printf("\nDecimal: %lu", bin2dec(string_root));

    return 0;
}

/*
    bin - binary
    dec - decimal
*/
unsigned long bin2dec(char *str)
{
    unsigned long i, temp = 0, digit = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '0')
            digit = 0;
        else
            digit = 1;

        temp = temp * 2 + digit;
    }

    return temp;
}

void inputStrings(char *str)
{
    char *t;
    fgets(str, 80, stdin);

    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';
}