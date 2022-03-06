#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++,i++){
            if(g==0 || g== 1){
                dp[i][j] = 0;

            }
            else if(g==2){
                // i or j k beech gap 2 hi toh hai isliye i+1 i+2;
                dp[i][j] = v[i] * v[i+1] * v[i+2];
            }
            else{
                int min = INT32_MAX;
                for(int k  = i+1; k<=j; k++){
                    //  iTringle = imidieate tringle 
                    // pleft = part on left
                    int iTringle = v[i] * v[k] * v[j];
                    int pleft = dp[i][k];
                    int pright = dp[k][j]; 
                    int total = pleft + pright + iTringle;
                    if(total < min){
                        min = total;
                    }
                }
                dp[i][j] = min;
            }
        }
    }
    cout<< dp[0][dp.size()-1];
}