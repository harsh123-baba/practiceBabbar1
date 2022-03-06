#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int len = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for(int g = 0; g<n; g++){
        for(int i = 0,j=g; j<n; j++, i++){
            if(g==0){
                dp[i][j] = true;
            }
            else if(g==1){
                dp[i][j] = (s[i] == s[j])? true:false;
            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            if(dp[i][j]){
                // i dont have to verify ki string size len m fit length s bda hai ki nhi
                // bqs jese jese expression age jayega
                // gap bdhti jayegi....
                len = g+1;
            }
        }
    }

    cout<<len;

}