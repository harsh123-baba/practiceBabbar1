#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    string s = "abcb";

    // cin>>s;
    int n = s.size();
    int len = 0;
    vector<vector<bool>>dp(n, vector<bool> (n, false));

    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j=g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = true;
            }else if(g==1){
                dp[i][j] = (s[i] == s[j])? true:false;
            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }
            if(dp[i][j]){
                len = g+1;
            }
        }
    }
    cout<<len;


}