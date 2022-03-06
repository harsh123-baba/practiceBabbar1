#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(vector<int> val, vector<int> weight, int x){
    vector<vector<int>> dp(weight.size()+1, vector<int> (x+1, 0));
    int n = dp.size();
    int m = dp[0].size();
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){       
            if(weight[i-1] <= j){
                int remainingCap = j-weight[i-1];
                if(dp[i-1][remainingCap]+val[i-1] > dp[i-1][j]){
                    dp[i][j] = dp[i-1][remainingCap]+val[i-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }  
        
        }   
    }
    return dp[n-1][m-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> val(n);
    vector<int> weight(n);
    int x;
    for(int i = 0; i<n; i++){
        cin>>val[i];   
    }
    for(int i = 0; i<n; i++){
        cin>>weight[i];
    }
    cin>>x;
    cout<<solve(val, weight, x);
    
}