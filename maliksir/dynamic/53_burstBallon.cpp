#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int maxCoins(vector<int>& nums) {  
    vector<vector<int>> dp(nums.size(), vector<int> (nums.size()));
    for(int g = 0; g < dp.size(); g++){
        for(int i = 0, j = g; j<dp.size(); j++, i++){
            int max = INT32_MIN;
            for(int k = i; k<=j; k++){
                int left = k==i? 0: dp[i][k-1];
                int right = k==j? 0:dp[k+1][j];
                int val = (i==0? 1:nums[i-1])* nums[k] * (j==dp.size()-1 ? 1:nums[j+1]);
                int total = left+right+val;
                if(total > max){
                    max = total;
                }
                
            }
            dp[i][j] = max;
            
        }
    }
    return dp[0][dp.size()-1];
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];

    }
    cout<<maxCoins(v);
}