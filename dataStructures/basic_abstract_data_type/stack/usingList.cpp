#include <iostream>

using namespace std;

//=====cài đặt danh sách( install list)=====
typedef int ElementType;

struct Node
{
    ElementType Element;
    Node *Next;
};

typedef struct Node Node;

typedef Node *Position;
typedef Position List;

void MakeNull_List(List &Header) // Khởi tạo danh sách rỗng
{
    Header = (Node *)malloc(sizeof(Node));
    Header->Next = NULL;
}

int Empty_List(List L) // kiểm tra danh sách rỗng, nếu rỗng trả về 1, không rỗng trả về 0
{
    return (L->Next == NULL);
}

Position FirstList(List L) // Trả về đầu danh sách
{
    return L;
}

void Insert_List(ElementType X, Position P, List &L) // Chèn phần tử X vào danh sách L tại vị trí P
{
    Position T;
    T = (Node *)malloc(sizeof(Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}

void InsertFirstList(ElementType X, List &L) // Chèn phần tử X vào đầu danh sách
{
    Insert_List(X, FirstList(L), L);
}

Position EndList(List L) // Cho biết vị trí cuối danh sách
{
    Position P;
    P = L;
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

void InsertEndList(ElementType X, List &L) // Chèn X vào cuối danh sách
{
    Insert_List(X, EndList(L), L);
}

void Delete_List(Position P, List &L) // Xóa phần tử thứ P trong danh sách L
{
    Position T;
    if (P->Next != NULL)
    {
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

Position Locate(ElementType X, List L) //Định vị vị trí của X trong danh sach L
{
    Position P = L;
    while (P->Next != NULL)
        if (P->Next->Element == X)
            break;
        else
            P = P->Next;
    return P;
}

ElementType Retrieve(Position P, List L) // Trả về giá trị tại vị trí P trong danh sách L
{
    if (P->Next != NULL)
        return P->Next->Element;
}

void Read_List(List &L) // Nhap danh sách vào
{
    int n;
    printf("\t Nhap so phan tu cua danh sach: ");
    scanf("%d", &n);
    int i = 0;
    ElementType X;
    while (i < n)
    {
        printf("\t-Nhap phan tu thu %d: ", i);
        scanf("%d", &X);
        InsertEndList(X, L);
        i++;
    }
}

void Print_List(List &L) // In danh sách ra
{
    Position P = FirstList(L);
    while (P->Next != NULL)
    {
        printf("%6d", P->Next->Element);
        P = P->Next;
    }
}

void Distinct(List &L) // Loc xóa các phần tử trùng nhau
{

    Position P, Q;
    for (P = L; P->Next != NULL; P = P->Next)
    {
        for (Q = P->Next; Q->Next != NULL;)
            if (P->Next->Element == Q->Next->Element)
                Delete_List(Q, L);
            else
                Q = Q->Next;
    }
}

void Sort(List &L) // sắp xếp danh sách theo thứ tự tăng/giảm dần
{
    Position P, Q;
    ElementType Temp;
    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL; Q = Q->Next)
            if (P->Next->Element > Q->Next->Element)
            {

                Temp = P->Next->Element;
                P->Next->Element = Q->Next->Element;
                Q->Next->Element = Temp;
            }
}
//=====finish install list=====

//=====start install stack by list=====
typedef List Stack;

// void MakeNuLL_Stack(Stack *S)
// {
//     MakeNull_List(*S);
// }

void MakeNuLL_Stack(Stack &S)
{
    MakeNull_List(S);
}

int Empty_Stack(Stack S)
{
    return Empty_List(S);
}

void Push(ElementType X, Stack &S)
{
    Insert_List(X, FirstList(S), S);
}

void Pop(Stack &S)
{
    Delete_List(FirstList(S), S);
}

int main()
{
    system("cls");

    system("pause");
    return 0;
}