#include<iostream>
#include<bits/stdc++.h>
using namespace std;





int main(){
    int n;
    cin>>n;
    //you are given pair of chords how much non intersecting chords can be form using this

    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i<=n; i++){
        int l = i-1;
        int r = 0;
        while(l>=0){
            dp[i] += dp[l]*dp[r];
            l--;
            r++;
        }
    }
    cout<<dp[n];


}