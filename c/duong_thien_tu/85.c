#include<stdio.h>

void create_array(int *arr[])
{
    int n;

    printf("Nhap cap ma tran: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            *(arr + i*n + j)=rand()%201-100;
        }
}

int main()
{

}