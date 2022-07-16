#include <iostream>
using namespace std;
#define MaxLength 100

class CARD
{
private:
    char tuaDe[25];
    char tacGia[25];
    int soLuong;

public:
    void nhap();
    void xuat();

    friend void search_max(CARD *arr, int n);
};

void CARD::nhap()
{
    cout << "Nhap ten tua de sach: ";
    fflush(stdin);
    fgets(tuaDe, 25, stdin);

    cout << "Nhap ten tac gia: ";
    fflush(stdin);
    fgets(tacGia, 25, stdin);

    cout << "Nhap so luong sach: ";
    cin >> soLuong;
}

void CARD::xuat()
{
    cout << "Tua de sach: " << tuaDe << endl;
    cout << "Tac gia: " << tacGia << endl;
    cout << "So luong: " << soLuong << endl;
}

void search_max(CARD *arr, int n)
{
    int temp = arr[0].soLuong;
    for(int i=0; i<n; i++)
        if(arr[i].soLuong>temp)
            temp=arr[i].soLuong;
    
    for(int i=0; i<n; i++)
        if(temp==arr[i].soLuong)
            cout<<arr[i].tuaDe<<", ";
}


int main()
{
    system("cls");
    CARD book[MaxLength];

    int i, n, max=0;

    cout << "n= ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout<<"BooK "<<i+1<<endl;
        book[i].nhap();
    }
    
    cout<< "\nDanh sach cac cuon sach co so luong lon nhat: " << endl;
    search_max(book, n);
    system("pause");
}