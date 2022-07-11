#include <iostream>
#include <string.h>

using namespace std;
#define MAX_LENGTH 100

class May;
class MayTinh;

class NhaSanXuat
{
private:
    char tenNhaSX[25], diaChi[25];

    friend class May;
    friend class MayTinh;

    friend void In(MayTinh *mt, int n);
    friend void Xoa(MayTinh *mt, int *n);

public:
    NhaSanXuat()
    {
        strcpy(tenNhaSX, "");
        strcpy(diaChi, "");
    }
};

class May
{
public:
    char nhanHieu[25];
    NhaSanXuat NSX;
    int giaThanh;

    void input();
    void output();
};

class MayTinh : public May
{
private:
    int tocDo, dungLuongRam, dungLuongHHD;

public:
    void input();
    void output();
    friend void In(MayTinh *mt, int n);
    friend void SapXep(MayTinh *mt, int n);
    friend void Xoa(MayTinh *mt, int *n);
};

void May::input()
{
    cout << "Nhap nhan hieu: ";
    fflush(stdin);
    fgets(nhanHieu, 25, stdin);

    cout << "Nhap nha san xuat: ";
    cout << "\nTen nha san xuat: ";
    fflush(stdin);
    fgets(NSX.tenNhaSX, 25, stdin);

    cout << "\nDia chi: ";
    fflush(stdin);
    fgets(NSX.diaChi, 25, stdin);

    cout << "Gia thanh: ";
    cin >> giaThanh;
}

void May::output()
{
    cout << "Nhan hieu: " << nhanHieu << endl;
    cout << "Ten nha san xuat: " << NSX.tenNhaSX << endl;
    cout << "Dia chi: " << NSX.diaChi << endl;
    cout << "Gia thanh: " << giaThanh << endl;
}

void MayTinh::input()
{
    May::input();

    cout << "Nhap toc do: ";
    cin >> tocDo;

    cout << "Nhap dung luong Ram: ";
    cin >> dungLuongRam;

    cout << "Nhap dung luong HHD";
    cin >> dungLuongHHD;
}

void MayTinh::output()
{
    May::output();

    cout << "Toc do: " << tocDo << endl;
    cout << "Dung luong Ram: " << dungLuongRam << endl;
    cout << "Dung luong HHD: " << dungLuongHHD << endl;
}

void In(MayTinh *mt, int n)
{
    for (int i = 0; i < n; i++)
        if (strcmp(mt[i].NSX.tenNhaSX, "IBM") == 0)
            mt[i].output();
}

void swap(MayTinh *a, MayTinh *b)
{
    MayTinh temp = *a;
    *a = *b;
    *b = temp;
}

void SapXep(MayTinh *mt, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (mt[i].giaThanh > mt[j].giaThanh)
                swap(mt[i], mt[j]);

    for (int i = 0; i < n; i++)
        mt[i].output();
}

void dich(int vitri, MayTinh *mt, int *n)
{
    for(int k=vitri; k<*n; k++)
        mt[k]=mt[k+1];
    *n--;
}
void Xoa(MayTinh *mt, int *n)
{
    for(int i=0; i<*n; i++)
        while(strcmp(mt[i].NSX.tenNhaSX, "Intel")==0)
            dich(i, mt, n);
}

int main()
{
    system("cls");

    MayTinh MT[MAX_LENGTH];
    int n, i;

    cout << "----Nhap so luong may tinh: ";
    cin >> n;
    for (i = 0; i < n; i++)
        MT[i].input();

    cout<<"\n-----May tinh hang IBM\n";
    In(MT, n);

    cout<<"\n-----Sap xep may tinh tang dan theo gia:\n";
    SapXep(MT, n);

    cout<<"\n-----Danh sach may tinh sau khi xoa:\n";
    Xoa(MT, &n);
    for(int i=0; i<n; i++)
        MT[i].output();

    system("pause");
}