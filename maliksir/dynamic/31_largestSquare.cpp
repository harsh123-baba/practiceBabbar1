#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int largest(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dp(n, vector<int>(m));
    // dp[n-1][m-1] = v[n-1][m-1];
    int max = INT32_MIN;
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(i== n-1 || j == m-1){
                dp[i][j] = v[i][j];
            }
            else if(v[i][j] == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], dp[i+1][j]))+1;
            }
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(max < dp[i][j]){
                max = dp[i][j];
            }
        }
    }
    return max;
}



int main(){
   vector<vector<int>> v = {{ 0, 1, 0 ,1, 0, 1 },
                            {1 ,0, 1 ,0 ,1, 0 },
                            {0, 1 ,1 ,1 ,1 ,0 },
                            {0, 0, 1, 1, 1, 0 },
                            {1, 1 ,1 ,1 ,1, 1}
                            };
                        
    cout<<largest(v);
}