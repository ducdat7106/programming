#include<stdio.h>
#include<stdlib.h>

void input(int *arr, int row, int column);
void output(int arr[], int row, int column);

void main()
{
    int *array, row, column;
    int i=0;

    printf("vao so cot, dong: ");
    scanf("%d%d", &row, &column);

    //cấp phát
    array=(int*)malloc(row*column*sizeof(int));

    input(array, row, column);
    output(array, row, column);

    //giải phóng
    free(array);
    
    return;
}
void input(int *arr, int row, int column)
{
    for(int i=0; i<row; ++i)
        for(int j=0; j<column; ++j)
        {
            printf("a[%d][%d] = ",i+1, j+1);
            scanf("%d", (arr+i*row+j));
        }
}

void output(int *arr, int row, int column)
{
    for(int i=0; i<row; ++i, putchar('\n'))
        for(int j=0; j<column; j++)
        {
            printf("%5d", *(arr+i*row+j));
        }
}

