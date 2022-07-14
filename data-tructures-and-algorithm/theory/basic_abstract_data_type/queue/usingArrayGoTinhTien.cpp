#include <iostream>
using namespace std;

#define MaxLength 100

typedef int ElementType;

typedef struct
{
    ElementType Element[MaxLength];
    int Front, Rear;
} Queue;

// void MakeNull_Queue(Queue &Q)
// {
//     Q.Front = -1;
//     Q.Rear = -1;
// }

void MakeNull_Queue(Queue *Q)
{
    Q->Front = -1;
    Q->Rear = -1;
}

int Empty_Queue(Queue Q)
{
    return (Q.Front == -1);
}

int Full_Queue(Queue Q)
{
    return ((Q.Rear - Q.Front + 1) == MaxLength);
}

ElementType front(Queue Q)
{
    if (!Empty_Queue(Q))
        cout << "Hang rong";
    else
        return Q.Element[Q.Front];
}

void DeQueue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        if (Q->Front == Q->Rear)
            MakeNull_Queue(Q);
        else
            Q->Front++;
    }
    else
        printf("Loi: Hang rong!");
}

void EnQueue(ElementType X, Queue *Q)
{
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q))
            Q->Front = 0;

        if (Q->Rear == MaxLength - 1)
        {
            int i;
            // Di chuyen tinh tien ra truoc Front vi tri
            for (i = Q->Front; i <= Q->Rear; i++)
                Q->Element[i - Q->Front] = Q->Element[i];
            // Xac dinh vi tri Rear moi
            Q->Rear = Q->Rear - Q->Front; // Q->Rear = MaxLength - 1 - Q->Front;
            Q->Front = 0;
        }
        // Tang Rear de luu noi dung moi
        Q->Rear = Q->Rear + 1;
        Q->Element[Q->Rear] = X;
    }
    else
        printf("Loi: Hang day!\n");
}


