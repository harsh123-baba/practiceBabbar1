#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    int omin = INT32_MAX;
    for(int i = 2; i<=n; i++){
        int min = INT32_MAX;
        for(int j = 1; j*j<=i; j++){
            int rem = i-(j*j);
            if(min > dp[rem]){
                min = dp[rem];
            }
        }
        dp[i] = min+1;
        
    }
    cout<<dp[n];

}