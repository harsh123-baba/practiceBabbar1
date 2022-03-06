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

    vector<int>dp(n);
    int omax = INT32_MIN;
    for(int i = 0; i<n; i++){
        
        int max = INT32_MIN;
        for(int j = 0;j<i; j++){
            if(v[i] > v[j]){
                if(max <= dp[j]){
                    max = dp[j];
                }
            }

        }
        if(max == INT32_MIN){
            dp[i] = v[i];
        }
        else{
            dp[i] = max+v[i];
        }
        if(omax < dp[i]){
            omax = dp[i];
        }

    }
cout<<omax;



}