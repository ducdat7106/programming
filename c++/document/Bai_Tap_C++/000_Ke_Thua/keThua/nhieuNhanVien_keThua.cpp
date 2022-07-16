#include <iostream>
#include <string>
#include <conio.h> //co getchar()

using namespace std;

class NhanVien
{
protected:
    int tuoi;
    string ten;
public:
    void nhapThongTin();
    void xuatThongTin();
};

class nhanVienSuaOngNuoc:public NhanVien
{
private:
    float soGioSua;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienLuongSuaOngNuoc();
};

class nhanVienGiaoHang:public NhanVien
{
private:
    float so_hang_giao;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienLuongGiaoHang();
};

class nhanVienXeOm:public NhanVien
{
private:
    float so_km;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienLuongXeOm();
};


void NhanVien::nhapThongTin()
{
    while (getchar() != '\n'); // xoa bo nho dem trc khi nhap chuoi
    cout << "\nNhap ten: ";
    getline(cin, ten);

    cout << "\nNhap tuoi: ";
    cin >> this->tuoi;
}

void NhanVien::xuatThongTin()
{
    cout << "\nTen: " << this->ten;
    cout << "\nTuoi: " << this->tuoi;
}

void nhanVienSuaOngNuoc::nhapThongTin()
{
    NhanVien::nhapThongTin();

    cout << "\nNhap so gio sua: ";
    cin >> soGioSua;
}

void nhanVienSuaOngNuoc::xuatThongTin()
{
    NhanVien::xuatThongTin();

    cout << "\nSo gio sua: " << soGioSua;
    cout << "\nTien luong: " << tienLuongSuaOngNuoc();
}

float nhanVienSuaOngNuoc::tienLuongSuaOngNuoc()
{
    return (size_t)(soGioSua * 5); // 5 = 50 000
}

void nhanVienGiaoHang::nhapThongTin()
{
    NhanVien::nhapThongTin();

    cout << "\nSo hang giao: ";
    cin >> so_hang_giao;
}

void nhanVienGiaoHang::xuatThongTin()
{
    NhanVien::xuatThongTin();
    
    cout<<"\nSo hang giao: "<<so_hang_giao;
    cout<<"\nTien luong: "<< tienLuongGiaoHang()<<endl;
    
}

float nhanVienGiaoHang::tienLuongGiaoHang()
{
    return (size_t)(so_hang_giao * 3.5); // 3.5 = 35 000
}

void nhanVienXeOm::nhapThongTin()
{
    NhanVien::nhapThongTin();

    cout << "\nSo km: ";
    cin >> so_km;
}

void nhanVienXeOm::xuatThongTin()
{
    NhanVien::xuatThongTin();

    cout << "\nSo km: "<<so_km;
    cout<<"\nTien luong: "<<tienLuongXeOm()<<endl;
}

float nhanVienXeOm::tienLuongXeOm()
{
    return so_km * 1;
}

// ham tinh tong tien luong
double tongLuongNVSuaOngNuoc(nhanVienSuaOngNuoc ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i].tienLuongSuaOngNuoc();
    }

    return sum;
}

double tongLuongNVGiaoHang(nhanVienGiaoHang ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i].tienLuongGiaoHang();
    }

    return sum;
}

double tongLuongNVXeOm(nhanVienXeOm ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i].tienLuongXeOm();
    }

    return sum;
}


int main()
{
    // int *a;
    // int *b = new int;
    // a=b;

    // int *a[100];
    // int *b = new int();
    // a[0] = b;

    nhanVienSuaOngNuoc *ds[100];
    nhanVienSuaOngNuoc *nv_1 = new nhanVienSuaOngNuoc();
    nhanVienSuaOngNuoc *nv_2 = new nhanVienSuaOngNuoc();
    nhanVienSuaOngNuoc *nv_3 = new nhanVienSuaOngNuoc();

    ds[0] = nv_1;
    ds[1] = nv_2;
    ds[2] = nv_3;

    

    delete[] nv_1;
    nv_1 = NULL;

    system("pause");
    return 0;
}