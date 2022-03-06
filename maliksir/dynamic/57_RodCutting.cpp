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
    vector<int> dup(n+1);
    for(int i = 0; i<n; i++){
        dup[i+1] = v[i];
    }

    vector<int> dp(dup.size());
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<dp.size(); i++){
        dp[i] = dup[i];
        int li = 1;
        int ri = i-1;
        while(li<=ri){
            if(dp[li]+dp[ri] > dp[i]){
                dp[i] = dp[li] + dp[ri];
            }
            li++;
            ri--;
        }
    }
    cout<<dp[dp.size()-1];
}