#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Pair{
    public:
    int r;
    int c;
    string psf;
    Pair(int r, int c, string psf){
        this->r = r;
        this->c = c;
        this->psf = psf;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for(int j = m-1; j>=0; j--){
        for(int i = n-1; i>=0; i--){
            if(j == dp[0].size()-1){
                dp[i][j] = v[i][j];
            }
            else if(i == 0){
                dp[i][j] = v[i][j] + max(dp[i+1][j+1], dp[i][j+1]);
            }
            else if(i == dp.size()-1){
                dp[i][j] = v[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
            }
            else{
                dp[i][j] = v[i][j] + max(dp[i+1][j+1], max(dp[i-1][j+1], dp[i][j+1]));
            }
        }
    }


    int maxima = INT32_MIN;
    for(int i = 0; i<dp[0].size(); i++){
        if(maxima < dp[i][0]){
            maxima = dp[i][0];
        }
    }
    cout<<maxima<<endl;


    queue<Pair> q;
    
    for(int i = 0; i<dp[0].size(); i++){
        if(maxima == dp[i][0]){
            q.push(Pair(i, 0, to_string(i)+""));
        }
    }
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        // cout<<"callled";
        if(rem.c == dp[0].size()-1){
            cout<<rem.psf;
        }
        else if(rem.r == 0){
            // cout<<rem.psf<<endl;
            int g = max(dp[rem.r+1][rem.c+1], dp[rem.r][rem.c+1]);
            if(g == dp[rem.r+1][rem.c+1]){
                q.push(Pair(rem.r+1, rem.c+1, rem.psf+" d3"));
            }
            if(g == dp[rem.r][rem.c+1]){    
                q.push(Pair(rem.r, rem.c+1,  rem.psf+" d2"));
            }
        // cout<<"calllede";

        }
        else if(rem.r == dp.size()-1){
            int g = max(dp[rem.r-1][rem.c+1], dp[rem.r][rem.c+1]);
            if(g == dp[rem.r-1][rem.c+1]){
                q.push(Pair(rem.r-1, rem.c+1, rem.psf+"d1"));
            }
            if(g == dp[rem.r][rem.c+1]){
                q.push(Pair(rem.r, rem.c+1,  rem.psf+"d2"));
            }
        // cout<<"callledq";

        }
        else{
            int g = max(dp[rem.r+1][rem.c+1], max(dp[rem.r-1][rem.c+1] ,dp[rem.r][rem.c+1]));
            
            if(g == dp[rem.r+1][rem.c+1]){
                q.push(Pair(rem.r+1, rem.c+1, rem.psf+"d3"));
        // cout<<"callledx";
            
            }
            if(g == dp[rem.r][rem.c+1]){
                q.push(Pair(rem.r, rem.c+1,  rem.psf+"d2"));
            
        // cout<<"callledx";
            
            }
            if(g == dp[rem.r-1][rem.c+1]){
                q.push(Pair(rem.r-1, rem.c+1, rem.psf+"d1"));
        // cout<<"callledx";
            }
            
        }
        
    }

}