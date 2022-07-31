#include <iostream>

using namespace std;

int test(int *array, int number);

int main()
{
    int arr1[] = {1, 5, 5, 6, 7, 8, 5, 5, 9};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    cout << test(arr1, len) << endl;

    int arr2[] = {1, 5, 4, 6, 7, 8, 9};
    len = sizeof(arr2) / sizeof(arr2[0]);
    cout << test(arr2, len) << endl;

    int arr3[] = {1, 5, 5, 7, 8, 9};
    len = sizeof(arr3) / sizeof(arr3[0]);
    cout << test(arr3, len) << endl;

    return 0;
}

int test(int *array, int number)
{
    int counter = 0;
    for (int i = 0; i < number - 1; i++)
        if (array[i] == 5 && (array[i + 1] == 6 || array[i + 1] == 5))
            counter++;

    return counter;
}