#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int minMoves(vector<int> v){
    int n =  v.size();
    vector<int>dp(n+1, INT32_MAX);
    dp[n] = 0;
    for(int i = n-1; i>=0; i--){
        int minima = INT32_MAX;
        for(int j=1; j<=v[i] && i+j <= dp.size(); j++){
            if(v[i]>0){
                minima = min(minima, dp[i+j]); 
            }
        }
        if(minima != INT32_MAX){
        dp[i] = minima+1;

        }
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    // vector<int> v = { 3 ,2 ,4 ,2 ,0 ,2 ,3 ,1, 2, 2};
    
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<minMoves(v);
}