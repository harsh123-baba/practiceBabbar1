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
    int n, tar;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    // int tar;
    cin>>tar;

    vector<vector<bool>> dp(n+1, vector<bool>(tar+1, false));
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=tar; j++){
            // /first col
            if(j==0 && i==0){
                dp[i][j] = true;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else if(i==0){
                dp[i][j] = false;
            }
            else{
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                else if(j >= v[i-1]){
                    if(dp[i-1][j-v[i-1]] == true){
                        dp[i][j] =true;
                    }
                }
            }
        }
    }
    cout<<dp[n][tar]<<endl;
    queue<Pair> q;
    q.push(Pair(n, tar, ""));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();

        if(rem.r == 0 || rem.c == 0){
            cout<<rem.psf<<endl;
            continue;
        }
        if(rem.c >= v[rem.r-1]){
            bool inc = dp[rem.r-1][rem.c-v[rem.r-1]];
            if(inc){
                q.push(Pair(rem.r-1, rem.c-v[rem.r-1], to_string(rem.r-1)+ " " + rem.psf));
            }
        }

        bool exc = dp[rem.r-1][rem.c];
        if(exc){
            q.push(Pair(rem.r-1, rem.c, rem.psf));
        }


    }


}
