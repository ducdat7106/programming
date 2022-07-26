#include <iostream>

using namespace std;

// hoán vị 2 phần tử
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// phân loại phân vùng
int partition(int *arr, int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
        if (arr[i] <= pivot)
            count++;

    // giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i=start, j=end;

    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivot)
            i++;
        while (arr[j]>pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    //bace case
    if(start>=end)
        return ;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void outputArray(int arr[], int n)
{
    cout<<endl;

    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
}

void inputArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap phan tu A["<<i+1<<"]= ";
        cin>>arr[i];
    }
}

int main()
{
    int arr[] = { 1,3,4,2,5,6,8,9};
    int n = sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    quickSort(arr, 0, n-1);
    outputArray(arr, n);
}