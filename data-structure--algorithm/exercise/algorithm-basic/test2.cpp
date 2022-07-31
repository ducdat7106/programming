#include <iostream>

using namespace std;

int absolute_different(int number);

int main()
{
    cout<<absolute_different(53)<<endl;
    cout<<absolute_different(30)<<endl;
    cout<<absolute_different(51)<<endl;
    return 0;
}

int absolute_different(int number)
{
    const int _number = 51;
    return (number >= _number) ? (number - _number)*3 : (_number - number);
}