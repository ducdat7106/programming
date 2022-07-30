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

class nhanVienSuaOngNuoc : public NhanVien
{
private:
    float soGioSua;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienLuongSuaOngNuoc();
};

class nhanVienGiaoHang : public NhanVien
{
private:
    float so_hang_giao;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienLuongGiaoHang();
};

class nhanVienXeOm : public NhanVien
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
    while (getchar() != '\n')
        ; // xoa bo nho dem trc khi nhap chuoi
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

    cout << "\nSo hang giao: " << so_hang_giao;
    cout << "\nTien luong: " << tienLuongGiaoHang() << endl;
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

    cout << "\nSo km: " << so_km;
    cout << "\nTien luong: " << tienLuongXeOm() << endl;
}

float nhanVienXeOm::tienLuongXeOm()
{
    return so_km * 1;
}

// ham tinh tong tien luong
double tongLuongNVSuaOngNuoc(nhanVienSuaOngNuoc *ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i]->tienLuongSuaOngNuoc();
    }

    return sum;
}

double tongLuongNVGiaoHang(nhanVienGiaoHang *ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i]->tienLuongGiaoHang();
    }

    return sum;
}

double tongLuongNVXeOm(nhanVienXeOm *ds[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ds[i]->tienLuongXeOm();
    }

    return sum;
}

// ham hoan vi 2 doi tuong cho nhau
void hoanViNVSuaOngNuoc(nhanVienSuaOngNuoc *x1, nhanVienSuaOngNuoc *x2)
{
    nhanVienSuaOngNuoc *temp = x1;
    x1 = x2;
    x2 = temp;
}
// ham hoan vi 2 doi tuong cho nhau
void hoanViNVGiaoHang(nhanVienGiaoHang *x1, nhanVienGiaoHang *x2)
{
    nhanVienGiaoHang *temp = x1;
    x1 = x2;
    x2 = temp;
}

void hoanViNVXeOm(nhanVienXeOm *x1, nhanVienXeOm *x2)
{
    nhanVienXeOm *temp = x1;
    x1 = x2;
    x2 = temp;
}

// ham sap xep danh sach giam dan theo luong
void sapXepLuongGiam_ds_nv_suaOngNuoc(nhanVienSuaOngNuoc *ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i]->tienLuongSuaOngNuoc() < ds[j]->tienLuongSuaOngNuoc())
                hoanViNVSuaOngNuoc(ds[i], ds[j]);
        }
}

void sapXepLuongGiam_ds_nv_giaoHang(nhanVienGiaoHang *ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i]->tienLuongGiaoHang() < ds[j]->tienLuongGiaoHang())
                hoanViNVGiaoHang(ds[i], ds[j]);
        }
}

void sapXepLuongGiam_ds_nv_xeOm(nhanVienXeOm *ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i]->tienLuongXeOm() < ds[j]->tienLuongXeOm())
                hoanViNVXeOm(ds[i], ds[j]);
        }
}

