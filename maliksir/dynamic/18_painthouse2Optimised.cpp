#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n, c;
    cin>>n>>c;
    vector<vector<int>> v(n, vector<int>(c));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<c; j++){
            cin>>v[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(c));
    int least = INT32_MAX;
    int sleast = INT32_MAX;
    for(int j = 0; j<c; j++){
        dp[0][j] = v[0][j];
        if(v[0][j]<least){
            sleast = least;
            least = v[0][j];
        }
        else if(v[0][j] < sleast){
            sleast = v[0][j];
        }
    }

    for(int i = 1; i<n; i++){
        int nleast=INT32_MAX;
        int nsleast = INT32_MAX;
        for(int j = 0; j<c; j++){
            
            if(dp[i-1][j] == least){
                dp[i][j] =   v[i][j]+sleast;
            
            }
            else{
                dp[i][j] =   v[i][j]+least;
            }
            if(dp[i][j]<=nleast){
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if(dp[i][j] <= nsleast){
                nsleast = dp[i][j];
         
            }
            
        }
        least = nleast;
        sleast = nsleast;
    }
    
    cout<<least;
}

