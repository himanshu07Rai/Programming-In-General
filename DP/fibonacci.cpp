#include <bits/stdc++.h>
using namespace std;

/*

bottom up

int fibo(int n)
{
    int f[n + 1];
    int i;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

*/

/*

top down

*/

int fibo(int n, vector<int> &lookup)
{
    if (lookup[n] == -1)
    {
        if (n <= 1)
            lookup[n] = n;
        else
            lookup[n] = fibo(n - 1, lookup) + fibo(n - 2, lookup);
    }
    return lookup[n];
}

int main()
{
    vector<int> lookup(5, -1);
    cout << fibo(4, lookup);
}