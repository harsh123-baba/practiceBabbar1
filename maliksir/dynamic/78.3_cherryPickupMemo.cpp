#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int solve(int r1, int c1, int r2, int c2, vector<vector<int>> v){
    
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }
    // vector<vector<vector<vector<int>>>> dp(n, vector<int>(n, vector<int>(n, vector<int>(n))));
    int dp[n][n][n][n];
    cout<<solve(0, 0, 0, 0, v);
}