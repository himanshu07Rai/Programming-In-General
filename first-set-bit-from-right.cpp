#include <bits/stdc++.h>

int getFirstSetBitPos(int no)
{
    int bit = 1;
    int pos = 1;
    if (no == 0)
    {
        return 0;
    }

    {
        while ((no & bit) != bit)
        {
            bit = bit << 1;
            pos++;
        }
    }
    return pos;
}
int main()
{
    int a = getFirstSetBitPos(4567);
    printf("First set bit is at position = %d\n", a);
    return 0;
}