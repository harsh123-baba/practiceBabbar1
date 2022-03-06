#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> v, vector<int> freq){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int g = 0; g<n; g++){
        for(int i = 0, j = g; j<n; j++, i++){
            if(g==0){
                dp[i][j] = freq[i];
            }
            else if(g == 1){
                int f1 = freq[i];
                int f2 = freq[j];
                dp[i][j] = min(f1 + 2*f2 , f2 + 2*f1);
            }
            else{
                int min = INT32_MAX;
                int fqofAll = 0;
                for(int x= i; x<=j; x++){
                    fqofAll += freq[x]; 
                }
                for(int k = i; k<=j ; k++){
                    int left = ((i==k )? 0: dp[i][k-1]);
                    int right = ((j==k) ? 0 : dp[k+1][j]);
                    
                    if((left + right +fqofAll)  < min){
                        min = left+right + fqofAll;
                    }
                }
                dp[i][j] = min;
            }
        }
    }
    return dp[0][n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<int> freq(n);
    for(int i = 0; i<n; i++){
        cin>>freq[i];
    }
    cout<<solve(v, freq);

}