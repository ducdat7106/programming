#include "main.h"

int main()
{
    char ch;
    // char *s1 = NULL, *s2 = NULL;
    char *s3 = NULL;

    // s1 = (char *)malloc(80 * sizeof(char));
    // s2 = (char *)malloc(80 * sizeof(char));
    
    char s1[] = "1000001";
    char s2[] =    "1111";


    // printf("Input String one: \n");
    // inputString(s1);

    // printf("Input string two: \n");
    // inputString(s2);

tt: printf("\nResult input: ");
    printString(s1);
    printString(s2);

    s3 = summationBinary(s1, s2);
    printf("\nResult convert: ");
    printString(s3);

    // free(s1);
    // s1 = NULL;

    // free(s2);
    // s2 = NULL;

    free(s3);
    s3 = NULL;

    stopScreen();

    printf("\nPress enter to continue!!\n");
    fflush(stdin);
    ch = getch();
    if (ch == 13)
        goto tt;

    return 0;
}

void clearScreen()
{
    system("cls");
}

void stopScreen()
{
    putchar('\n');
    system("pause");
}

void inputString(char *str)
{
    char *t = NULL;

    fflush(stdin);
    fgets(str, 80, stdin);

    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';
}

void printString(char *str)
{
    printf("\n\tOutput String: %20s", str);
}

char *summationBinary(char *str_a, char *str_b)
{
    size_t len_a, len_b;
    int len_c, t, carry;

    int value_a, value_b;

    char *str_c = NULL;

    len_a = strlen(str_a);
    len_b = strlen(str_b);

    len_c = (len_a >= len_b) ? (len_a + 1) : (len_b + 1);

    str_c = (char *)malloc((len_c + 1) * sizeof(char));
    if (!str_c)
        return NULL;
    str_c[len_c] = '\0';

    carry = 0;
    // string a and b still element
    while (len_a && len_b) // len_a != 0 && len_b != 0
    {
        if (str_a[len_a - 1] == '0')
            value_a = 0;
        else
            value_a = 1;

        if (str_b[len_b - 1] == '0')
            value_b = 0;
        else
            value_b = 1;

        t = value_a + value_b + carry;
        carry = t / 2;
        str_c[len_c - 1] = (t % 2) + 48;

        len_a--;
        len_b--;
        len_c--;
    }

    // String a or b still element
    while (len_a) // len_a != 0
    {
        if (str_a[len_a - 1] == '0')
            value_a = 0;
        else
            value_a = 1;

        t = value_a + carry;
        carry = t / 2;
        str_c[len_c - 1] = (t % 2) + 48;

        len_a--;
        len_c--;
    }

    while (len_b) // len_b != 0
    {
        if (str_b[len_b - 1] == '0')
            value_b = 0;
        else
            value_b = 1;

        t = value_b + carry;
        carry = t / 2;
        str_c[len_c - 1] = (t % 2) + 48;

        len_b--;
        len_c--;
    }

    // String a and b no more element
    if (carry)
        str_c[len_c - 1] = 1 + 48;
    else
        str_c++;

    return str_c;
}
