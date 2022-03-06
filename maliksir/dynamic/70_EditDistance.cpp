// 1. You are given two strings s1 and s2.
// 2. You have to find the minimum number of operations needed to convert s1 to s2.
//    Operations allowed are - 
//    Insert - You can insert any character in s1.
//    Remove - You can remove any character in s1.
//    Replace - You can replace any character in s1 with any other character.



#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int EditDistance(string s1, string s2){
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
    for(int i = 0; i<dp.size(); i++){
        for(int j = 0; j<dp[0].size(); j++){
            if(i==0 && j == 0){
                dp[i][j] = 0;
            }
            else if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else {
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    // replace // delete // insert respectively
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1;
                }
            }

        }   
    }
    return dp[dp.size()-1][dp[0].size()-1];

}


int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<EditDistance(s1, s2);
}


