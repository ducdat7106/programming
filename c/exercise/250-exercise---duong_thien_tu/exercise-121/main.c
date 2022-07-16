#include "main.h"

int main()
{
    char s[80];
    unsigned long position_start, position_finish;
    int result = -1;

    printf("\nInput string: ");
    inputString(s);

    printf("\nInput position start cut string: ");
    scanf("%lu", &position_start);

    printf("\nInput position end cut string: ");
    scanf("%lu", &position_finish);

    result  =  clearString(s, position_start, position_finish);
    if(result == 1)
        puts("\nError");
    else if(result == 0)
        printf("\nResult : %s\n",s);

    return 0;
}

int clearString(char *str, int position_start, int counterChar)
{
    size_t len = strlen(str);

    if (len < position_start || len < 0 || len < (position_start + counterChar))
        return 1;
    
    strcpy(&str[position_start], &str[position_start + counterChar]);
    return 0;
}

void inputString(char *str)
{
    char *t;
    fgets(str, 80, stdin);

    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';
}