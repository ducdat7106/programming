#include<iostream>

using namespace std;


#define Maxlength 100

typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elenments[Maxlength];
    Position Front, Rear;
} Queue;

void MakeNull_Queue(Queue &Q) // khởi tạo hành đợi rỗng
{
    Q.Front = -1;
    Q.Rear = -1;
}

int Empty_Queue(Queue Q) // kiểm tra hàng đợi có rỗng hay không
{
    return Q.Front == -1;
}

int Full_Queue(Queue Q) // Kiểm tra hàng đợi có bị tràn hay không
{
    return (Q.Rear - Q.Front + 1) == Maxlength;
}
void DeQueue(Queue &Q)
{
    if (!Empty_Queue(Q))
    {
        Q.Front = Q.Front + 1;
        if (Q.Front > Q.Rear)
            MakeNull_Queue(Q);
    }
    else
        printf("Loi: Hang rong!");
}
void EnQueue(ElementType X, Queue &Q) // Thêm phần tử X vào cuối hàng đợi Q
{

    if (!Full_Queue(Q))
    {
        if (Empty_Queue(Q))
            Q.Front = 0;
        if (Q.Rear == Maxlength - 1)
        {
            for (int i = Q.Front; i <= Q.Rear; i++)
                Q.Elenments[i - Q.Front] = Q.Elenments[i];
            Q.Rear = Maxlength - Q.Front - 1;
            Q.Front = 0;
        }
        Q.Rear = Q.Rear + 1;
        Q.Elenments[Q.Rear] = X;
    }
    else
        printf("Loi: Hang doi day!");
}
void Inp_Queue(Queue &Q) // Nhập hàng đợi vào
{
    Position n;
    printf("\t- So phan tu hang doi: ");
    scanf("%d", &n);

    Q.Front = 0;
    Q.Rear = n - 1;
    Position i;
    for (i = Q.Front; i <= Q.Rear; i++)
    {
        printf("\t - Nhap phan tu thu %d : ", i);
        scanf("%d", &Q.Elenments[i]);
    }
}
void Out_Queue(Queue Q) // In hàng đợi ra
{
    for (int i = Q.Front; i <= Q.Rear; i++)
        printf("%5d", Q.Elenments[i]);
    printf("\n");
}
void Sort_Queue(Queue &Q) // Sắp xếp
{

    for (int i = Q.Front; i < Q.Rear; i++)
        for (int j = i + 1; j <= Q.Rear; j++)
        {
            if (Q.Elenments[i] > Q.Elenments[j])
            {
                Q.Elenments[i] = Q.Elenments[i] + Q.Elenments[j];
                Q.Elenments[j] = Q.Elenments[i] - Q.Elenments[j];
                Q.Elenments[i] = Q.Elenments[i] - Q.Elenments[j];
            }
        }
}
void DelX_Queue(Position X, Queue &Q) // Xóa phần tử tại vị trí X trong hàng đợi
{
    if (!((X >= Q.Front) && (X <= Q.Rear)))
        printf("\tVi tri Can xoa khong ton tai!");
    else
    {
        for (int i = X; i > Q.Front; i--)
            Q.Elenments[i] = Q.Elenments[i - 1];
    }
    DeQueue(Q);
}
void Distinc_Queue(Queue &Q) // Xóa phần tử trùng nhau
{
    for (int i = Q.Front; i < Q.Rear; i++)
        for (int j = i + 1; j <= Q.Rear; j++)
            if (Q.Elenments[i] == Q.Elenments[j])
            {
                DelX_Queue(j, Q);
                i++;
            }
}
main()
{
    Queue Q;
    Position t = 2;
    ElementType X = 50;

    Inp_Queue(Q);

    printf("\t =>Hang doi ban da nhap: \n");
    Out_Queue(Q);
    printf("\n");

    Sort_Queue(Q);
    printf("\t =>Hang doi ban da sap xep: \n");
    Out_Queue(Q);
    printf("\n");

    Distinc_Queue(Q);
    printf("\t =>Hang doi ban da loai bo phan tu trung: \n");
    Out_Queue(Q);
    printf("\n");

    DeQueue(Q);
    printf("\t =>Hang doi ban da xoa phan tu dau: \n");
    Out_Queue(Q);
    printf("\n");

    EnQueue(X, Q);
    printf("\t =>Hang doi them X=%d vao cuoi: \n", X);
    Out_Queue(Q);
    printf("\n");

    system("pause");
}