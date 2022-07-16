#include <stdio.h>
#include<stdlib.h>

void inputMatrix(int **arr, int row, int column);
void outputMatrix(int **arr, int row, int column);

int main()
{
    int **array = NULL;
    int row, column;
    int i = 0;

    printf("vao so hang, so cot: ");
    scanf("%d%d", &row, &column);

    // cấp phát mảng các con trỏ cấp 1
    array = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < column; ++i)
    {
        // cấp phát cho từng con trỏ cấp 1
        array[i] = (int *)malloc(column * sizeof(int));
    }

    inputMatrix(array, row, column);
    outputMatrix(array, row, column);

    // giải phóng từng hàng
    for (i = 0; i < row; ++i)
        free(array[i]);

    // giải phóng con trỏ quản lý các hàng
    free(array);

    return 0;
}

void inputMatrix(int **arr, int row, int column)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
}

void outputMatrix(int **arr, int row, int column)
{
    for (int i = 0; i < row; ++i, putchar('\n'))
        for (int j = 0; j < column; ++j)
        {
            if(j==0)
                printf("%d", arr[i][j]);
            else
                printf("%5d", arr[i][j]);
            // printf("\n");
        }
}
