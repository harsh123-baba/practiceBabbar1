#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Pair{
    public:
    int r;
    int c;
    string psf;
    Pair(int r, int c, string psf ){
        this->r = r;
        this->c = c;
        this->psf = psf;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<int> w(n);
    for(int i = 0; i<n; i++){
        cin>>w[i];
    }
    int cap;
    cin>>cap;
    
    vector<vector<int>> dp(n+1, vector<int>(cap+1 , 0));

    for(int i = 0; i<dp.size(); i++){
        for(int j = 0; j<dp[0].size(); j++){
            if(i==0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                if(j >= w[i-1]){
                    dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][cap]<<endl;

    queue<Pair> q;
    q.push(Pair(v.size(), cap, ""));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        if(rem.r ==  0 || rem.c == 0){
            cout<<rem.psf<<endl;
        }    
        else{
            int exc = dp[rem.r-1][rem.c];
            if(rem.c >= w[rem.r-1]){
                int inc = v[rem.r-1] + dp[rem.r-1][rem.c-w[rem.r-1]];
                if(dp[rem.r][rem.c] == inc){
                    q.push(Pair(rem.r-1, rem.c-w[rem.r-1], to_string(rem.r-1) + " "+rem.psf));
                }
            }
            if(dp[rem.r][rem.c]==exc){
                q.push(Pair(rem.r-1, rem.c,rem.psf));
            }
        }
    }

}