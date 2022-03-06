/*
    during this series i learned catalen numbers there i seen so far that 
    many problems are solved using catalen number 

    1. Catalen  number
    2. Number of bsts
    3. valleys and mountains
    4. Non intersecting Chords in circle
    5. Number of tringulation in polygon   
    6. 


*/

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        int l = i-1;
        int r = 0;
        while(l>=0){
            dp[i] += dp[l]*dp[r];
            l--;
            r++;
        }
    }
    cout<<dp[n];
}
