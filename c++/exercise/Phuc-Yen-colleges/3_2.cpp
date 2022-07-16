#include <iostream>
#include <string.h>
#include <iomanip> //setw()
using namespace std;

class BenhNhan
{
    char Ten[30], GioiTinh[5], DiaChi[30], TienSuBenh[50];
    int Tuoi;

public:
    void nhap();
    void xuat();
};

class BacSi
{
    char TenBacSi[30], NoiCongTac[50];

public:
    void nhap();
    void xuat();
};

class TrieuChung
{
    char MaChieuTrung[30], TenChieuTrung[50];

public:
    void nhap();
    void xuat();
};

class Phieu
{
    char NgayKham[30], MaPhieu[30];
    BenhNhan bn;
    BacSi bs;
    int n;
    TrieuChung ct[100];
    char KetLuan[50];

public:
    void nhap();
    void xuat();
};

void BenhNhan::nhap()
{
    cout << "Nhap ten: ";
    fflush(stdin);
    fgets(Ten, 30, stdin);

    cout << "Nhap gioi tinh: ";
    fflush(stdin);
    fgets(GioiTinh, 5, stdin);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    fgets(DiaChi, 30, stdin);

    cout << "Nhap tien su benh: ";
    fflush(stdin);
    fgets(TienSuBenh, 50, stdin);

    cout << "Nhap tuoi: ";
    cin >> Tuoi;
}

void BenhNhan::xuat()
{
    cout << "Ten: " << Ten;
    cout << "Gioi tinh: " << GioiTinh;
    cout << "Tuoi: " << Tuoi << endl;
    cout << "Dia chi: " << DiaChi;
    cout << "Tien su benh: " << TienSuBenh;
}

void BacSi::nhap()
{
    cout << "Nhap ten bac si: ";
    fflush(stdin);
    fgets(TenBacSi, 30, stdin);

    cout << "Nhap noi cong tac: ";
    fflush(stdin);
    fgets(NoiCongTac, 50, stdin);
}

void BacSi::xuat()
{
    cout << "Ten: " << TenBacSi;
    cout << "Ten benh vien: " << NoiCongTac;
}

void TrieuChung::nhap()
{
    cout << "Nhap ma trieu chung: ";
    fflush(stdin);
    fgets(MaChieuTrung, 30, stdin);

    cout << "Nhap ten trieu chung: ";
    fflush(stdin);
    fgets(TenChieuTrung, 50, stdin);
}

void TrieuChung::xuat()
{
    cout << setw(5) << MaChieuTrung << setw(20) << TenChieuTrung << endl;
}

void Phieu::nhap()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    fgets(MaPhieu, 30, stdin);

    cout << "Nhap ngay kham: ";
    fflush(stdin);
    fgets(NgayKham, 30, stdin);

    bn.nhap();
    bs.nhap();

    cout << "Nhap so luong trieu chung: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        ct[i].nhap();

    cout << "Nhap ket luan: ";
    fflush(stdin);
    fgets(KetLuan, 30, stdin);
}

void Phieu::xuat()
{
    cout << "     PHIEU KHAM BENH\n";
    cout << "Ma phieu: " << MaPhieu;
    cout << "Ngay kham: " << NgayKham;
    bn.xuat();
    bs.xuat();
    cout << "Ma trieu chung       Ten trieu chung\n";
    for (int i = 0; i < n; i++)
        ct[i].xuat();

    cout << "Ket luan: " << KetLuan;
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
