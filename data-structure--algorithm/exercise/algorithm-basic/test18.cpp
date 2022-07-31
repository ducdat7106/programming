#include <iostream>

using namespace std;

int test(int x, int y, int z);
int test_lib(int x, int y, int z);

int main()
{
    cout << test(1, 2, 3) << endl;
    cout << test(1, 3, 2) << endl;
    cout << test(1, 1, 1) << endl;
    cout << test(1, 2, 2) << endl;

    // cout << test_lib(1, 2, 3) << endl;
    // cout << test_lib(1, 3, 2) << endl;
    // cout << test_lib(1, 1, 1) << endl;
    // cout << test_lib(1, 2, 2) << endl;

    return 0;
}

int find_max(int x, int y)
{
    return (x >= y ? x : y);
}

int test(int x, int y, int z)
{
    int number_max = find_max(x, find_max(y, z));
    return number_max;
}

int test_lib(int x, int y, int z)
{
    int number_max = max(x, max(y, z));
    return number_max;
}