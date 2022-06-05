#include <iostream>
#include <iomanip>

using namespace std;

class NhanVien
{
    char TenNhanVien[30], ChucVu[30];

public:
    void nhap();
    void xuat();
};

class Phong
{
    char Ten[30], MaPhong[30], TruongPhong[30];

public:
    void nhap();
    void xuat();
};

class Phieu;

class TaiSan
{
    char TenTaiSan[30], TinhTrang[30];
    int SoLuong;

public:
    void nhap();
    void xuat();
    friend class Phieu;
};

class Phieu
{
    char MaPhieu[30], Ngay[30];
    NhanVien nv;
    Phong p;
    int n;
    TaiSan ts[100];

public:
    void nhap();
    void xuat();
};

void NhanVien::nhap()
{
    cout << "Nhap ten nhan vien: ";
    fflush(stdin);
    fgets(TenNhanVien, 30, stdin);

    cout << "Nhap chuc vu: ";
    fflush(stdin);
    fgets(ChucVu, 30, stdin);
}

void NhanVien::xuat()
{
    cout << "Ten nhan vien: " << TenNhanVien;
    cout << "Chuc vu: " << ChucVu;
}

void Phong::nhap()
{
    cout << "Nhap ten phong: ";
    fflush(stdin);
    fgets(Ten, 30, stdin);

    cout << "Nhap ma phong: ";
    fflush(stdin);
    fgets(MaPhong, 30, stdin);

    cout << "Nhap truong phong: ";
    fflush(stdin);
    fgets(TruongPhong, 30, stdin);
}

void Phong::xuat()
{
    cout << "Ten phong: " << Ten;
    cout << "Ma phong: " << MaPhong;
    cout << "Truong Phong: " << TruongPhong;
}

void TaiSan::nhap()
{
    cout << "Nhap ten tai san: ";
    fflush(stdin);
    fgets(TenTaiSan, 30, stdin);

    cout << "Nhap tinh trang: ";
    fflush(stdin);
    fgets(TinhTrang, 30, stdin);

    cout << "Nhap so luong tai san: ";
    cin >> SoLuong;
}

void TaiSan::xuat()
{
    cout<<setw(5)<<TenTaiSan<<setw(15)<<SoLuong<<setw(15)<<TinhTrang<<endl;
}

void Phieu::nhap()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    fgets(MaPhieu, 30, stdin);

    cout << "Nhap ngay: ";
    fflush(stdin);
    fgets(Ngay, 30, stdin);

    nv.nhap();
    p.nhap();

    cout << "So loai tai san : ";
    cin >> n;

    for (int i = 0; i < n; i++)
        ts[i].nhap();
}

void Phieu::xuat()
{
    cout<<"\n       PHIEU KIEM KE TAI SAN\n";
    cout << "Ma phieu: " << MaPhieu;
    cout << "Ngay: " << Ngay;

    nv.xuat();
    p.xuat();

    cout << "Ten tai san      So luong        Tinh trang\n";
    for (int i = 0; i < n; i++)
        ts[i].xuat();

    cout << "So tai san da kiem ke:" << n << endl;

    int TongSoLuong = 0;
    for (int i = 0; i < n; i++)
        TongSoLuong += ts[i].SoLuong;
    cout << "Tong so luong: " << TongSoLuong << endl;
}

int main()
{
    system("cls");
    Phieu ph;

    ph.nhap();
    ph.xuat();

    return 0;
    system("pause");
}