#include <bits/stdc++.h>
using namespace std;

/* Either we can use this formula nCr = n!/r!(n-r)! or Pascal's Triangle */

int C(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
    {
        return C(n - 1, r - 1) + C(n - 1, r);
    }
}

int main()
{
    int n = 4, r = 3;
    cout << C(n, r) << endl;
}