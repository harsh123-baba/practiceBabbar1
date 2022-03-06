#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(vector<int> v, int x){
    int n = v.size();
    int m = x;
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    for(int i = 0; i<=n; i++ ){   
        for(int j = 0; j<=m;j++){
            if(i==0 && j == 0){
                dp[i][j] = true;
            }
            else if( i== 0 ){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                else{
                    int val = v[i-1];
                    if(j >= val){
                        if(dp[i-1][j-val]== true){
                            dp[i][j] = true;
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
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    cout<<solve(v, x);

}