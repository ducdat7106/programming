#include <iostream>
#include <string>
#include <conio.h> //co getchar()

using namespace std;

class xe
{
protected:
    string hoTenNguoiThue;
    float soGioThue;

public:
    void nhapThongTin();
    void xuatThongTin();
};

void xe::nhapThongTin()
{
    while (getchar() != '\n')
        ; // xoa bo nho dem trc khi nhap chuoi
    cout << "\nNhap ho ten nguoi thue: ";
    getline(cin, hoTenNguoiThue);

    cout << "\nNhap so gio thue: ";
    cin >> soGioThue;
}

void xe::xuatThongTin()
{
    cout << "\nHo ten nguoi thue: " << hoTenNguoiThue;
    cout << "\nSo gio thue: " << soGioThue;
}

class xeDap : public xe
{
private:
public:
    float tienThueXeDap();
};

float xeDap::tienThueXeDap()
{
    return (10 + (soGioThue - 1) * 8); // 10 = 10 000
}

class xeMay : public xe
{
private:
    int loaiXe;
    string bienSo;

public:
    void nhapThongTin();
    void xuatThongTin();
    float tienThueXeMay();

    void setter_loaiXe(int LOAIXE)
    {
        loaiXe = LOAIXE;
    }

    int getter_loaiXe()
    {
        return loaiXe;
    }
};

void xeMay::nhapThongTin()
{
    xe::nhapThongTin();

    cout << "\nNhap loai xe can thue(100-250): ";
    cin >> loaiXe;

    while (getchar() != '\n')
        ; // xoa bo nho dem trc khi nhap chuoi
    cout << "\nNhap bien so xe: ";
    getline(cin, bienSo);
}

void xeMay::xuatThongTin()
{
    xe::xuatThongTin();

    cout << "\nLoai xe: " << loaiXe;
    cout << "\nBien so: " << bienSo;
}

float xeMay::tienThueXeMay()
{
    float s = 0;

    if (loaiXe == 100)
    {
        s = 150; // 150 = 150 000
    }
    else
    {
        s = 200;
    }

    return (s + (soGioThue - 1) * 100);
}

void xuatTatCaThongTinThueXe(xeDap ds_xedap[], xeMay ds_xemay[], int n, int m)
{
    int dem = 0;
    cout << "\n\n\t\tDanh sach thue xe dap\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tThong tin thue xe dap thu " << dem++ << endl;
        ds_xedap[i].xuatThongTin();
        cout << "\nTien thue: " << ds_xedap[i].tienThueXeDap();
    }

    cout << "\n\n\t\tDanh sach thue xe may\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\n\tThong tin thue xe may thu " << dem++ << endl;
        ds_xemay[i].xuatThongTin();
        cout << "\nTien thue: " << ds_xemay[i].tienThueXeMay();
    }
}

float tongTienThueXe(xeDap ds_xedap[], xeMay ds_xemay[], int n, int m)
{
    float tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong += ds_xedap[i].tienThueXeDap();
    }

    for (int i = 0; i < m; i++)
    {
        tong += ds_xemay[i].tienThueXeMay();
    }

    return tong;
}

void xuatTatCaThongTinThueXeDap(xeDap ds_xedap[], int n)
{
    cout << "\n\n\t\tDanh sach thue xe dap\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tThong tin thue xe dap thu " << i + 1 << endl;
        ds_xedap[i].xuatThongTin();
        cout << "\nTien thue: " << ds_xedap[i].tienThueXeDap();
    }

    cout << "\n\n\t\tTong tien thue xe dap: ";

    float tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong += ds_xedap[i].tienThueXeDap();
    }

    cout << (size_t)tong;
}

void Menu(xeDap ds_xedap[], xeMay ds_xemay[], int n, int m)
{
    int luachon;
    while (true)
    {
        system("cls"); // xoa man hinh
        cout << "\n\n\t\t========Chuong trinh quan ly===========";
        cout << "\n1. Nhap danh sach thue xe dap, xe may";
        cout << "\n2. Xuat tat ca thong tin thue xe";
        cout << "\n3. Tinh tong tien thue xe dap va xe may";
        cout << "\n4. Xuat thong tin lien quan den cho thue xe dap";
        cout << "\n5. Tinh tong tien thue xe may loai 250";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n\n\t\t===========End====================";

        cout << "\nNhap lua chon ";
        cin >> luachon;

        if (luachon < 0 || luachon > 5)
        {
            cout << "\nNhap sai.Moi nhap lai!";
            system("pause");
        }
        else if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            int chon;
            while (true)
            {
                system("cls");
                cout << "\n1. Thue xe dap";
                cout << "\n2. Thue xe may";
                cout << "\n0. Thoat";

                cout << "\nNhap lua chon: ";
                cin >> chon;
                if (chon < 0 || chon > 2)
                {
                    cout << "\nNhap sai. Moi nhap lai!";
                }
                else if (chon == 1)
                {
                    xeDap x;
                    cout << "\n\n\t\tNhap thong tin thue xe dap";
                    x.nhapThongTin();
                    ds_xedap[n] = x;
                    n++;
                }
                else if (chon == 2)
                {
                    xeMay x;
                    cout << "\n\n\t\tNhap thong tin thue xe may";
                    x.nhapThongTin();
                    ds_xemay[m] = x;
                    m++;
                }
                else if (chon == 0)
                {
                    system("cls");
                    break;
                }
            }
        }
        else if (luachon == 2)
        {
            xuatTatCaThongTinThueXe(ds_xedap, ds_xemay, n, m);
            system("pause");
        }
        else if (luachon == 3)
        {
            cout << "\n\n\t\tTong tien thue xe la: " << tongTienThueXe(ds_xedap, ds_xemay, n, m);
            system("pause");
        }
        else if (luachon == 4)
        {
            cout << "\nTat ca thong tin lien quan den viec thue xe dap";
            xuatTatCaThongTinThueXeDap(ds_xedap, n);
            system("pause");
        }
        else if (luachon == 5)
        {
            float dem = 0;

            cout << "\n\n\t\tDanh sach thue xe may loai 250 phan khoi";

            for (int i = 0; i < m; i++)
            {
                if (ds_xemay[i].getter_loaiXe() == 250)
                {
                    cout << "\n\tThong tin thue xe may thu " << ++dem << endl;
                    ds_xemay[i].xuatThongTin();
                    cout << "\nTien thue: " << ds_xemay[i].tienThueXeMay() << endl;
                }
            }
            system("pause");
        }
    }
}

int main()
{
    xeDap ds_xeDap[100];
    xeMay ds_xeMay[100];

    int n = 0;
    int m = 0;

    Menu(ds_xeDap, ds_xeMay, n, m);

    system("pause");
    return 0;
}