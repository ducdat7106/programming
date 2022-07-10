#include<iostream>
// #include <>

using namespace std;
#define MaxLength 100

class SinhVien
{
    char MaSinhVien[30];
    char TenSinhVien[30];
public:
    void nhap();
    void xuat();
};

class Lop
{
    char TenLop[30];
    int Khoa;
public:
    void nhap();
    void xuat();
};

class MonHoc
{
    char TenMonHoc[30];
    int SoTrinh, Diem;
public:
    void nhap();
    void xuat();

    friend class Phieu;
};

class Phieu
{
    SinhVien sv;
    Lop l;
    int n;
    MonHoc m[MaxLength];
public:
    void nhap();
    void xuat();
};

void SinhVien::nhap()
{
    cout<<"Nhap MSV: ";
    fflush(stdin);
    fgets(MaSinhVien, 30, stdin);

    cout << "Nhap ten sinh vien: ";
    fflush(stdin);
    fgets(TenSinhVien, 30, stdin);
}

void SinhVien::xuat()
{
    cout<<"Ma sinh vien: "<<MaSinhVien;
    cout<<"Ho ten sinh vien: "<<TenSinhVien;
}

void Lop::nhap()
{
    cout<<"Nhap ten lop: ";
    fflush(stdin);
    fgets(TenLop, 30, stdin);

    cout<<"Nhap khoa: ";
    cin>>Khoa;
}

void Lop::xuat()
{
    cout<<"Lop: "<<TenLop;
    cout<<"Khoa: "<<Khoa<<endl;
}

void MonHoc::nhap()
{
    cout<<"Nhap ten mon hoc: ";
    fflush(stdin);
    fgets(TenMonHoc,30,stdin);

    cout<<"Nhap so trinh: ";
    cin>>SoTrinh;

    cout<<"Nhap diem: ";
    cin>>Diem;
}


void MonHoc::xuat()
{
    // cout<<"Ten mon hoc: "<<TenMonHoc;
    // cout<<"So trinh: "<<SoTrinh<<endl;
    // cout<<"Diem: "<<Diem<<endl; 

    cout<<setw(5)<<TenMonHoc<<setw(10)<<SoTrinh<<setw(5)<<Diem<<endl;
}

void Phieu::nhap()
{
    sv.nhap();
    l.nhap();

    cout<<"Nhap so mon hoc: ";
    cin>>n;

    for(int i=0; i<n; i++)
    m[i].nhap();
}

void Phieu::xuat()
{
    cout<<"          PHIEU BAO DIEM\n";
    sv.xuat();
    l.xuat();

    cout<<"Bang diem:\n";
    cout<<"Ten mon   So trinh  Diem\n";
    for(int i=0; i<n; i++)
        m[i].xuat();
    
    float D=0, TongSoTrinh=0, DiemTrungBinh=0;

    for(int i=0; i<n; i++)
    {
        D += m[i].SoTrinh*m[i].Diem;
        TongSoTrinh += m[i].SoTrinh;
    }

    DiemTrungBinh = D/TongSoTrinh;

    cout<<"     Diem trung binh: "<<DiemTrungBinh<<endl;
}

int main()
{
    system("cls");
    int n;
    Phieu p[100];

    cout<<"n= ";
    cin>>n;

    for(int i=0; i<n; i++)
        p[i].nhap();

    for (int i = 0; i < n; i++)
        p[i].xuat();

    system("pause");
    return 0;
}