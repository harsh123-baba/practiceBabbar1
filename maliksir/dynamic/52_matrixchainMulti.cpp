#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int chainMul(vector<int> v){
    vector<vector<int>> dp(v.size()-1, vector<int> (v.size()-1));
    for(int g = 0; g<dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            if(g==0){
                dp[i][j] = 0;
            }
            else if(g==1){
                dp[i][j] = v[i] * v[j] * v[j+1];                
            }
            else{
                int min = INT32_MAX;
                for(int k = i; k<j ; k++){
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = v[i] * v[k+1] * v[j+1];
                    int tc = lc + rc + mc;
                    if(min > tc){
                        min = tc;
                    }
                }
                dp[i][j] = min;
            }

        }
    }
    return dp[0][dp.size()-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    cout<<chainMul(v);

}