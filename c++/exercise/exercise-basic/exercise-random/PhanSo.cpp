#include <iostream>
using namespace std;

class PhanSo
{
    int tuSo, mauSo;

public:
    PhanSo();
    ~PhanSo();

    void input();
    void output();

    friend PhanSo Cong(PhanSo a, PhanSo b);
    friend PhanSo Tru(PhanSo a, PhanSo b);
    friend PhanSo Nhan(PhanSo a, PhanSo b);
    friend PhanSo Chia(PhanSo a, PhanSo b);
};

PhanSo::PhanSo()
{
    tuSo = 0;
    mauSo = 1;
}

PhanSo::~PhanSo()
{
    tuSo = 0;
    mauSo = 1;
}

void PhanSo::input()
{
    cout << "Vao tu so:";
    cin >> tuSo;

    cout << "Vao mau so: ";
    cin >> mauSo;
}

void PhanSo::output()
{
    cout << "Phan So: " << tuSo << "/" << mauSo << endl;
}

PhanSo Cong(PhanSo a, PhanSo b)
{
    PhanSo temp;

    temp.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
    temp.mauSo = a.mauSo * b.mauSo;

    return temp;
}

PhanSo Tru(PhanSo a, PhanSo b)
{
    PhanSo temp;

    temp.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
    temp.mauSo = a.mauSo * b.mauSo;

    return temp;
}

PhanSo Nhan(PhanSo a, PhanSo b)
{
    PhanSo temp;

    temp.tuSo = a.tuSo*b.tuSo;
    temp.mauSo = a.mauSo*b.mauSo;

    return temp;
}
PhanSo Chia(PhanSo a, PhanSo b)
{
    PhanSo temp;

    temp.tuSo = a.tuSo*b.mauSo;
    temp.mauSo = a.mauSo*b.tuSo;

    return temp;
}

int main()
{
    system("cls");

    PhanSo ps1, ps2, ps3;
    
    cout<<"Nhap phan so thu 1: \n";
    ps1.input();

    cout << "Nhap phan so thu 2: \n";
    ps2.input();

    cout<<"Tong 2 phan so:\n";
    ps3 = Cong(ps1, ps2);
    ps3.output();

    return 0;

    system("pause");
}