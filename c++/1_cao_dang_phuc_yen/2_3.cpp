#include<iostream>

using namespace std;

#define MaxLength 100

class Ve
{
    protected:
        int giaGoc;
        char ngay[30];
    public:
        void nhap();
        void xuat();
};

class VeLon : public Ve
{
    private:
        int giamLon;
        int giaVeLon;
    public:
        void nhap();
        void xuat();
};

class VeNho : public Ve
{
    private:
        int giamNho;
        int giaVeNho;

    public:
        void nhap();
        void xuat();
};

void Ve::nhap()
{
    cout<<"Nhap gia ve goc: ";
    cin>>giaGoc;

    cout<<"Nhap ngay giao dich: ";
    fflush(stdin);
    fgets(ngay, 30, stdin);
}

void Ve::xuat()
{
    cout<<"Gia ve goc: "<<giaGoc<<endl;
    cout<<"Ngay: "<<ngay;
}

void VeLon::nhap()
{
    Ve::nhap();

    cout<<"Phan tram giam: ";
    cin>>giamLon;

    giaVeLon = giaGoc-(giaGoc*giamLon)/100;
}

void VeLon::xuat()
{
    Ve::xuat();

    cout<<"Gia ve nguoi lon: "<<giaVeLon<<endl;
}

void VeNho::nhap()
{
    Ve::nhap();

    cout<<"Nhap phan tram giam: ";
    cin>>giamNho;

    giaVeNho = giaGoc-(giaGoc*giamNho)/100;
}

void VeNho::xuat()
{
    Ve::xuat();

    cout<<"Gia ve nho: "<<giaVeNho<<endl;
}


int main()
{
    system("cls");
    VeNho N;
    VeLon L;

    cout<<"\n-----Ve nguoi lon:\n";
    L.nhap();
    L.xuat();

    cout<<"\n-----Ve tre em:\n";
    N.nhap();
    N.xuat();

    system("pause");
}