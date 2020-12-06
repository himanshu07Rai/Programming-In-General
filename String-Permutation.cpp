#include <bits/stdc++.h>
using namespace std;

// #1
// void permute(string s, int k)
// {
//     static int ds[3] = {0};
//     static char res[10];
//     int i;
//     if (s[k] == '\0')
//     {
//         cout << res << endl;
//     }
//     else
//     {
//         for (i = 0; s[i] != '\0'; i++)
//         {
//             if (ds[i] == 0)
//             {
//                 res[k] = s[i];
//                 ds[i] = 1;
//                 permute(s, k + 1);
//                 ds[i] = 0;
//             }
//         }
//     }
// }

// #2

void permute(string s, int l, int h)
{
    if (l == h)
        cout << s << endl;
    else
    {
        int i;
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            permute(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}