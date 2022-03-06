#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minAsciiDel(string s1, string s2){
    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1));
    for(int i = dp.size()-1; i>=0; i--){
        for(int j = dp[0].size()-1; j>=0; j--){
            if(i==dp.size()-1 && j == dp[0].size()-1){
                dp[i][j] = 0;
            }
            else if(i==dp.size()-1){
                dp[i][j] = (int)(s2[j]) + dp[i][j+1];
            }
            else if(j==dp[0].size()-1){
                dp[i][j] = (int)(s1[i]) + dp[i+1][j];
            }
            else {
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min((int)(s1[i])+dp[i+1][j],(int)(s2[j])+dp[i][j+1]);
                }
            }

        }
    }
    return dp[0][0];
}


int main(){
    string s1;
    string s2;
    cin>>s1>>s2;

    cout<<minAsciiDel(s1, s2);
}