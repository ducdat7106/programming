#include "main.h"

int main()
{
    char str_available[] = "123456789";
    char *str_in = NULL, *str_out = NULL;

    printf("\nInput string: ");
    str_in = inputString();

    str_out = reverseString(str_in);
    printf("\nString output: %s", str_out);

    free(str_in); str_in=NULL;
    free(str_out); str_out = NULL;
    return 0;
}

char *inputString()
{
    char *str = NULL, *t;
    int length = 100;

    str = (char *)malloc(length * sizeof(char));
    if (!str)
        return NULL;

    fflush(stdin);
    fgets(str, length, stdin);
    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';

    return str;
}

char *reverseString(char *str)
{
    char *str_temp = NULL;
    size_t len = strlen(str) + 1; //add 1 for position '\0'

    str_temp = (char *)malloc(len * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
        str_temp[i] = str[len - i - 2];     //- 2 for 0, 1, 2... and '\0' 
    str_temp[len - 1] = '\0';       //- 1 for '\0'

    return str_temp;
}