#include <iostream>
#include <cstring>

using namespace std;

void enter_string(char *str);
void reverse(char *str);

int main()
{
    char *s = NULL;

    s = new char[30];

    enter_string(s);
    
    reverse(s);

    cout << "String reverse: " << s << endl;

    delete[] s;

    return 0;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *str)
{
    int len = strlen(str), i;

    for (i = 0; i < len / 2; i++)
        swap(&str[i], &str[len - 1 - i]);
}

void enter_string(char *str)
{
    char *t;
    cout << "Enter string: ";
    fgets(str, 30, stdin);
    if ((t = strrchr(str, '\n')) != NULL)
        *t = '\0';
}