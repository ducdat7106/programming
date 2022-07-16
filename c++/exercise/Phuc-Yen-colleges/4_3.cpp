#include <iostream>
using namespace std;

class SP
{
    float T, A;

public:
    friend istream &operator>>(istream &x, SP &y);
    friend ostream &operator<<(ostream &x, SP &y);
    SP operator+(SP y);
    SP operator-(SP y);
    SP()
    {
        T = A = 0;
    }
    SP(float x1, float x2)
    {
        T = x1;
        A = x2;
    }
};
istream &operator>>(istream &x, SP &y)
{
    cout << "Phan thuc: ";
    x >> y.T;
    cout << "Phan ao: ";
    x >> y.A;
    return x;
}
ostream &operator<<(ostream &x, SP &y)
{
    x << y.T << "+" << y.A << "*i";
    return x;
}
SP SP::operator+(SP y)
{
    SP z;
    z.T = T + y.T;
    z.A = A + y.A;
    return z;
}
SP SP::operator-(SP y)
{
    SP z;
    z.T = T - y.T;
    z.A = A - y.A;
    return z;
}
int main()
{
    SP x, y, z;
    cout << "SP x: \n";
    cin >> x;
    cout << x << endl;
    cout << "SP y: \n";
    cin >> y;
    cout << y << endl;
    z = x + y;
    cout << "Cong sp: " << z << endl;
    z = x - y;
    cout << "Tru sp: " << z << endl;

    system("pause");
}