#include <iostream>

using namespace std;

struct SoPhuc
{
    float PhanThuc;
    float PhanAo;
};

typedef struct SoPhuc SP;

SP operator+(SP x, SP y)
{
    SP tg;
    tg.PhanThuc = x.PhanThuc + y.PhanThuc;
    tg.PhanAo = x.PhanAo + y.PhanAo;
    return tg;
}

int main()
{
    // system("cls");

    SP x1, y1, T1;

    x1.PhanThuc = 2;
    x1.PhanAo = 3;
    y1.PhanThuc = 3;
    y1.PhanAo = 5;

    T1 = operator+(x1, y1); // T1 = x1+y1;

    cout << "Ket qua: " << T1.PhanThuc << " +i " << T1.PhanAo;

    return 0;
    system("pause");
}