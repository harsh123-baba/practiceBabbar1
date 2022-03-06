#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


// int kTrasaction(vector<int> p, int k){
//     vector<vector<int>> dp(k+1, vector<int>(p.size(), 0));
//     for(int t = 1; t<=k; t++){
//         for(int d = 1; d<p.size(); d++){
//             int m = dp[t][d-1];
//             for (int pd = 0; pd < d; pd++){
//                 int ptillTminus1 = dp[t-1][pd];
//                 int ptth = p[d]-p[pd];
//                 if(ptillTminus1 + ptth > m){
//                     m  = ptillTminus1 + ptth;
//                 }   

//             }
//             dp[t][d] = m;
//         }
//     }
//     return dp[k][p.size()-1];
// }




int kTrasaction(vector<int> p, int k){
    vector<vector<int>> dp(k+1, vector<int>(p.size(), 0));

    for(int t = 1; t<=k; t++){
        for(int d = 1; d<p.size(); d++){
            int max = dp[t][d-1];
            for(int pd = 0; pd<d; pd++){
                int ptilltminus1 = dp[t-1][pd];
                int ptth = p[d]-p[pd];
                if(max < ptth+ptilltminus1){
                    max = ptilltminus1 + ptth;
                }
            }
            dp[t][d] =max;
        }
   
    }
    return dp[k][p.size()-1];
}

int kTransOptimized(vector<int> p, int k){
    vector<vector<int>> dp(k+1, vector<int> (p.size(), 0));
    for(int t = 1; t<=k; t++){
        int m = INT32_MIN;
        for(int d = 1; d<p.size(); d++){
            m = max(m, dp[t-1][d-1] - p[d-1]);
            if(m + p[d] > dp[t][d-1]){
                dp[t][d] = m+p[d];
            }
            else{
                dp[t][d] = dp[t][d-1];
            }
        }
    }
    return  dp[k][p.size()-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i = 0; i<n; i++){
        cin>>price[i];
    }
    int k;
    cin>>k;
    cout<<kTransOptimized(price, k);
}