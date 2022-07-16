#include "main.h"

int main()
{
    unsigned long value;
    char s[80];

    inputNumber(&value);
    dec2bin(s, value);
    printf("String binary: %s\n", s);  

    return 0;
}

void dec2bin(char *str, unsigned long number)
{
    int i=0;

    unsigned long surplus;

    do{
        surplus = number%2;
        number /= 2;

        if(surplus == 0)
            str[i++] = '0';
        else
            str[i++] = '1';
    }while(number/2 != 0);

    str[i] = '1';
    str[i+1] = '\0';

    str = strrev(str);
}

void inputNumber(unsigned long *number)
{
    printf("Input number: ");
    scanf("%lu", number);
}

