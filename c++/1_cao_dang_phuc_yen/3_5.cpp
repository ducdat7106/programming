#include<iostream>

using namespace std;

class KhachHang
{
    char MaKhachHang[30], TenKhachHang[30], DiaChi[30], CMT[30], DiaChi[30];
public:
    void nhap();
    void xuat();
};

class Phong
{
    char MaPhong[30], LoaiPhong[30], Hang[30];
    int SoNguoi;
public:
    void nhap();
    void xuat();
    friend class Phieu;
};

class Phieu
{
    char MaPhieu[30], NgayDat[30], NgayDen[30];
    int SoTienDatTruoc, TongNguoi;
    KhachHang kh;
    Phong p[100];
    int n;
public:
    void nhap();
    void xuat();
};

void KhachHang::nhap()
{
    cout<<"Nhap ma khach hang: ";
    fflush(stdin);
    fgets(MaKhachHang, 30, stdin);

    cout << "Nhap ten khach hang: ";
    fflush(stdin);
    fgets(TenKhachHang, 30, stdin);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    fgets(DiaChi, 30, stdin);

    cout << "Nhap so chung minh thu: ";
    fflush(stdin);
    fgets(MaKhachHang, 30, stdin);
}

void KhachHang::xuat()
{
    cout<<"Ma khach hang: "<<MaKhachHang;
    cout<<"Ten khach hang: "<<TenKhachHang;
    cout<<"Dia chi: "<<DiaChi;
    cout<<"CMT: "<<CMT;
}

void Phong::nhap()
{
    cout << "Nhap ma phong: ";
    fflush(stdin);
    fgets(MaPhong, 30, stdin);

    cout << "Nhap loai phong: ";
    fflush(stdin);
    fgets(LoaiPhong, 30, stdin);

    cout << "Nhap hang: ";
    fflush(stdin);
    fgets(Hang, 30, stdin);

    cout<<"Nhap so nguoi: ";
    cin>>SoNguoi;
}

void Phong::xuat()
{
    cout<<"Ma phong: "<<MaPhong;
    cout<<"Loai phong: "<<LoaiPhong;
    cout<<"Hang phong: "<<Hang;
    cout<<"So nguoi trong phong: "<<SoNguoi<<endl;
}

void Phieu::nhap()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    fgets(MaPhieu, 30, stdin);

    cout << "Nhap ngay dat: ";
    fflush(stdin);
    fgets(NgayDat, 30, stdin);

    cout << "Nhap ngay den: ";
    fflush(stdin);
    fgets(NgayDen, 30, stdin);

    cout<<"Nhap so tien dat truoc: ";
    cin>>SoTienDatTruoc;

    kh.nhap();

    cout<<"Nhap so phong: ";
    cin>>n;
    for(int i=0; i<n; i++)
        p[i].nhap();
}

void Phieu::xuat()
{
    cout<<"Ma phieu: "<<MaPhieu;
    cout<<"Ngay dat: "<<NgayDat;
    cout<<"Ngay den: "<<NgayDen;
    cout<<"So tien dat truoc: "<<SoTienDatTruoc;
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=p[i].SoNguoi;
    cout<<"Tong so nguoi: "<<sum<<endl;
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