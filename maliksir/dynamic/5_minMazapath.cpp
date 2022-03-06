#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int MinCoseMazePath(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));
    
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(i==dp.size()-1 && j== dp[0].size()-1){
                dp[i][j] = v[i][j];
            }
            else if(i== dp.size()-1){
                dp[i][j] = v[i][j]+dp[i][j+1];
            }
            else if(j == dp[0].size()-1){
                dp[i][j] = v[i][j]+dp[i+1][j];
            }
            else{
                dp[i][j] = v[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}


int main(){
    int n, m;
    cin>>n;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    cout<<MinCoseMazePath(v);
}