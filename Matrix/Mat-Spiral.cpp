#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 3

void printSpiral(int mat[N][M])
{
    int T = 0, B = N - 1, L = 0, R = M - 1;
    int dir = 0;
    while (L <= R && T <= B)
    {
        if (dir == 0)
        {
            for (int k = L; k <= R; k++)
                cout << mat[T][k] << " ";
            T++;
        }
        else if (dir == 1)
        {
            for (int k = T; k <= B; k++)
                cout << mat[k][R] << " ";
            R--;
        }
        else if (dir == 2)
        {
            for (int k = R; k >= L; k--)
                cout << mat[B][k] << " ";
            B--;
        }
        else if (dir == 3)
        {
            for (int k = B; k >= T; k--)
                cout << mat[k][L] << " ";
            L++;
        }
        dir = (dir + 1) % 4;
    }
}

int main()
{
    int mat[N][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printSpiral(mat);
    return 0;
}