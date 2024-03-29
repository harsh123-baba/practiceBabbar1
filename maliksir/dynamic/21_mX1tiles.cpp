// In this video, we discuss the second variation of the Tiling problem where we are required to find and print all the configurations to tile a path of m*n units using tiles of m*1 units such that the path is completely paved. In this problem, 

// 1. You are given a number n and a number m separated by line-break representing the length and breadth of a n * m floor.
// 2. You've an infinite supply of m * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> dp(n+1);
    for(int i = 1; i<=n; i++){
        if(i<m){
            dp[i] = 1;
        } 
        else if(i==m){
            dp[i]=2;
        }
        else{
            dp[i] = dp[i-1]+dp[i-m];
        }
    }
    cout<<dp[n];
}
