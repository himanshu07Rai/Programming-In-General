#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 3, M = 4;
    int mat[N][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i, j, k;
    for (k = 0; k < N; k++)
    {
        i = k;
        j = 0;
        while (i >= 0)
        {
            cout << mat[i][j] << " ";
            i = i - 1;
            j = j + 1;
        }
    }

    for (k = 1; k < M; k++)
    {
        i = N - 1;
        j = k;
        while (j < M)
        {
            cout << mat[i][j] << " ";
            i = i - 1;
            j = j + 1;
        }
    }
    return 0;
}