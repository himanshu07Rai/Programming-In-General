#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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

    selectionSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}