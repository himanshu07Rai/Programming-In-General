/*
Check if a string is a rotated palindrome or not
*/

#include<bits/stdc++.h>
using namespace std;

/*
        Approach 1

bool isPalindrome(string str,int l,int r)
{
    while(l<r)
    {
        if(str[l]!=str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool isRotatedPalindrome(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        rotate(str.begin(), str.begin() + 1, str.end());

        if (isPalindrome(str, 0, n - 1)) {
            return true;
        }
    }
 
    return false;
}


int main()
{
    string str = "AABCBAA";
    int n = str.size();
    if(isPalindrome(str,0,n-1))
        cout << "The string is a rotated palindrome";
 
    else if (isRotatedPalindrome(str)) {
        cout << "The string is a rotated palindrome";
    }
    else {
        cout << "The string is not a rotated palindrome";
    } 
    return 0;
}

*/

//  Approach 2

bool isPalindrome(vector<char> &str,int l,int r)
{
    cout<<l<<" "<<r<<"\n";
    while(l<r)
    {
        if(str[l]!=str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool isRotatedPalindrome(vector<char> &str)
{
    int n = str.size();
    vector<char>temp;
    for(int i = 0;i<2*n;i++)
    {
        temp.push_back(str[i%n]);
    }
    for(int i=0;i<n;i++)
    {
        int j = i+n-1;
        if(isPalindrome(temp,i,j))
            return true;
    }
    return false;
}

int main()
{
    // vector<char>str{'C','B','A','A','B','C','D'};
    vector<char>str{'B','A','A','B','C','C'};

    if (isRotatedPalindrome(str)) {
        cout << "The string is a rotated palindrome";
    }
    else {
        cout << "The string is not a rotated palindrome";
    } 
    return 0;
}

