#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

// this code is correct but takes n^3 time so optimized code in nexttut.
int solve(string s){
    int n = s.size();
    vector<vector<bool>>dp(n, vector<bool>(n));
    for(int g =0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = true;
            }
            else if(g==1){
                dp[i][j] = (s[i] == s[j]) ? true:false;

            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
    }
// cout<<"hi";
    vector<vector<int>> strg(n, vector<int>(n));
    for(int g = 0; g<strg.size(); g++){
        for(int i = 0, j = g; j<strg.size(); i++,j++){
            if(g==0){
                strg[i][j] = 0;
            }
            else if(g==1){
                strg[i][j] = (s[i] == s[j])? 0:1;
            }
            else{
                if(dp[i][j]){
                    strg[i][j] = 0;
                }
                else{
                    int min = INT32_MAX;
                    for(int k = i; k<j; k++){
                        int left = strg[i][k];
                        int right = strg[k+1][j];
                        if(left+right+1 < min){
                            min = left + right + 1;
                        }
                    }
                    strg[i][j] = min;
                }
            }
        }
    }
    return strg[0][strg.size()-1];

}


int main(){
    string s;
    cin>>s;
    cout<<solve(s);
}