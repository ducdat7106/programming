#include <iostream>

using namespace std;

bool test(int x, int y);

int main()
{
    cout<<test(-1, 120)<<endl;
    cout<<test(120, -120)<<endl;
    cout<<test(5, 120)<<endl;

    return 0;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

bool test(int x, int y)
{
    if (x > y)
        swap(x, y);

    return (y > 100 && x < 0);
}