#include<iostream>
using namespace std;

class PhanSo
{
    float TS, MS;
public:
    PhanSo();
    PhanSo(float t, float m);

    PhanSo operator+(PhanSo y);
    PhanSo operator-(PhanSo y);

    friend istream & operator >>(istream & x, PhanSo &y);
    friend ostream & operator<<(ostream & x, PhanSo & y);
};


PhanSo::PhanSo()
{
    TS = 0;
    MS=1;
}
PhanSo::PhanSo(float t, float m)
{
    TS=t;
    MS = m;
}

istream & operator>>(istream &x, PhanSo & y)
{
    cout<<"Tu so:";
    x>>y.TS;

    cout<<"Mau so: ";
    x>>y.MS;

    return x;
}

ostream & operator <<(ostream & x, PhanSo & y)
{
    x<<y.TS<<"/"<<y.MS;
    return x;
}

PhanSo PhanSo::operator+(PhanSo y)
{
    PhanSo z;

    z.TS = TS*y.MS + y.TS*MS;
    z.MS = MS*y.MS;

    return z;
}

PhanSo PhanSo::operator-(PhanSo y)
{
    PhanSo z;

    z.TS = TS*y.MS + y.TS*MS;
    z.MS = MS*y.MS;

    return z;
}

int main()
{
    PhanSo x,y,z;

    cout<<"PS x: \n";
    cin>>x;

    cout<<"PS y: \n";
    cin>>y;

    cout<<x<<endl;
    cout<<y<<endl;

    z=x+y;
    cout<<"Phep cong: "<<z<<endl;

    z=x-y;
    cout<<"Phep tru: "<<z<<endl;
    
    system("pause");
}