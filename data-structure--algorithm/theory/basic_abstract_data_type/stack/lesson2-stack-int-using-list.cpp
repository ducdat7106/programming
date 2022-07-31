#include <iostream>

using namespace std;

//===============install list=====
typedef int ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node Node;

typedef Node *Position;

typedef Position List;

typedef List Stack;

// initialization list empty
void MakeNull_List(List &Header)
{
    Header = (Node *)malloc(sizeof(Node));
    Header->Next = NULL;
}

// check stack empty.
int Empty_List(List L)
{
    return (L->Next == NULL);
}

// return value first list
Position First_List(List L)
{
    return L;
}

// return value end list
Position End_List(List L)
{
    Position P;
    P = L;
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

// insert element X into list L at position P
void Insert_List(ElementType X, Position P, List &L)
{
    Position T;
    T = (Node *)malloc(sizeof(Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}

// insert element X into first list
void Insert_First_List(ElementType X, List &L)
{
    Insert_List(X, First_List(L), L);
}

// insert element X into end list
void Insert_End_List(ElementType X, List &L)
{
    Insert_List(X, End_List(L), L);
}

// delete element at position P in list L
void Delete_List(Position P, List &L)
{
    Position T;
    if (P->Next != NULL)
    {
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

// return position of element X in list L
Position Locate(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL)
        if (P->Next->Element == X)
            break;
        else
            P = P->Next;
    return P;
}

// return value of element at position P in list L
ElementType Retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}

// enter list L
void Read_List(List &L)
{
    int n;
    printf("\t Enter number of element: ");
    scanf("%d", &n);
    int i = 0;
    ElementType X;
    while (i < n)
    {
        printf("\t-Enter th element %d: ", i);
        scanf("%d", &X);
        Insert_End_List(X, L);
        i++;
    }
}

// output list L
void Print_List(List &L)
{
    Position P = First_List(L);
    while (P->Next != NULL)
    {
        printf("%6d", P->Next->Element);
        P = P->Next;
    }
}

// delete all elements similar
// or filter delete elements similar
void Distinct(List &L)
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

// sort the list in  ascending order  -- ascending order-thứ tự tăng dần
void Sort(List &L)
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
//=====Finish install list=====

//=====Start install stack by list=====

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

// push element into top stack
void Push(ElementType X, Stack &S)
{
    Insert_List(X, First_List(S), S);
}

// delete element at top stack
void Pop(Stack &S)
{
    Delete_List(First_List(S), S);
}

ElementType Top(Stack S)
{
    return Retrieve(First_List(S), S);
}

void Read_Stack(Stack &S)
{
    int i, N;
    ElementType X;
    MakeNuLL_Stack(S);
    cout << "Number of element of stack N = ";
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cout << "Number th element: " << i + 1<<":   ";
        cin >> X;
        Push(X, S);
    }
}

void Print_Stack(Stack S)
{
    while (!Empty_Stack(S))
    {
        cout << Top(S) << "   ";
        Pop(S);
    }
    cout << endl;
}

int main()
{
    system("cls");

    Stack S;
    Read_Stack(S);
    cout << "Stack just enter: ";
    Print_Stack(S);

    system("pause");
    return 0;
}
