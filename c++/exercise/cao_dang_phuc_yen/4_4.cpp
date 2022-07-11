#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
class MT
{
    int n, m;
    float a[100][100];

public:
    friend istream &operator>>(istream &x, MT &y);
    friend ostream &operator<<(ostream &x, MT &y);
    MT operator-();
};
istream &operator>>(istream &x, MT &y)
{
    cout << "n= ";
    x >> y.n;
    cout << "m= ";
    x >> y.m;
    for (int i = 0; i < y.n; i++)
        for (int j = 0; j < y.m; j++)
        {
            gotoxy(5 + 3 * j, 5 + i);
            x >> y.a[i][j];
        }
    return x;
}
ostream &operator<<(ostream &x, MT &y)
{
    for (int i = 0; i < y.n; i++)
    {
        for (int j = 0; j < y.m; j++)
        {
            x << y.a[i][j] << " ";
        }
        x << endl;
    }
    return x;
}
MT MT::operator-()
{
    MT z;
    z.n = n;
    z.m = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            z.a[i][j] = -a[i][j];
    }
    return z;
}

int main()
{
    MT y, z;
    cout << "Nhap MT :\n";
    cin >> y;
    z = -y;
    cout << "Doi dau: \n"
         << z << endl;
    system("pause");
}