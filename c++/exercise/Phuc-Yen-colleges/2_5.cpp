#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:
    char HoTen[50];
    int Tuoi;

    void nhap();
    void xuat();
};

class BenhNhan;

class Hospital
{
private:
    char TenBV[50], DiaChi[50];
    Person GiamDoc;
    friend class BenhNhan;
    friend void In(BenhNhan *arr, int n);
};

class BenhNhan : public Person
{
    char TieuSu[30], ChanDoan[30];
    Hospital BenhVien;

public:
    void nhap();
    void xuat();
    friend void In(BenhNhan *arr, int n);
};

void Person::nhap()
{
    cout << "Nhap ho ten: ";
    fflush(stdin);
    fgets(HoTen, 30, stdin);

    cout << "Nhap tuoi: ";
    cin >> Tuoi;
}

void Person::xuat()
{
    cout << "Ho ten: " << HoTen;
    cout << "Tuoi: " << Tuoi;
}

void BenhNhan::nhap()
{
    Person::nhap();

    cout << "Nhap tieu su: ";
    fflush(stdin);
    fgets(TieuSu, 30, stdin);

    cout << "Nhap chan doan: ";
    fflush(stdin);
    fgets(ChanDoan, 30, stdin);

    cout << "Nhap ten benh vien: ";
    fflush(stdin);
    fgets(BenhVien.TenBV, 30, stdin);

    cout << "Nhap dia chi benh vien: ";
    fflush(stdin);
    fgets(BenhVien.DiaChi, 30, stdin);

    BenhVien.GiamDoc.nhap();
}

void BenhNhan::xuat()
{
    Person::xuat();

    cout << "Tieu su: " << TieuSu;
    cout << "Chan doan: " << ChanDoan;
    cout << "Ten benh vien: " << BenhVien.TenBV;
    cout << "Dia chi benh vien: " << BenhVien.DiaChi;

    BenhVien.GiamDoc.xuat();
}

void In(BenhNhan *arr, int n)
{
    int couter = 0;

    for (int i = 0; i < n; i++)
        if (strcmp(arr[i].BenhVien.TenBV, "ABC\n") == 0)
        {
            couter++;
            arr[i].xuat();
        }

    if (couter == 0)
        cout << "\nKhong co benh nhan nhu vay ton tai!!!\n";
}

void swap(BenhNhan *a1, BenhNhan *a2)
{
    BenhNhan temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void sort(BenhNhan *a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].Tuoi > a[j].Tuoi)
                swap(a[i], a[j]);

    for (int i = 0; i < n; i++)
        a[i].xuat();
}

int main()
{
    system("cls");
    BenhNhan bn[100];
    BenhNhan tg;
    int n, i, j;

    cout << "n= ";
    cin >> n;
    cout << "\n-----Nhap:\n";
    for (i = 0; i < n; i++)
    {
        cout << "\nBenh nhan " << i + 1 << endl;
        bn[i].nhap();
    }
    /*
    cout << "\n-----Xuat:\n";
    for(i=0; i<n; i++)
    {
        cout << "Benh nhan " << i + 1 << endl;
        bn[i].xuat();
    }
    */

    /*
     cout<<"--xuat benh nhan tang theo tuoi:\n";
     sort(bn, n);
     */

    cout << "\n----Benh nhan o trong benh vien co giam doc la Hoang Ha:\n";
    In(bn, n);

    system("pause");
}