#include<iostream>
#include<string.h>

using namespace std;

#define MaxLength 100

class Person
{
    protected:
        char hoTen[50];
        char ngaySinh[12];
        char queQuan[100];
    public:
        Person()
        {
            strcpy(hoTen, "");
            strcpy(ngaySinh, "");
            strcpy(queQuan, "");
        }

        void nhap();
        void xuat();
};

class Diem
{
    protected:
        int dtoan;
        int dly;
        int dhoa;
    public:
        Diem()
        {
            dtoan=dly=dhoa=0;
        }

        void nhap();
        void xuat();
};

class HocSinh : public Person, public Diem
{
    private:
        char lop[30];
        int tongDiem;
    public:
        HocSinh()
        {
            strcpy(lop, "");
            tongDiem=0;
        }

        void nhap();
        void xuat();
};

void Person::nhap()
{
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    fgets(hoTen, 50, stdin);

    cout << "Nhap ngay sinh: ";
    fflush(stdin);
    fgets(ngaySinh, 15, stdin);

    cout << "Nhap que quan: ";
    fflush(stdin);
    fgets(queQuan, 100, stdin);
}

void Person::xuat()
{
    cout<<"Ho ten: "<<hoTen<<endl;
    cout<<"Ngay sinh: "<<ngaySinh<<endl;
    cout<<"Que quan: "<<queQuan<<endl;
}

void Diem::nhap()
{
    cout<<"Nhap diem toan: ";
    cin>>dtoan;

    cout<<"Nhap diem ly: ";
    cin>>dly;

    cout<<"Nhap diem hoa: ";
    cin>>dhoa;
}

void Diem::xuat()
{
    cout<<"Diem toan ly hoa: \n"<<dtoan<<" "<<dly<<" "<<dhoa;
}

void HocSinh::nhap(){
    Person::nhap();

    cout<<"Nhap ten lop: ";
    fflush(stdin);
    fgets(lop, 25, stdin);

    Diem::nhap();

    tongDiem = dtoan+dly+dhoa;
}

void HocSinh::xuat()
{
    Person::xuat();

    cout<<"Lop: "<<lop<<endl;

    Diem::xuat();

    cout<<"\nTong diem: "<<tongDiem<<endl;
}

int main()
{
    system("cls");

    HocSinh hs[MaxLength];
    int n,i;

    cout<<"Nhap so sinh vien: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Sinh vien thu "<<i+1<<":"<<endl;
        hs[i].nhap();
    }
        
    cout<<"\nThong tin vua nhap:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Sinh vien thu"<<i+1<<endl;
        hs[i].xuat();
    }

    system("pause");
}