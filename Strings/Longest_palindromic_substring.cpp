/*
Given a string, find the maximum length of continuous susbstring of it that is also a palindrome
*/

// Approach 1 : Brute Force : To do this first, run three nested loops, the outer two loops pick all substrings one by one by fixing the corner characters, the inner loop checks whether the picked substring is palindrome or not.
// TC : O(n^3)

// Approach 2 : DP n^2, n^2

#include <bits/stdc++.h>

using namespace std;
/*
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

int longestPalSubstr(string str)
{
    int n = str.size();

    vector<vector<bool>> table(n,vector<bool>(n));

    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
    return maxLength;
}

int main()
{
    string str = "aaaabbaa";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}

*/

// Approach 3 n^2, 1


// Expand in both directions of `low` and `high` to find
// maximum length palindrome


string expand(string str, int low, int high)
{
    int len = str.length();
 
    // run till `str[low.high]` is a palindrome
    while (low >= 0 && high < len && (str[low] == str[high])) {
        low--, high++;        // Expand in both directions
    }
 
    // return palindromic substring
    return str.substr(low + 1, high - low - 1);
}
 
// Function to find the longest palindromic substring in `O(n²)` time
// and `O(1)` space
int findLongestPalindromicSubstring(string str, int len)
{
    // `max_str` stores the maximum length palindromic substring
    // found so far
 
    string max_str = "", curr_str;
 
    // `max_length` stores the maximum length of palindromic
    // substring found so far
 
    int max_length = 0, curr_length;
 
    // consider every character of the given string as a midpoint and expand
    // in both directions to find maximum length palindrome
 
    for (int i = 0; i < len; i++)
    {
        // find the longest odd length palindrome with `str[i]` as a midpoint
 
        curr_str = expand(str, i, i);
        curr_length = curr_str.length();
 
        // update maximum length palindromic substring if odd length
        // palindrome has a greater length
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
 
        // Find the longest even length palindrome with `str[i]` and `str[i+1]`
        // as midpoints. Note that an even length palindrome has two
        // midpoints.
 
        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();
 
        // update maximum length palindromic substring if even length
        // palindrome has a greater length
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }

    cout << "The longest palindromic substring of " << str << " is "
         << max_str<<" ";
 
    return max_length;
}

 
int main()
{
    string str = "ABDCBCDBDCBBC";
    auto res = findLongestPalindromicSubstring(str, str.length() - 1);
    cout<<"of Length : "<<res;
 
    return 0;
}

