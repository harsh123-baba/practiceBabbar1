#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCost(string s1, string s2, int c1, int c2){
    vector<vector<int>>dp(s1.size()+1 ,vector<int>(s2.size()+1));
    for(int i =dp.size()-1; i>=0; i--){
        for(int j = dp[0].size()-1; j>=0; j--){
            if(i==dp.size()-1 && j==dp[0].size()-1){
                dp[i][j] = 0;
            }
            else if(i==dp.size()-1){
                dp[i][j] = 0;
            }
            else if(j==dp[0].size()-1){
                dp[i][j] = 0;
            }
            else {
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }
    int cost = (c1*(s1.size()-dp[0][0]) + c2*(s2.size()-dp[0][0]));
    return cost;
}


int main(){
    string s1;
    string s2;
    int c1, c2;
    cin>>s1>>s2;
    cin>>c1>>c2;
    cout<<minCost(s1, s2, c1, c2);

}