#include "D:\data_structures_and_algorithms\type_data_truu_tuong_basic\list\usingPointer.cpp"

typedef List Queue; //đồng nhất hàng với danh sách

void MakeNullQueue(Queue &pQ)
{
    MakeNull_List(pQ);
}

// return 1 is rong
// return 0 is ko rong
int EmptyQueue(Queue Q)
{
    return Empty_List(Q);
}

void enQueue(ElementType X, Queue &pQ)  // add  element into end Queue
{
    Insert_List(X, EndList(pQ), pQ);
}

void deQueue(Queue pQ)  //remove element at first Queue
{
    Delete_List(FirstList(pQ), pQ);
}

ElementType front(Queue Q)//return value element at first queue
{
    return Retrieve(FirstList(Q), Q);
}