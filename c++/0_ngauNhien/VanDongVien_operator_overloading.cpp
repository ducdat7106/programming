#include <iostream>
#include<cstring>
using namespace std;

class VanDongVien
{
protected:
    //string hoten, monthidau;
    char hoten[30], monthidau[30];
    int tuoi;
    float cannang, chieucao;

public:
    VanDongVien();

VanDongVien(char[] ,char[] , int, float , float);

    void set();
    void get();

    friend istream &operator>>(istream &is_input, VanDongVien &vdv);

    friend ostream &operator<<(ostream &os_output, VanDongVien &vdv);

    friend void printArray(VanDongVien &vdv, int n);
};

VanDongVien::VanDongVien()
{
    strcpy(hoten, " ");
    strcpy(monthidau, " ");
    tuoi = 0;
    cannang = chieucao = 0;
}

VanDongVien::VanDongVien(char hoten1[], char monthidau1[], int tuoi1, float cannang1, float chieucao1)
{
    strcpy(hoten, hoten1);
    strcpy(monthidau, monthidau1);
    tuoi = tuoi1;
    cannang = cannang1;
    chieucao = chieucao1;
}


void sort()
{
    
}

void printArray(VanDongVien &vdv, int n)
{
    cout << "Danh sach van dong vien: ";
    for (int i = 0; i < n; i++)
    {
        // cout << vdv.get() << endl;
    }
}

istream &operator>>(istream &is_input, VanDongVien &vdv)
{
    cout << "Ho ten: ";
    fflush(stdin);
    fgets(vdv.hoten, sizeof(vdv.hoten), stdin);
}

int main()
{
    system("cls");

    system("pause");
    return 0;
}