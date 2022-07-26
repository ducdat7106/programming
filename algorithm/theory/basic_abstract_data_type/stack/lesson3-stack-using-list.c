#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int item;
    struct node *next;
};

typedef struct node *stackNode;

typedef struct
{
    stackNode top;
} stack;

void stackInitialize(stack *s)
{
    s->top = NULL;
    return;
}

int stackEmpty(stack s)
{
    return (s.top == NULL);
}

void Push(stack *s, int x)
{
    stackNode p;
    p = (stackNode)malloc(sizeof(struct node));
    p->item = x;
    p->next = s->top;
    s->top = p;
    return;
}

int Pop(stack *s)
{
    stackNode p;
    if (stackEmpty(*s))
        printf("Stack Empty");
    else
    {
        p = s->top;
        s->top = s->top->next;
        return p->item;
    }
}

int main()
{
    char *st;
    char *t;
    int i;
    stack *s;

    // system("cls");

    s = (stack *)malloc(100 * sizeof(stack));

    stackInitialize(s);

    st = (char *)malloc(30 * sizeof(char));

    printf("Enter string character: ");
    fgets(st, 30, stdin);
    if ((t = strrchr(st, '\n')) != NULL)
        *t = '\0';

    printf("%s\n", st);

    // /*
    for (i = 0; i < strlen(st); i++)
        Push(s, st[i]);
    printf("String reverse:\n");
    while (!stackEmpty(*s))
        printf("%c", Pop(s));
    // */

    free(st);
    st = NULL;
    free(s);
    s = NULL;

    printf("\n");
    system("pause");
    return 0;
}