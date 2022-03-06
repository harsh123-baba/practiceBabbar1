#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

// o(n^2)

int highway(vector<int> x, vector<int> rev, int t){
    vector<int> dp(x.size());
    dp[0] = rev[0];
    int ans = 0;
    
    for(int  i = 0; i<x.size(); i++){
        int m = 0;
        for(int j = 0; j<i; j++){
            int dist = x[i]-x[j];
            if(dist > t){
                m = max(m, dp[j]);
                 
            }

        }
        dp[i] = m+rev[i];
        ans = max(dp[i], ans);
    }
    return ans;
}


// o(m)
int highway2(vector<int> x, vector<int> rev, int t, int m){
    unordered_map<int, int> map;
    for(int i = 0; i<x.size(); i++){
        map[x[i]] = rev[i];

    }   
    vector<int> dp(m+1);
    dp[0] = 0;
    for(int i = 1; i<=m; i++){
        if(map[i]){
            int notInstalled = dp[i-1];
            int installed = map[i];
            if(i>t+1){
                installed = dp[i-t-1]+installed;
            }
            dp[i] = max(installed, notInstalled);
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    return dp[m];
}




int main(){
    int n, m;
    cin>>m;
    cin>>n;
    vector<int> x(n);
    vector<int> rev(n);
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
    for(int i = 0; i<n; i++){
        cin>>rev[i];
    }
    int t;
    cin>>t;
    cout<<highway2(x, rev, t, m);
}