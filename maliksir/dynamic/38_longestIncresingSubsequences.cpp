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

    vector<int> dp(n);
    // dp[0] = 1;
    int omax = 0;
    for(int i = 0; i<n; i++){
        int max = 0;
        for(int j = 0; j<i; j++){
            if(v[j] < v[i]){
                if(max < dp[j]){
                    max = dp[j];
                }
            }
        }
        dp[i]= max+1;
        if(dp[i]  > omax){
            omax = dp[i];
        }        
        

    }
    cout<<omax;


}