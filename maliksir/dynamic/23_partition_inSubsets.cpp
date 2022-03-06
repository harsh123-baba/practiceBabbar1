#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> dp(k+1, vector<int>(n+1));
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            if(i==j){
                dp[i][j] =1;
            }
            else if(i>j){
                dp[i][j]=0;
            }
            else{   
                dp[i][j] = i*(dp[i][j-1]) + dp[i-1][j-1];
            }
        }
    }
    cout<<dp[k][n];

}