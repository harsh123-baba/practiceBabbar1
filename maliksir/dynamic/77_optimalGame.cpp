#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int optimalGame(vector<int> v){
    vector<vector<int>> dp(v.size(), vector<int>(v.size()));
    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = v[i];
            }
            else if(g == 1){
                dp[i][j] = max(v[i], v[j]);
            }
            else{
                int val1 = v[i] + min(dp[i+2][j], dp[i+1][j-1]);
                // i -> i+1 , j
                // if i + 1 liya toh i+2, j ya i+1, j-1 bachega
                //kyoki i +1 wala step opponent ka tha toh jo bh hoga wo sb opponent k naam pr hoga
                // j -> j-1, i;
                int val2 = v[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[0][dp.size()-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<optimalGame(v);
}