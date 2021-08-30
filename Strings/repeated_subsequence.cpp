#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string str, int low, int high)
{
    while(low<high)
    {
        if(str[low]!=str[high])
            return false;
    }
 
    return true;
}

bool hasRepeatedSubsequence(string str)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < str.length(); i++)
    {
        if (++freq[str[i]] >= 3) {
            return true;
        }
    }
 
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] >= 2) {
            temp += str[i];
        }
    }
 
    return !isPalindrome(temp, 0, temp.length() - 1);
}

int main()
{
    string str = "XYYX";        // `XB` and `YB` are repeated subsequences
 
    if (hasRepeatedSubsequence(str)) {
        cout << "Repeated subsequence is present";
    }
    else {
        cout << "No repeated subsequence is present";
    }
 
    return 0;
}