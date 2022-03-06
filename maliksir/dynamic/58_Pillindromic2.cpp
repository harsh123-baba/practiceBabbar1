#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(string s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for(int g = 0; g<n; g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = true;
            }
            else if(g == 1){
                dp[i][j] = (s[i] == s[j])?true:false;
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

    vector<int>strg(n);
    strg[0] = 0;
    for(int j = 1; j<n; j++){
        int min = INT32_MAX;
        for(int i = j; i>=1; i--){
            if(dp[i][j] == true){
                if(strg[i-1] < min){
                    min = strg[i-1];

                }
            }
        }
        strg[j] = min+1;
    }
    return strg[n-1];
}



int main(){
    string s;
    cin>>s;
    cout<<solve(s);

}