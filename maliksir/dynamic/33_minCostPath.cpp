#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Pair{
    public:
    int r;
    int c;
    string psf;

    Pair(int r, int c, string psf){
        this->r  = r;
        this->c = c;
        this->psf = psf;
    }

};


int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));

    for(int  i= 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m));
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(i==dp.size()-1 && j == dp[0].size()-1){
                dp[i][j] = v[i][j];
            }   
            else if(i == dp.size()-1){
                dp[i][j] = v[i][j] + dp[i][j+1];
            }
            else if(j == dp[0].size()-1){
                dp[i][j] = v[i][j] + dp[i+1][j];
            }
            else{
                dp[i][j] = v[i][j] + min(dp[i+1][j] , dp[i][j+1]);
            }
        }
    }

cout<<dp[0][0]<<endl;
    queue<Pair> q;
    q.push(Pair(0, 0, ""));
    while(q.size() > 0){
        // cout<<"calling\n";
        Pair rem = q.front();
        q.pop();
        if(rem.c == dp[0].size()-1 && rem.r == dp.size()-1){
            cout<<rem.psf<<endl;
        }
        else if(rem.r == dp.size()-1){
            q.push(Pair(rem.r, rem.c+1, rem.psf+"h"));
        }
        else if(rem.c == dp[0].size()-1){
            q.push(Pair(rem.r+1, rem.c, rem.psf+"v"));
        }
        else{
            if(dp[rem.r+1][rem.c] > dp[rem.r][rem.c+1]){
                q.push(Pair(rem.r, rem.c+1, rem.psf+"h"));
            }
            else if(dp[rem.r][rem.c+1] > dp[rem.r+1][rem.c]){
                q.push(Pair(rem.r+1, rem.c, rem.psf+"v"));
            }
            else{
                q.push(Pair(rem.r+1, rem.c, rem.psf+"v"));
                q.push(Pair(rem.r, rem.c+1, rem.psf+"h"));
            }
        }
    }
            
        
    
}