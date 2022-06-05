#include <iostream>
#include <iomanip>

using namespace std;

class KhachHang
{
    char MaKhacHang[30], TenKhachHang[30], DiaChi[30], SoDT[30];

public:
    void nhap();
    void xuat();
};

class Sach
{
    char MaSach[30], TenSach[30];
    int Gia, SoLuong, ThanhTien;

public:
    void nhap();
    void xuat();

    friend class Phieu;
};

class Phieu
{
    char MaPhieu[30], Ngay[30];

    KhachHang kh;

    int n;
    Sach s[100];

public:
    void nhap();
    void xuat();
};


void KhachHang::nhap()
{
    cout<<"Nhap ma khach hang: ";
    fflush(stdin);
    fgets(MaKhacHang, 30, stdin);

    cout << "Nhap ten khach hang: ";
    fflush(stdin);
    fgets(TenKhachHang, 30, stdin);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    fgets(DiaChi, 30, stdin);

    cout << "Nhap so dien thoai: ";
    fflush(stdin);
    fgets(SoDT, 30, stdin);
}

void KhachHang::xuat()
{
    cout<<"Ma khach hang: "<<MaKhacHang;
    cout<<"Ten khach hang: "<<TenKhachHang;
    cout<<"Dia chi: "<<DiaChi;
    cout<<"So dien thoai: "<<SoDT;
}

void Sach::nhap()
{
    cout << "Nhap ma sach: ";
    fflush(stdin);
    fgets(MaSach, 30, stdin);

    cout << "Nhap ten sach: ";
    fflush(stdin);
    fgets(TenSach, 30, stdin);

    cout << "Nhap gia: ";
    cin>>Gia;

    cout<<"Nhap so luong: ";
    cin>>SoLuong;    
}

void Sach::xuat()
{
    cout<<"Ma sach: "<<MaSach;
    cout<<"Ten sach: "<<TenSach;

    ThanhTien = Gia*SoLuong;
    cout<<"Gia      So luong      Thanh tien";
    cout<<Gia<<setw(10)<<SoLuong<<setw(10)<<ThanhTien<<endl;
}

void Phieu::nhap()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    fgets(MaPhieu, 30, stdin);

    cout << "Nhap ngay: ";
    fflush(stdin);
    fgets(Ngay, 30, stdin);

    kh.nhap();

    cout<<"Nhap so luong sach: ";
    cin>>n;
    for(int i=0; i<n; i++)
        s[i].nhap();
}

void Phieu::xuat()
{
    cout<<"Ma phieu: "<<MaPhieu;
    cout<<"Ngay: "<<Ngay;

    for(int i=0; i<n; i++)
        s[i].xuat();

    int sum=0;
    for(int i=0; i<n; i++)
        sum+=s[i].ThanhTien;
    
    cout<<"Tong tien phai tra: "<<sum;
}

int main()
{
    system("cls");
    Phieu p;

    p.nhap();
    p.xuat();

    return 0;
    system("pause");
}