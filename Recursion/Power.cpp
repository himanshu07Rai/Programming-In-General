#include <bits/stdc++.h>
using namespace std;

/*POWER USING RECURSION ( m^n ) */

// int POW(int m, int n)
// {
//     if (n == 0)
//         return 1;
//     else
//     {
//         return POW(m, n - 1) * m;
//     }
// }

/* POWER USING RECURSION ( FASTER ) */

int POW(int m, int n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n % 2 == 0)
            return POW(m * m, n / 2);
        else
            return m * POW(m * m, (n - 1) / 2);
    }
}

// Driver code

int main()

{
    int m = 3, n = 9;
    cout << POW(m, n);
    return 0;
}
