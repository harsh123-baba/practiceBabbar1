#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = dp.size() - 2; i>=0; i--){
        for(int j = dp[0].size()-2; j>=0; j--){
            char c1 = s1[i];
            char c2 = s2[j];

            if(c1==c2){
                dp[i][j] = 1 + dp[i+1][j+1]; 
            }
            else{
                 dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0];
}


