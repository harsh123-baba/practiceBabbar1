#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(int n){
    vector<int> dp0(n+1);
    vector<int> dp1(n+1);
    dp0[1] = 1;
    dp1[1] = 1;
    for(int i=2; i<=n; i++){
        dp0[i] = dp1[i-1];
        dp1[i] = dp1[i-1]+dp0[i-1];

    }
    return dp0[n]+dp1[n];
}


//optimizeed

int solveopt(int n){
    int ozero = 1;
    int oone = 1;
    for(int i = 2; i<=n; i++){
        int nzero = oone;
        int none = oone+ozero;
        ozero = nzero;
        oone = none;
    }
    return ozero+oone;
}




int main(){
    int n;
    cin>>n;
    cout<<solveopt( n);
}