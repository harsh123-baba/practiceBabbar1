#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n));

    for(int g = 0; g<n; g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g == 0){
                dp[i][j] = 1;
            }
            else if(g==1){
                dp[i][j] = (s[i] == s[j])?3:2;
            }
            else{
                dp[i][j] = (s[i]==s[j]) ? (dp[i][j-1] + dp[i+1][j] + 1) : (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]);

            }
        }
    }
    cout<<dp[0][n-1];



}