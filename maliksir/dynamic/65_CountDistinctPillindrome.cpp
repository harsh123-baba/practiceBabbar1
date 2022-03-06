#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(string s){
    int n = s.size();
    vector<int> next(n);
    vector<int> prev(n);
    unordered_map<char, int> map;
    for(int i = 0; i<n; i++){
        if(map.find(s[i]) == map.end()){
            prev[i] = -1;
        }
        else{
            prev[i] = map[s[i]];
        }
        map[s[i]] = i;
    }
    map.clear();

    for(int i = n-1; i>=0; i--){
        if(map.find(s[i]) == map.end()){
            next[i] = -1;
        }
        else{
            next[i] = map[s[i]];
        }
        map[s[i]] = i;
    }

    //gap stretagy

    vector<vector<int>> dp(n, vector<int>(n));
    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = 1;
            }
            else if(g==1){
                dp[i][j] = 2;
            }
            else{
                if(s[i]!= s[j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                } 
                else{
                    int nextIdx = next[i]; 
                    int prevIdx = prev[j];
                    if(nextIdx > prevIdx){
                        dp[i][j] = 2* dp[i+1][j-1] + 2;
                    }
                    else if(nextIdx == prevIdx){
                        dp[i][j] = 2* dp[i+1][j-1] +1;
                    }
                    else{
                        dp[i][j] = 2 * dp[i+1][j-1] - dp[nextIdx+1][prevIdx-1];  
                    }
                }
            }
        }
    }
    return dp[0][n-1];

}






int main(){
    string s;
    cin>>s;
    cout<<solve(s);
}