#include <bits/stdc++.h>
using namespace std;

/* FIBONACCI SERIES*/
/* 0 1 1 2 3 5 8 13 21*/
// int fib(int n)
// {
//     if (n <= 1)
//         return n;
//     else
//     {
//         return fib(n - 2) + fib(n - 1);
//     }
// }

// Driver code
// int main()
// {
//     cout << fib(5);
// }

/* FIBONACCI SERIES ( MEMOIZATION ) */
int fib(int n, int arr[])
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if (arr[n - 2] == -1)
            arr[n - 2] = fib(n - 2, arr);
        if (arr[n - 1] == -1)
            arr[n - 1] = fib(n - 1, arr);
        return arr[n - 2] + arr[n - 1];
    }
}

// Driver code
int main()
{
    int arr[9];
    for (int i = 0; i < 9; i++)
        arr[i] = -1;
    arr[8] = fib(8, arr);
    cout << arr[8] << endl;
    for (int i = 0; i <= 8; i++)
        cout << arr[i] << " ";
    cout << endl;
}
