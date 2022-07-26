// Time 12/7/2022 --- 12:00
#include <iostream>
#include <string.h>

using namespace std;

struct Element_Type
{
    int id; // code student-msv
    char name[30];
    int age;
};

typedef struct Element_Type ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node Node;
typedef Node *Position;
typedef Position List;

void Make_Null_List(List *Header)
{
    (*Header) = (Node *)malloc(sizeof(Node));
    (*Header)->Next = NULL;
}

Position First(List L)
{
    return L;
}

Position End(List L)
{
    Position p;
    p = First(L);
    while (p->Next != NULL)
        p = p->Next;
    return p;
}

Position Next(Position p, List L)
{
    return p->Next;
}

void Insert_List(ElementType x, Position p, List *L)
{
    Position t;
    t = (Node *)malloc(sizeof(Node));
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
}

void Delete_List(Position p, List *L)
{
    Position temp;
    
    if (p->Next != NULL)
    {
        temp = p->Next;
        p->Next = temp->Next;
        free(temp);
    }
}

void Insert_List(ElementType X, Position P, List &L)
{
    Position Temp;                       // Create node new
    Temp = (Node *)malloc(sizeof(Node)); // memory allocation node new. This node pointed to by Temp
    Temp->Element = X;                   // assign the appropriate value
    Temp->Next = P->Next;
    P->Next = Temp;
}

void Delete_List(Position P, List &L)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

Position Find(int id_student, List L)
{
    Position p;
    int Found = 0;
    p = L;
    while ((p->Next != NULL) && (Found == 0))
        if (p->Next->Element.id == id_student)
            Found = 1;
        else
            p = p->Next;
    return p;
}

void Delete(int id_student, List *L)
{
    Position p;
    p = Find(id_student, *L);
    if (p != End(*L))
        Delete_List(p, L);
    else
        printf("No find, this student code\n");
}

Position Locate_Sorted_List(int age, List L)
{
    Position p;
    p = L;
    while ((p->Next != NULL) && (p->Next->Element.age < age))
        p = Next(p, L);
    return p;
}

void Insert_Sorted_List(ElementType x, List *L)
{
    Position p = Locate_Sorted_List(x.age, *L);
    Insert_List(x, p, L);
}

ElementType Retrieve(Position p, List L)
{
    if (p->Next != NULL)
        return p->Next->Element;
}

void Sort(List *L)
{
    Position p, q, smallest;
    p = First(*L);

    while (p->Next != NULL)
    {
        smallest = p;
        q = Next(p, *L);
        while (q->Next != NULL)
        {
            if (q->Next->Element.age < smallest->Next->Element.age)
                smallest = q;
            q = Next(q, *L);
        }
        ElementType x;
        x = p->Next->Element;
        p->Next->Element = smallest->Next->Element;
        smallest->Next->Element = x;
        p = Next(p, *L);
    }
}

void Print_List(List L)
{
    Position p;
    ElementType x;
    p = First(L);
    while (p != End(L))
    {
        x = Retrieve(p, L);
        printf("%d:%s:%d\n", x.id, x.name, x.age);
        p = Next(p, L);
    }
    printf("\n");
}

void Read_List(List *L)
{
    char *t;
    int i, n;
    Make_Null_List(L);
    printf("Number element in list is N= ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        ElementType x;
        printf("Element: %d: \n", i);
        printf("ID student: ");
        scanf("%d", &x.id);

        getchar();
        printf("Name employee: ");
        fgets(x.name, 30, stdin);
        if ((t = strrchr(x.name, '\n')) != NULL)
            *t = '\0';

        printf("Age employee: ");
        scanf("%d", &x.age);

        if (Find(x.id, *L) == End(*L))
            Insert_List(x, End(*L), L);
        else
            printf("Employee code already exists\n");
    }
}

double Age_Medium(List L)
{
    int number_element = 0;
    int total_age = 0;

    Position p = First(L);

    while (p != End(L))
    {
        number_element++;
        p = Next(p, L);
        total_age = total_age + p->Element.age;
    }

    return 1.0 * total_age / number_element;
}

int main()
{
    List L;
    ElementType X;
    Position P;

    int code_student;
    char *t;

    system("cls");

    Read_List(&L);
    printf("\nList present:\n");
    Print_List(L);

    printf("\nList after sort age increment:\n");
    Sort(&L);
    Print_List(L);

    printf("\nAge medium: %5.2f", Age_Medium(L));

    printf("\nCode student need clear: ");
    scanf("%d", &code_student);

    Delete(code_student, &L);
    printf("\nList after delete:\n");
    Print_List(L);

    printf("\nElement need add: ");

    printf("\nCode employee: ");
    scanf("%d", &X.id);

    getchar();
    printf("\nFirst and last name employee: ");
    fgets(X.name, 30, stdin);
    if ((t = strrchr(X.name, '\n')) != NULL)
        *t = '\0';

    printf("\nAge employee: ");
    scanf("%d", &X.age);

    Insert_Sorted_List(X, &L);

    printf("\nList present:\n");
    Print_List(L);

    return 0;
}
