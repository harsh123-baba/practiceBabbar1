#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int coinChange(vector<int> v, int x){
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int amnt = 1; amnt <= x; amnt++){
        for(int coin : v){
            if(coin <= amnt){
                int ramnt = amnt-coin;
                dp[amnt] += dp[ramnt];
            }
        }
    }
    return dp[x];
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int  i =   0; i<n; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    cout<<coinChange(v, x);
}