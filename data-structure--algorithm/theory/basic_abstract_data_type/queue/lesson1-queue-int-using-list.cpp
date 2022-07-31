#include <iostream>

typedef int ElementType;

struct note
{
    ElementType element;
    struct note *next;
};

typedef struct note note_type;

typedef note_type *Position;

typedef struct
{
    Position Front, Rear;
} Queue;

Queue Q;

void MakeNull_Queue(Queue *Q)
{
    Position Header;
    Header = (struct note *)malloc(sizeof(struct note));
    Header->next = NULL;
    Q->Front = Header;
    Q->Rear = Header;
}

int Empty_Queue(Queue Q)
{
    return (Q.Front == Q.Rear);
}

void Enter_Queue(ElementType X, Queue *Q)
{
    Q->Rear->next = (note_type *)malloc(sizeof(note_type));
    Q->Rear = Q->Rear->next;
    Q->Rear->element = X;
    Q->Rear->next = NULL;
}

void Delete_Queue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        Position Tempt;
        Tempt = Q->Front;
        Q->Front = Q->Front->next;
        free(Tempt);
    }
    else
        printf("Error! Queue empty");
}

// get value element
ElementType Retrieve_First(Queue Q)
{
    if (!Empty_Queue(Q))
        return Q.Front->next->element;
}

void Read_Queue(Queue *Q)
{
    int i, N;
    ElementType X;
    MakeNull_Queue(Q);
    printf("Number of element queue N = ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        printf("Number th element %d: ", i);
        scanf("%d", &X);
        Enter_Queue(X, Q);
    }
}

void Print_Queue(Queue Q)
{
    while (!Empty_Queue(Q))
    {
        printf("%d ", Retrieve_First(Q));
        Delete_Queue(&Q);
    }
    printf("\n");
}

main()
{
    Queue Q;
    Read_Queue(&Q);
    printf("Queue just enter: ");
    Print_Queue(Q);
    return 0;
}
