#include<bits/stdc++.h>
using namespace std;

void findInterleavings(string result, string X, string Y, unordered_set<string> &collection)
{
    // insert `result` into the set if the end of both strings is reached
    if (!X.length() && !Y.length())
    {
        collection.insert(result);
        return;
    }
 
    // if the string `X` is not empty, append its first character in the
    // result and recur for the remaining substring
 
    if (X.length()) {
        findInterleavings(result + X[0], X.substr(1), Y, collection);
    }
 
    // if the string `Y` is not empty, append its first character in the
    // result and recur for the remaining substring
 
    if (Y.length()) {
        findInterleavings(result + Y[0], X, Y.substr(1), collection);
    }
}

int main()
{
    string X = "ABC";
    string Y = "ACB";

    unordered_set<string> collection;
 
    findInterleavings("", X, Y, collection);
 
    for (string s: collection) {
        cout << s << endl;
    }
 
    return 0;
}