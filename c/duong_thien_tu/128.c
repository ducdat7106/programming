#include <stdio.h>

int Length(char *arr)
{
    int length = 0;

    while (arr[length] != '\0')
        length++;

    return length - 1;
}

void clear_enter(char *arr)
{
    int length = Length(arr);

    printf("\nDo dai chuoi: %d", length);

    if (arr[length] == '\n')
        arr[length] = '\0';
    else
        printf("\nerror need fix!!\n");
}

void nhap_chuoi(char *arr)
{
    printf("Nhap chuoi: ");
    fflush(stdin);
    fgets(arr, 30, stdin);

    clear_enter(arr);
}

void in_chuoi_con(char *arr, int length, int length_max)
{
    for(int i=0; i<length; i++)
    {

    }
}
void chuoi_con_max(char *arr, int length)
{
    int counter_old = 0, counter_new = 0;

    if (arr[0] != ' ')
    {
        while (arr[counter_new] != ' ')
        {
            counter_new++;
        }

        for (int i = counter_new; i < length; i++)
        {
            if (arr[i - 1] == ' ' && arr[i] != ' ')
            {
                while (arr[i] != ' ' && arr[i] != '\0')
                {
                    counter_old++;
                    i++;
                }

                i--;

                if (counter_old > counter_new)
                    counter_new = counter_old;

                counter_old = 0;
            }          
        }
    }
    else if(arr[0] == ' ')
    {

        for (int i = 0; i < length; i++)
        {
            if (arr[i - 1] == ' ' && arr[i] != ' ')
            {
                while (arr[i] != ' ' && arr[i] != '\0')
                {
                    counter_old++;
                    i++;
                }

                i--;

                if (counter_old > counter_new)
                    counter_new = counter_old;

                counter_old = 0;
            }
        }
    }


}

int main()
{
    //system("cls");

    char array[100];

    nhap_chuoi(array);

    printf("\nChuoi: %s", array);

    //system("pause");
    return 0;
   
}

