#include <bits/stdc++.h>
using namespace std;

/*SUM OF n NATURAL NUMBERS */

int sum(int n)
{
    if (n == 0)
        return 0;
    else
    {
        return sum(n - 1) + n;
    }
}

// Driver code

int main()

{
    int r = 6;
    cout << sum(r);
    return 0;
}
