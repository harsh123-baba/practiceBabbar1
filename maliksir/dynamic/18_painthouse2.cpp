#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n, c;
    cin>>n>>c;
    vector<vector<int>> v(n, vector<int>(c));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<c; j++){
            cin>>v[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(c));
    for(int j = 0; j<c; j++){
        dp[0][j] = v[0][j];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<c; j++){
            int minima = INT32_MAX;
            for(int k = 0; k<c; k++){
                if(k!=j){
                    if(dp[i-1][k] < minima){
                        minima = dp[i-1][k];
                    }
                }
            }
            dp[i][j] = minima + v[i][j];
        }
    }
    int minima = INT32_MAX;
    for(int k = 0; k<c; k++){
        if(minima > dp[n-1][k]){
            minima = dp[n-1][k];
        }
    }
    cout<<minima;
}

