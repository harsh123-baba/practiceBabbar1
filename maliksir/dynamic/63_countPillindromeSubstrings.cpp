#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    
    int n = s.size();
    int count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                // count++;
                dp[i][j] = true;
            }
            else if(g==1){
                dp[i][j] = (s[i] == s[j] )? true:false;
            
            }
            else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }       
            }
            if(dp[i][j]){
                count++;
            }
        }

    }
    cout<<count;


}