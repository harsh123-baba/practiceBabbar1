#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


class Pair{
    public:
    int index;
    int value;
    int len;
    string psf;

    Pair(int index, int value, int len, string psf){
        this->index = index;
        this->len = len;
        this->psf = psf;
        this->value =value;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vector<int> dp(n);
    int omax = 0;
    int ind = 0;
    for(int i = 0; i<n; i++){
        int maxima = 0;
        for(int j = 0; j<i; j++){
            if(v[i] > v[j]){
                if(maxima < dp[j]){
                    maxima = dp[j];
                }
            }
            
        }
        dp[i] = maxima+1;
        if(omax < dp[i]){
            omax = dp[i];
            ind = i;
        }
    } 
    cout<<omax<<endl;
    queue<Pair> q;
    q.push(Pair(ind, v[ind], omax, to_string(v[ind]) ));


    while(q.size() > 0){
        Pair rem = q.front();
        q.pop();
        if(rem.len == 1){
            cout<<rem.psf<<endl;
        }
        for(int j = rem.index - 1; j>=0; j--){
            if(dp[j] == rem.len - 1 && v[j]<=rem.value){
                q.push(Pair(j, v[j], dp[j], to_string(v[j]) + " -> " + rem.psf));
            }
        }
    }
}