#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<long long> dp(n+1);
    dp[0] = 1;
    unordered_map<char, long long>map;
    for(long long i =1; i<n+1; i++){
        dp[i] = dp[i-1] *2;
        char ch = s[i-1];
        if(map.find(ch) != map.end()){
            dp[i] -= map[ch];
        }   
        map[ch] = i;
    }
    cout<<dp[n]-1;
}