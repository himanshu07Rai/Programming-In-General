/*
Given a string S. The task is to print all the possible rotated strings of the given string.
*/

#include<bits/stdc++.h>
using namespace std;


// void generateRotations(string str)
// {
//     int n = str.length();
//     cout<<str<<"\n";
//     for (int i = 0; i < n-1; i++)
//     {
//         rotate(str.begin(), str.begin() + 1, str.end());
//         cout<<str<<"\n";

//     }
// }

void generateRotations(string str)
{
    int n = str.length();
    char temp[2*n + 1];
    char s[n+1];
    strcpy(s,str.c_str());
    strcpy(temp, s);
    strcat(temp, s);
    for (int i = 0; i < n; i++)
    {
        for (int j=0; j != n; j++)
            printf("%c",temp[i + j]);
        printf("\n");
    }
}


int main()
{
    string str = "geeks";
    generateRotations(str);
    return 0;
}