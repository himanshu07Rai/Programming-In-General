#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    if(idx==n)
        return 0;
    int m = max(arr,idx+1,n);
    int r = max(m,arr[idx]);
    return r;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
