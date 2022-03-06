#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


int climbWithJump(vector<int> v){
    vector<int> dp(v.size()+1);
    // 6 s 6 pr jane ka ek hi rasta hai 
    // 0 s 6 pr jane ka bht raste hai 
    // so hm choti problem s bde problem ki side jate
    // direction <------
    int n = v.size();
    dp[n] = 1;
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<=v[i] && i+j<=v.size(); j++){
            dp[i]+=dp[i+j];
        }
    }
    return dp[0];

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<climbWithJump(v);
}