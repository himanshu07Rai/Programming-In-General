/*
O(n^2) time and O(1) space algorithm

Rotate by +90:
    Transpose
    Reverse each row

Rotate by -90:
    Method 1 :
        Transpose
        Reverse each column

    Method 2 :
        Reverse each row
        Transpose

Rotate by +180:
    Method 1: Rotate by +90 twice
    Method 2: Reverse each row and then reverse each column (Transpose)

Rotate by -180:
    Method 1: Rotate by -90 twice
    Method 2: Reverse each column and then reverse each row
    Method 3: Rotate by +180 as they are same
*/

#include <bits/stdc++.h>
#define N 3
using namespace std;

void reverse_rows(int arr[N][N])
{
    int k;
    for (int i = 0; i < N; i++)
    {
        k = N - 1;
        for (int j = 0; j < k; j++)
        {
            swap(arr[i][j], arr[i][k]);
            k--;
        }
    }
}

void transpose(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            swap(arr[i][j], arr[j][i]);
}

void print_matrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d\t", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "The matrix before rotation\n";
    print_matrix(mat);
    cout << "The matrix after rotation - Clockwise\n";
    transpose(mat);
    reverse_rows(mat);
    print_matrix(mat);
    // cout << "\nThe matrix after rotation - Anti-Clockwise\n";
    // reverse_rows(mat);
    // transpose(mat);
    // print_matrix(mat);
    return 0;
}