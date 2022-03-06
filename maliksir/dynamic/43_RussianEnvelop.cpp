#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Envelop{
    public:
    int w;
    int h;
    Envelop(int w ,int h){
        this->w = w;
        this->h = h;
    }
};


bool compare(Envelop e1, Envelop e2){
    return e1.w < e2.w;
}

int main(){
    int n;
    cin>>n;
    vector<Envelop> v;
    for(int i = 0; i<n; i++){
        int wid, hei;
        cin>>wid>>hei;
        Envelop e = Envelop(wid , hei);
        v.push_back(e);
    }
    sort(v.begin(), v.end(), compare);

    vector<int> dp(n);
    int omax = 0;
    for(int i = 0; i<n; i++){
        int max = 0;
        for(int j = 0; j<i; j++){
            if(v[j].h < v[i].h && v[j].w < v[i].w){
                if(max < dp[j]){
                    max = dp[j];
                }
            }
        }
        dp[i] = max+1;
        if(dp[i] > omax){
            omax = dp[i];
        }

    }
    cout<<omax;
}