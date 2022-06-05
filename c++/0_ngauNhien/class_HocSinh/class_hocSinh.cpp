#include<iostream>

using namespace std;

#define Max_Length 100

static int count = 0;

class hocSinh
{
private:
    char hoTen[25];
    int lop;
    float dtoan, dly, dhoa,tb;
public:
    void nhap();
    void xuat();
    void xuatDieuKien();
    void dieuKien();
};

void hocSinh::nhap()
{
    cout<<"Ho va ten: ";
    fflush(stdin);
    fgets(hoTen, 25, stdin);

    cout<<"Lop: ";
    cin>>lop;

    cout<<"diem toan: ";
    cin>>dtoan;

    cout<<"dien ly: ";
    cin>>dly;

    cout<<"diem hoa: ";
    cin>>dhoa;

    tb = (dtoan+dly+dhoa)/3;
}

void hocSinh::xuat()
{
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nLop: "<<lop;
    cout<<"\nDiem toan: "<<dtoan;
    cout<<"\nDiem hoa: "<<dhoa;
    cout<<"\nDiem ly: "<<dhoa;
    cout<<"\nDiem trung binh: "<<tb;
}

void hocSinh::xuatDieuKien()
{
    if(tb>=5)
    {
        hocSinh::xuat();
    }
}


int main()
{
    hocSinh  sinhVien[Max_Length];

    int n, i;
    system("cls");//clear screen

    cout<<"Nhap so luong sinh vien: ";
    cin>>n;

    for(int j=0; j<n; j++)
    {
        sinhVien[j].nhap();
    }

    cout<<"\nDanh sach sinh vien:"<<endl;
    for(int j=0; j<n; j++)
    {
        sinhVien[j].xuat();
        cout<<endl;
    }

    cout<<"\n\nDanh sach sinh vien co diem trung binh lon hon 5:"<<endl;
    for(int j=0; j<n; j++)
    {
        sinhVien[j].xuatDieuKien();
    }

    system("pause");//pause hit a key
}