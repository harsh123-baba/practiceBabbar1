#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(string s, string pattern){
    vector<vector<bool>> dp(pattern.size()+1, vector<bool>(s.size()+1));
    for(int i = dp.size()-1; i>=0; i--){
        for(int j = dp[0].size()-1; j>=0; j--){
            if(i==dp.size()-1 && j == dp[0].size()-1){
                dp[i][j] = true;
            }
            else if(i==dp.size()-1){
                dp[i][j] = false;
            }
            else if(j == dp[0].size()-1){
                if(pattern[i] == '*'){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
            else{
                if(pattern[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(pattern[i] == '*'){
                    dp[i][j] = dp[i+1][j+1] || dp[i][j+1];
                }
                else if(s[j] == pattern[i]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[0][0];
}

int main(){
    string s, pattern;
    // cin>>s>>pattern;
    s = "baaabab";
    pattern = "ba*a?";
    cout<<solve(s, pattern);
}