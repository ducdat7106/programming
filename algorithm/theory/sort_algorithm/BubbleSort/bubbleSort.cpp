#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[],  int n)
{
    int i,j;
    bool swapped;
    for(i=0; i<n-1; i++)
    {
        swapped = false;
        for(j=0;j<n-i-1; j++)
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        
        if(swapped == false)
            break;
    }
}

void printArray(int arr[], int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
}

int main()
{

    int arr[]={1,9,8,7,1,2,5,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"\nSorted array:\n";
    printArray(arr, n);
    return 0;
}