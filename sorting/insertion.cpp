#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i,j,val;
    for(i = 1;i<n;i++)
    {
        val = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>val)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "  " << array[i];
    }
    cout << "\n";
}

int main()
{
    int data[] = {5,7,4,3,1};

    int size = sizeof(data) / sizeof(data[0]);

    insertionSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}