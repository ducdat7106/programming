#include<iostream>

using namespace std;

#define MaxLength 100

class THUCPHAM
{
    protected:
        char tenThucPham[30];
        int giaCa;
    public:
        void nhap();
        void xuat();
};

class TPHOP:public THUCPHAM
{
    private:
        int soHop;
    public:
        void nhap();
        void xuat();
};

class TPKHOP:public THUCPHAM
{
    private:
        int khoiLuong;
    public:
        void nhap();
        void xuat();
};

void THUCPHAM::nhap()
{
    cout<<"Nhap ten thuc pham: ";
    fflush(stdin);
    fgets(tenThucPham, 30, stdin);

    cout<<"Gia ca: ";
    cin>>giaCa;
}

void THUCPHAM::xuat()
{
    cout<<"Ten thuc pham: "<<tenThucPham<<endl;
    cout<<"Gia ca: "<<giaCa<<endl;
}

void TPHOP::nhap()
{
    THUCPHAM::nhap();
    cout<<"So hop: ";
    cin>>soHop;    
}

void TPHOP::xuat()
{
    THUCPHAM::xuat();
    cout<<"So hop: "<<soHop<<endl;
}

void TPKHOP::nhap()
{
    THUCPHAM::nhap();
    cout<<"Khoi luong: ";
    cin>>khoiLuong;
}

void TPKHOP::xuat()
{
    THUCPHAM::xuat();
    cout<<"Khoi luong: "<<khoiLuong<<endl;
}

int main()
{
    TPHOP tpHop[MaxLength];
    TPKHOP tpkHop[MaxLength];

    int m,n,i;

    system("cls");

    cout<<"Nhap so luong thuc pham hop: ";
    cin>>n;
    for(i=0; i<n; i++)
        tpHop[i].nhap();
    
    cout<<"Nhap so luong thuc pham khong hop: ";
    cin>>m;
    for(i=0; i<m; i++)
        tpkHop[i].nhap();
    

    cout<<"\n\nThuc pham hop:"<<endl;
    for(i=0; i<n; i++)
        tpHop[i].xuat();
    
    cout<<"\n\nThuc pham khong hop:"<<endl;
    for(i=0; i<m; i++)
        tpkHop[i].xuat();
}