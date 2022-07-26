#include <iostream>

using namespace std;

bool test(int array[], int length_array);

int main()
{
    int arr1[] = {1, 1, 2, 2, 2, 3, 4, 5};
    size_t len = sizeof(arr1) / sizeof(arr1[0]);
    cout << test(arr1, len) << endl;

    int arr2[] = {1, 1, 2, 3, 2, 3, 4, 5};
    len = sizeof(arr2) / sizeof(arr2[0]);
    cout << test(arr2, len) << endl;

    int arr3[] = {1, 1, 1, 2, 2, 2, 3, 4, 5};
    len = sizeof(arr3) / sizeof(arr3[0]);
    cout << test(arr3, len) << endl;

    return 0;
}

bool test(int array[], int length_array)
{
    for (int i = 0; i < length_array - 2; i++)
        if (array[i] == array[i + 1] && array[i] == array[i + 2])
            return true;
    return false;
}