void Menu(nhanVienSuaOngNuoc *ds_nv_suaOngNuoc[], nhanVienGiaoHang *ds_nv_giaoHang[], nhanVienXeOm *ds_nv_xeOm[], int n, int m, int l)
{
    int luachon;

    while (true)
    {
        system("cls"); // xoa man hinh
        cout << "\n\n\t\t=====Chuong trinh quan ly=====";
        cout << "\n1. Nhap thong tin nv sua ong nuoc";
        cout << "\n2. Nhap thong tin nv giao hang";
        cout << "\n3. Nhap thong tin nv xe om" << endl;
        cout << "\n4. Xuat thong tin nv sua ong nuoc";
        cout << "\n5. Xuat thong tin nv giao hang";
        cout << "\n6. Xuat thong tin nv xe om" << endl;
        cout << "\n7. Tong luong 3 loai nhan vien";
        cout << "\n8. Sap xep nhan vien giam dan theo luong";
        cout << "\n\n0. Thoat chuong trinh";
        cout << "\n\n\t\t=====End=====";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon < 0 || luachon > 8)
        {
            cout << "\n\n\t\tNhap sai. Moi nhap lai! ";
        }

        if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            nhanVienSuaOngNuoc *nv_suaOngNuoc = new nhanVienSuaOngNuoc(); // doi tuong con tro

            cout << "\n\n\t\tNhap thong tin nv sua ong nuoc\n";
            nv_suaOngNuoc->nhapThongTin();

            // them doi tuong con tro nv sua ong nuoc vao danh sach con tro ds_nv_suaong nuoc
            ds_nv_suaOngNuoc[n] = nv_suaOngNuoc;
            n++;
        }
        else if (luachon == 2)
        {
            nhanVienGiaoHang *nv_giaoHang = new nhanVienGiaoHang();

            cout << "\n\n\t\tNhap thong tin nv giao hang\n";
            nv_giaoHang->nhapThongTin();

            // them doi tuong con tro nv sua ong nuoc vao danh sach con tro ds_nv_suaong nuoc
            ds_nv_giaoHang[m] = nv_giaoHang;
            m++;
        }
        else if (luachon == 3)
        {
            nhanVienXeOm *nv_xeOm = new nhanVienXeOm();

            cout << "\n\n\t\tnhap thong tin nv xe om\n";
            nv_xeOm->nhapThongTin();

            // them doi tuong con tro nv sua ong nuoc vao danh sach con tro ds_nv_suaong nuoc
            ds_nv_xeOm[l] = nv_xeOm;
            l++;
        }
        else if (luachon == 4)
        {
            if (n > 0)
            {
                cout << "\n\n\t\tXuat danh sach nhan vien sua ong nuoc";
                for (int i = 0; i < n; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien sua ong nuoc thu " << i + 1;
                    ds_nv_suaOngNuoc[i]->xuatThongTin();
                }
                cout << "\n\n\t\tTong tien luong: " << tongLuongNVSuaOngNuoc(ds_nv_suaOngNuoc, n) << endl;
            }
            else
            {
                cout << "\nKhong co nhan vien de hien thi!";
            }

            system("pause");
        }
        else if (luachon == 5)
        {
            if (m > 0)
            {
                cout << "\n\n\t\tXuat danh sach nhan vien giao hang";
                for (int i = 0; i < n; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien giao hang thu " << i + 1;
                    ds_nv_giaoHang[i]->xuatThongTin();
                }
                cout << "\n\n\t\tTong tien luong: " << tongLuongNVGiaoHang(ds_nv_giaoHang, m);
            }
            else
            {
                cout << "\nKhong co nhan vien de hien thi!";
            }

            system("pause");
        }
        else if (luachon == 6)
        {
            if (l > 0)
            {
                cout << "\n\n\t\tXuat danh sach nhan vien xe om";
                for (int i = 0; i < n; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien xe om thu " << i + 1;
                    ds_nv_xeOm[i]->xuatThongTin();
                }
                cout << "\n\n\t\tTong tien luong: " << tongLuongNVXeOm(ds_nv_xeOm, l);
            }
            else
            {
                cout << "\nKhong co nhan vien de hien thi!";
            }

            system("pause");
        }
        else if (luachon == 7)
        {

            double sum_luong = tongLuongNVSuaOngNuoc(ds_nv_suaOngNuoc, n) + tongLuongNVGiaoHang(ds_nv_giaoHang, m) + tongLuongNVXeOm(ds_nv_xeOm, l);
            cout << "\n\n\t\tTong tien cong ty can tra hang thang: " << (size_t)sum_luong<<endl;
            system("pause");
        }
        else if (luachon == 8)
        {
            int dem = 0;

            if (n > 0)
            {
                dem = 1;
                cout << "\n\n\t\tDS giam dan luong sua ong nuoc: \n";
                sapXepLuongGiam_ds_nv_suaOngNuoc(ds_nv_suaOngNuoc, n);
                for (int i = 0; i < n; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien sua ong nuoc thu " << i + 1;
                    ds_nv_suaOngNuoc[i]->xuatThongTin();
                }
            }

            if (m > 0)
            {
                dem = 1;
                cout << "\n\n\t\tDS giam dan luong giao hang: \n";
                sapXepLuongGiam_ds_nv_giaoHang(ds_nv_giaoHang, m);
                for (int i = 0; i < m; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien giao hang thu " << i + 1;
                    ds_nv_giaoHang[i]->xuatThongTin();
                }
            }

            if (l > 0)
            {
                dem = 1;
                cout << "\n\n\t\tDS giam dan luong xe om: \n";
                sapXepLuongGiam_ds_nv_xeOm(ds_nv_xeOm, l);
                for (int i = 0; i < l; i++)
                {
                    cout << "\n\n\t\tThong tin nhan vien xe om thu " << i + 1;
                    ds_nv_xeOm[i]->xuatThongTin();
                }
            }

            if (dem == 0)
                cout << "\nKhong co nhan vien de sap xep!"<<endl;

            system("pause");
        }
    }

    // giai phong cac doi tuong con tro dc cap phat dong (new)
    for (int i = 0; i < n; i++)
    {
        delete ds_nv_suaOngNuoc[i];
        ds_nv_suaOngNuoc[i] = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        delete ds_nv_giaoHang[i];
        ds_nv_giaoHang = NULL;
    }

    for (int i = 0; i < l; i++)
    {
        delete ds_nv_xeOm[i];
        ds_nv_xeOm[i] = NULL;
    }
}

int main()
{
    nhanVienSuaOngNuoc *ds_suaOngNuoc[100]; // doi tuong con tro
    nhanVienGiaoHang *ds_giaoHang[100]; //mảng 1 chiều các con trỏ
    nhanVienXeOm *ds_xeOm[100];
    //khai báo mảng chứa các con trỏ, nhưng ko dùng toán tử new-->ko cần phải giải phóng

    int n = 0; // so luong nhan vien sua ong nuoc
    int m = 0;
    int l = 0;

    Menu(ds_suaOngNuoc, ds_giaoHang, ds_xeOm, n, m, l);

    system("pause");
    return 0;
}