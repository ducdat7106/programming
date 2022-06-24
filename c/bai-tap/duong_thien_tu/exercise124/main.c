#include "main.h"

int main()
{
    int number, number1;
    char *string1 = NULL, *string2 = NULL;

    /*
    printf("\nInput number need convert: ");
    number = inputNumber();

    string1 = itos_function(number);
    printf("\nResult convert number: ");
    outputString(string1);
    */

    //----------------------------------------------------
    printf("\nInput string need convert: ");
    string2 = inputString();

    number1 = stoi_function(string2);
    printf("Number: %d", number1);

    free(string1);
    string1 = NULL;

    free(string2);
    string2 = NULL;

    return 0;
}

int inputNumber()
{
    int value;
    scanf("%d", &value);
    return value;
}

char *inputString()
{
    char *str = NULL;
    int length = 100;

    str = (char *)malloc(length * sizeof(char));

    fflush(stdin);
    fgets(str, length, stdin);

    return str;
}

void outputString(char *str)
{
    printf("\n\tString output: %10s", str);
}

char *itos_function(int number)
{
    char *str = NULL;
    int counter = 0;
    int t;
    int temp = number;

    while (temp) // temp != 0
    {
        temp /= 10;
        counter++;
    }

    str = (char *)malloc((counter + 1) * sizeof(char));
    if (!str)
        return NULL;
    str[counter] = '\0';

    temp = number;
    while (temp || counter)
    {
        t = temp % 10;
        str[counter - 1] = t + 48;
        temp /= 10;
        counter--;
    }

    return str;
}

int stoi_function(char *str)
{
    int i;
    unsigned int number;
    number = 0;

    size_t len = strlen(str)-1;
    int index_number = len;

    for (i = 0; i < len; i++)
    {
        index_number--;
        number += (str[i] - 48) * pow(10, index_number); 
    }

    return number;
}
