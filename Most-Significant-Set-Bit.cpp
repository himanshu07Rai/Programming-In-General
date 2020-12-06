#include <bits/stdc++.h>
using namespace std;

void setBitNumber(int n)
{
    if (n == 0)
    {
        cout << "No set Bit\n";
        return;
    }
    int k = (log2(n));

    cout << k << "\n"
         << "2^" << k << " = " << (1 << k) << "\n";
}

int main()
{
    int n = 0;
    setBitNumber(n);
    return 0;
}