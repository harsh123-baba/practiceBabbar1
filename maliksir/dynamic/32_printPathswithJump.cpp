#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Pair{
    public:
    int idx;
    int allowedJumps;
    int takenJumps;
    string psf;
    Pair(int idx,int allowedJumps, int takenJumps, string psf){
        this->idx = idx;
        this->allowedJumps = allowedJumps;
        this->takenJumps = takenJumps;
        this->psf = psf;
    }  
};

int main(){
    int n=10;
    // cin>>n;
    // vector<int> v(n);
    // for(int i = 0; i<n; i++){
    //     cin>>v[i];
    // }
    vector<int> v = {3,3,0,2,1,2,4,2,0,0};
    vector<int> dp(n, INT32_MAX);
    dp[n-1] = 0;
    for(int i = n-2; i>=0; i--){
        int min = INT32_MAX;
        for(int j = 1; j<=v[i]&&i+j < n; j++){
            if(dp[i+j] != INT32_MAX && dp[i+j] < min){
                min = dp[i+j];
            }
        }
        if(min!= INT32_MAX){

        dp[i] = min+1;
        }
    }
    cout<<dp[0]<<endl;

    queue<Pair> q;
    q.push(Pair(0, v[0], dp[0], "0"));
    while(q.size() > 0){
        Pair rem = q.front();
        q.pop();
        if(rem.takenJumps == 0){
            cout<<rem.psf<<endl;
        }
        for(int i = 1; i<=rem.allowedJumps && (i+rem.idx) < n; i++){
            int ci = i+rem.idx;
            if(dp[ci] != INT32_MAX && dp[ci] == rem.takenJumps-1){
                q.push(Pair(ci, v[ci], dp[ci], rem.psf + " -> "+to_string(ci)));
            }
        }

    }


}