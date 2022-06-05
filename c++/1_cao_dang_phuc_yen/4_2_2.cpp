#include<iostream>

using namespace std;

class PS
{
    int TS, MS;
public:
    PS();
    PS(int t, int m);

    friend istream & operator >>(istream & x, PS & y);
    friend ostream & operator<<(ostream & x, PS & y);

    PS operator*(PS y);
};

PS::PS()
{
    TS=0;
    MS=1;
}

PS::PS(int t, int m)
{
    TS=t;
    MS=m;
}

PS PS::operator*(PS y)
{
    PS z;
    z.TS = TS*y.TS;
    z.MS = MS*y.MS;
}

istream & operator>>(istream &x, PS &y)
{
    cout<<"Tu so: ";
    x>>y.TS;

    cout<<"Mau so: ";
    x>>y.MS;

    return x;
}

ostream & operator <<(ostream & x, PS &y)
{
    x<<y.TS<<"/"<<y.MS;

    return x;
}



int main()
{
    system("cls");
    PS x,y,z;

    cout<<"PS x:\n";
    cin>>x;

    cout<<"PS y:\n";
    cin>>y;

    cout<<x<<endl;
    cout<<y<<endl;

    z=x*y;

    cout<<"Phep nhan"<<z<<endl;

    return 0;
    system("pause");
}