#include <bits/stdc++.h>
using namespace std;

void bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {7,8,9,1};
    bubble(arr, 4);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << "  ";
    cout << endl;
}