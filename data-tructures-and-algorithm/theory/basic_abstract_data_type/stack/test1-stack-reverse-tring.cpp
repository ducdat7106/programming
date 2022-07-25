#include <iostream>
#include <string.h>

using namespace std;

// list - danh sách liên kết
//=====install list=====
typedef char ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node Node;

typedef Node *Position;

typedef Position List;

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

// push into top stack
void Push(ElementType X, Stack &S)
{
    Insert_List(X, First_List(S), S);
}

// delete at top stack
ElementType Pop(Stack &S)
{
    ElementType X = Retrieve(S->Next, S);
    Delete_List(First_List(S), S);
    return X;
}

void reverse_string(char *str);


int main()
{
    char str[] = "hello";
    reverse_string(str);
    return 0;
}

void reverse_string(char *str)
{
    char *string_character;
    char *t;
    Stack *S;

    MakeNuLL_Stack(*S);

    printf("Input string character: ");
    fgets(string_character, 30, stdin);
    if ((t = strrchr(string_character, '\n')) != NULL)
        *t = '\0';

    for(int i=0; i<strlen(string_character); i++)
        Push(string_character[i], *S);
    printf("\nString character reverse: \n");
    while(!Empty_Stack(*S))
        printf("%c", Pop(*S));
}
