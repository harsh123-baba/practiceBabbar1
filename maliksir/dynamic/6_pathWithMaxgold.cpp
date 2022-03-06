#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int MaxGoldMine(vector<vector<int>>v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int j = m-1; j>=0; j--){
        for(int i = n-1; i>=0; i--){
            if(j==v[0].size()-1){
                dp[i][j] = v[i][j];
            }
            else if(i==0){
                dp[i][j] = max(dp[i][j+1], dp[i+1][j+1])+v[i][j];
            }
            else if(i==n-1){
                dp[i][j] = max(dp[i-1][j+1], dp[i][j+1])+v[i][j];
            }
            else{
                dp[i][j] = max(dp[i+1][j+1], max(dp[i-1][j+1], dp[i][j+1]))+v[i][j];
            }
        }
    }
    int maxima = dp[0][0];
    for(int  i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            maxima = max(maxima, dp[i][j]);
        }

    }
    return maxima;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    cout<<MaxGoldMine(v);
}