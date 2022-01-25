#include<bits/stdc++.h>

using namespace std;

int russianPeasant(int a,int b){
    if(b==0)return 0;
    if(b&1)return a+russianPeasant(a<<1,b>>1);
    return russianPeasant(a<<1,b>>1);
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a<0 && b<0)
    {
        a*=-1;
        b*=-1;
    }
    else if(b<0)
    {
        a*=-1;
        b*=-1;
    }
    cout<<russianPeasant(a,b);
}