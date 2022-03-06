#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f){
    vector<vector<int>>dp(e+1, vector<int>(f+1));
    for(int i = 1; i<=e; i++){
        for(int j = 1; j<=f; j++){   
            if(i == 1){
                dp[i][j] = j;
            }
            else if(j == 1){
                dp[i][j] = 1;
            }
            else{
                // mj meri row ka j
                // pj prev row ka j
                int minf = INT32_MAX;
                for(int mj = j-1, pj = 0; mj >= 0; mj--, pj++){
                    int v1 = dp[i][mj]; // egg survives
                    int v2 = dp[i-1][pj]; // egg drops
                    int val = max(v1, v2); 
                    minf =  min(minf, val);
                }
                dp[i][j] = minf+1;
            }
        }

    }
    return dp[e][f];
}

int main(){
    int e, f;
    cin>>e>>f;
    cout<<eggDrop(e, f);
}
