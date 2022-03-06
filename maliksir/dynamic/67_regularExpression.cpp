#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool regularExpression(string s, string p){
    int n = p.size();
    int m = s.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 0 ; i<dp.size(); i++){
        for(int j = 0; j<dp[0].size(); j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                if(p[i-1] == '*'){
                    dp[i][j] = dp[i-2][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
            else{   
                char sch = s[j-1];
                char pch = p[i-1];
                if(sch == pch){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pch == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pch == '*'){
                    dp[i][j] = dp[i-2][j];
                    char PsecondLastChar = p[i-2];
                    if(PsecondLastChar == sch || PsecondLastChar == '.'){
                        dp[i][j] = dp[i][j-1] || dp[i][j];
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
    }
    return  dp[dp.size()-1][dp[0].size()-1];
}

int main(){
    string s;
    string p;
    cin>>s>>p;
    cout<<regularExpression(s, p);

}