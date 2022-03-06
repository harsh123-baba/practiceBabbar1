#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int lrs(string s){
    vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1));
    for(int i = dp.size()-1; i>=0; i--){
        for(int j = dp[0].size()-1; j>=0 ; j--){
            if(i == dp.size()-1 && j == dp[0].size()-1){
                dp[i][j] = 0;
            }
            else if(i==dp.size()-1){
                dp[i][j] = 0;
            }
            else if(j == dp[0].size()-1){
                dp[i][j] = 0;
            }

            else {
                if(s[i] == s[j]&& (i != j)){
                    dp[i][j] = dp[i+1][j+1]+1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                }

            }

        }
    }
    return dp[0][0];
}


int main(){
    string s;
    cin>>s;
    cout<<lrs(s);
}