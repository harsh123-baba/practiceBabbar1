#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int lcs(string s1, string s2){
    int len  = 0;
    vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1));
    for(int i = 0; i< dp.size(); i++){
        for(int j = 0; j<dp[0].size(); j++){
            if(i== 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 0;
            }   
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 0;
            }
            if(dp[i][j] > len){
                len = dp[i][j];
            }
        }

    }
    return len;
}


int main(){
    string s1;
    string s2;
    cin>>s1>>s2; 
    cout<<lcs(s1, s2);
}   