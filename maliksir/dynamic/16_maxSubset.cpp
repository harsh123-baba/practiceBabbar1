#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(vector<int> v){
    int inc = v[0];
    int exc = 0;
    for(int i =1; i<v.size(); i++){
        int ninc = exc + v[i];
        int nexc = max(inc , exc);
        inc = ninc;
        exc = nexc;
    }
    return max(inc, exc);
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(v);
}