#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> h(n, vector<int>(3));
    for(int i =0; i<n; i++){
        for(int j=0;j<3; j++){
            cin>>h[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (3));
    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[0][2] = h[0][2];

    for(int i = 1; i<h.size(); i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+h[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+h[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0])+h[i][2];
    }
    cout<< min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

}
