#include <iostream>

using namespace std;

bool test(int *array, int length);

int main()
{
    int arr1[] = {1, 1, 2, 3, 1};
    size_t len = sizeof(arr1) / sizeof(arr1[0]); // size of array integer
    cout << test(arr1, len) << endl;

    int arr2[] = {1, 1, 2, 4, 1};
    len = sizeof(arr2) / sizeof(arr2[0]);
    cout << test(arr2, len) << endl;

    int arr3[] = {1, 1, 2, 3, 4};
    len = sizeof(arr3) / sizeof(arr3[0]);
    cout << test(arr3, len) << endl;

    int arr4[] = {1, 1, 2, 3, 1, 1, 2, 3};
    len = sizeof(arr4) / sizeof(arr4[0]);
    cout << test(arr4, len) << endl;

    return 0;
}

bool test(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] != 1 && array[i] != 2 && array[i] != 3)
        {
            return false;
        }
    }

    return true;
}