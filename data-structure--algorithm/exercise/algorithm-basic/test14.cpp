#include <iostream>

using namespace std;

bool test(int x, int y);

int main()
{
    cout<<test(100, 199)<<endl;
    cout<<test(99, 120)<<endl;
    cout<<test(10, 19)<<endl;
    cout<<test(300, 599)<<endl;


    return 0;
}

bool test(int x, int y)
{
    return (x <= 200 && y <= 200 && x >= 100 && y >= 100);
}