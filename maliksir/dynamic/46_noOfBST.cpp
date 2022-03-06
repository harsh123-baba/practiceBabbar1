#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] =1;
    for(int i = 2; i<=n; i++){
        int l=0;
        int r = i-1;
        //same as catalan number actually nothing is special in this case
        while ( l <= i-1 ){
            dp[i] += dp[l]*dp[r];
            l++;
            r--;
        }

        // for(int j = 0; j<i; j++){
        //     dp[i] += dp[j] * dp[i-j-1];
        // }
    }
    cout<<dp[n];
}