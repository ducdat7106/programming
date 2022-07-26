#include <iostream>

using namespace std;

#define Maxlength 100
typedef int ElementType;
typedef int Position;

struct Stack
{
    ElementType Elements[Maxlength]; // Node
    int Top_idx;                     // Top Index
};

typedef struct Stack Stack;

//  initialization stack
void MakeNull_Stack(Stack &S)
{
    S.Top_idx = -1;
}

// manipulation check stack empty
int Empty_Stack(Stack S)
{
    return S.Top_idx == -1;
}

// manipulation stack full
int Full_Stack(Stack S)
{
    return S.Top_idx == Maxlength - 1;
}

// value element top stack
ElementType Top(Stack S)
{
    if (!Empty_Stack(S))
        return S.Elements[S.Top_idx];
    else
        printf("Error! Stack empty");
}

// delete element at top stack
void Pop(Stack &S)
{
    if (!Empty_Stack(S))
        S.Top_idx -= 1;
    else
        printf("Error! Stack empty.");
}

// manipulation take a element uoy of stack
int Top_And_Pop(Stack &S)
{
    if (Empty_Stack(S))
        cout << "Stack empty!";
    else
        return S.Elements[S.Top_idx--];
}

// Extra element into top stack
void Push(ElementType X, Stack &S)
{
    if (Full_Stack(S))
        printf("Error! Stack full.");
    else
    {
        S.Top_idx += 1;
        S.Elements[S.Top_idx] = X;
    }
}

// sort ascending
void Sort(Stack &S)
{
    ElementType Temp;
    for (int i = 0; i < S.Top_idx; i++)
        for (int j = i + 1; j <= S.Top_idx; j++)
            if (S.Elements[i] > S.Elements[j])
            {
                Temp = S.Elements[i];
                S.Elements[i] = S.Elements[j];
                S.Elements[j] = Temp;
            }
}

// delete element at position X
void Delete(Position X, Stack &S)
{
    ElementType Temp;

    while (X != S.Top_idx)
    {
        S.Elements[X] = S.Elements[X + 1];
        X++;
    }

    Pop(S); // clear top stack
}

// delete elements same
void Distinct(Stack &S)
{
    for (int i = 0; i <= S.Top_idx - 1; i++)
        for (int j = i + 1; j <= S.Top_idx; j++)
        {
            if (S.Elements[i] == S.Elements[j])
            {
                Delete(j, S);
                i++;
            }
        }
}

void Input_Stack(Stack &S)
{
    int n;
    ElementType x;
    printf("\t- Enter number of element of stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\t- Enter element %d: ", i + 1);
        scanf("%d", &x);
        Push(x, S);
    }
}
void Output_Stack(Stack S)
{
    printf("\t");
    while (!Empty_Stack(S))
    {
        printf("%4d", S.Elements[S.Top_idx]);
        Pop(S);
    }
    printf("\n");
}

int count_element(Stack S)
{
    return (S.Top_idx + 1);
}

int main()
{
    system("cls");

    Stack S;
    int pos;

    MakeNull_Stack(S);

    Input_Stack(S);

    printf("\n\t=> Stack of you just entered:\n");
    Output_Stack(S);

    Sort(S);
    printf("\n\t=> Stack arranged: \n");
    Output_Stack(S);

    Distinct(S);
    printf("\n\t=> Stack was break element same:\n");
    Output_Stack(S);

    printf("\n\tDelete one element ay position x: ");
    scanf("%d", &pos);
    Delete(pos, S);
    Output_Stack(S);

    printf("\nNumber of element of stack: %d\n", count_element(S));

    system("pause");
    return 0;
}