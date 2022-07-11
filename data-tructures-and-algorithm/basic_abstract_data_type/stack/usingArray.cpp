#include <iostream>

using namespace std;

#define Maxlength 100
typedef int ElementType;
typedef int Position;

typedef struct
{
    ElementType Elements[Maxlength];
    int Top_idx;
} Stack;

//Stack S;

void MakeNull_Stack(Stack &S)
{
    S.Top_idx = Maxlength;
}

int Empty_Stack(Stack S)
{
    return S.Top_idx == Maxlength;
}

int Full_Stack(Stack S)
{
    return S.Top_idx == 0;
}

ElementType Top(Stack S)    //giá trị phần tử đầu ngăn xếp
{
    if (!Empty_Stack(S))
        return S.Elements[S.Top_idx];
    else
        printf("Loi! Ngan xep rong");
}

void Pop(Stack &S)  //xóa phân tử tại đỉnh ngăn xếp
{
    if (!Empty_Stack(S))
        S.Top_idx = S.Top_idx + 1;
    else
        printf("Loi! Ngan xep rong");
}

void Push(ElementType X, Stack &S)  //Thêm phần tủ vào đỉnh ngăn xếp
{
    if (Full_Stack(S))
        printf("Loi! ngan xep day");
    else
    {
        S.Top_idx = S.Top_idx - 1;
        S.Elements[S.Top_idx] = X;
    }
}

void Sort(Stack &S)
{
    ElementType Temp;
    for (int i = S.Top_idx; i < Maxlength; i++)
        for (int j = i + 1; j <= Maxlength; j++)
            if (S.Elements[i] > S.Elements[j])
            {
                Temp = S.Elements[i];
                S.Elements[i] = S.Elements[j];
                S.Elements[j] = Temp;
            }
}

void Delete(Position X, Stack &S) //xóa  phần tử tại vị trí X
{
    X = S.Top_idx + X;
    ElementType Temp;

    while (!(X == S.Top_idx))
    {
        Temp = S.Elements[X];
        S.Elements[X] = S.Elements[X - 1];
        S.Elements[X - 1] = Temp;
        X--;
    }
    Pop(S);
}

void Distinc(Stack &S) //xóa các phần tử giống nhau
{
    for (int i = S.Top_idx; i < Maxlength - 1; i++)
        for (int j = i + 1; j < Maxlength; j++)
        {
            if (S.Elements[i] == S.Elements[j])
            {
                Delete(j - S.Top_idx, S);
                i++;
                // j++;
            }
        }
}

void Inp_Stack(Stack &S)
{
    int n;
    ElementType x;
    printf("\t- Nhap vao so phan tu ngan xep: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\t - Nhap phan tu thu %d: ", i);
        scanf("%d", &x);
        Push(x, S);
    }
}
void Out_Stack(Stack S)
{
    while (!Empty_Stack(S))
    {
        printf("%4d", S.Elements[S.Top_idx]);
        Pop(S);
    }
}
main()
{
    system("cls");
    Stack S;
    MakeNull_Stack(S);
    Inp_Stack(S);

    printf("\n\t=> Ngan xep cua ban vua nhap: \n");
    Out_Stack(S);

    Sort(S);
    printf("\n\t=> Ngan xep da sap xep: \n");
    Out_Stack(S);

    Distinc(S);

    printf("\n\t=> Ngan xep da loai bo phan tu trung: \n");
    Out_Stack(S);

    system("pause");
}