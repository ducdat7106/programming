#include<iostream>

using namespace std;

#define Max_Length 100

class Person
{
    protected:
        char hoTen[25];
        char ngaySinh[25];
        char queQuan[25];
    public:
        void nhap();
        void xuat();
};

class KySu:public Person
{
    public:
        char nganhHoc[25];
        int namTotNghiep;

        void nhap();
        void xuat();
};

void Person::nhap()
{
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    fgets(hoTen, 25, stdin);

    cout << "Nhap ngay sinh: ";
    fflush(stdin);
    fgets(ngaySinh, 25, stdin);

    cout << "Nhap que quan: ";
    fflush(stdin);
    fgets(queQuan, 25, stdin);
}

void Person::xuat()
{
    cout<<"Ho ten: "<<hoTen<<endl;
    cout<<"Ngay sinh: "<<ngaySinh<<endl;
    cout<<"Que quan: "<<queQuan<<endl;
}

void KySu::nhap()
{
    Person::nhap();
    cout<<"Nhap nganh hoc: ";
    fflush(stdin);
    fgets(nganhHoc, 25, stdin);

    cout<<"Nhap nam tot nghiep: ";
    cin>>namTotNghiep;
}

void KySu::xuat()
{
    Person::xuat();

    cout<<"Nganh hoc: "<<nganhHoc<<endl;
    cout<<"Nam tot nghiep: "<<namTotNghiep<<endl;
}

int main()
{
    system("clr");

    KySu ks[Max_Length];
    int n,i;

    cout<<"Nhap so Ky su hien co: ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cout<<"Nhap ky su "<<i+1<<": \n";
        ks[i].nhap();
    }

    cout<<"\n=====Thong tin ky su tot nghiep gan day nhat:=====";
    int max = ks[0].namTotNghiep;
    for(i=0; i<n; i++)
        if(ks[i].namTotNghiep>max)
            max=ks[i].namTotNghiep;

    for(i=0; i<n; i++)
        if(ks[i].namTotNghiep==max)  
            ks[i].xuat();

    system("pause");     
}