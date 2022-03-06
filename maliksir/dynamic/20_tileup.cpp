
// In this video, we discuss the first variation of the Tiling problem where we are required to tile a long 2 * n unit path using 2 * 1 unit infinite tiles in all possible ways. In this problem, 

// 1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
// 2. You've an infinite supply of 2 * 1 tiles.

// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp (n+1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<=n; i++){  
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}