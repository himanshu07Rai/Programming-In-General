#include <bits/stdc++.h>
using namespace std;

/*FACTORIAL OF A NUMBERS */

int fact(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        return fact(n - 1) * n;
    }
}

// Driver code

int main()

{
    int r = 5;
    cout << fact(r);
    return 0;
}
