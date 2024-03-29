#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        int inside = i-1;
        int outside = 0;

        while(inside >= 0){
            dp[i] += dp[outside]*dp[inside];
            
            inside--;
            outside++;
        }
    }
    cout<<dp[n];
}