#include<iostream>
#include "D:\data_structures_and_algorithms\type_data_truu_tuong_basic\queue\usingList.cpp"

void readQueue(Queue &pQ)
{
    int n;
    ElementType X;
    cout<<"So phan tu can nhap vao n= ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap phan tu thu "<<i+1<<": ";
        cin>>X;
        enQueue(X, pQ);
    }
}


void printQueue(Queue Q){
    cout<<"cac phan tu trong hang: \n";
    while(!EmptyQueue(Q))
    {
        cout<<front(Q)<<endl;
        deQueue(Q);
    }
}

int main()
{
    system("cls");

    Queue Q;
    MakeNullQueue(Q);

    readQueue(Q);

    printQueue(Q);

    system("pause");
    return 0;
}
