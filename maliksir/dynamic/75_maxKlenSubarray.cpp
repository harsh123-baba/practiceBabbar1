#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> v, int k){
    vector<int> maxSum(v.size());
    int cSum = v[0];
    maxSum[0] = v[0];
    for(int i = 1; i<v.size(); i++){
        if(cSum > 0){
            cSum += v[i];
        }
        else{
            cSum = v[i];
        }
        maxSum[i] = cSum;
    }
    int exactK = 0;
    for(int i = 0; i<k; i++){
        exactK += v[i];
    }
    int ans = INT32_MIN;
    if(exactK > ans){
        ans = exactK;
    }
    for(int i = k; i<v.size(); i++){
        exactK += v[i] - v[i-k];
        if(exactK > ans){
            ans = exactK;
        }
        int morethanK = exactK + maxSum[i-k];
        if(morethanK > ans){
            ans = morethanK;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    cout<<maxSubArray(v, k);
}