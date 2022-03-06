#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int TargetSum(vector<int> v, int x){
    vector<vector<bool>> dp(v.size()+1, vector<bool>(x+1, false));
    int n = dp.size();
    int m = dp[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i==0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else {
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                // reason why i-1 beacuse the i in v i-1 in dp; kyoki hm 0 subset bh use lege yha
                else {    
                    int val = v[i-1];
                    if(j >= val){
                        if(dp[i-1][j-val]==true){
                            dp[i][j]= true;
                        }
                    }   
                }    
            }
        }
    }
    return dp[v.size()][x];


}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    cout<<TargetSum(v, x);

}