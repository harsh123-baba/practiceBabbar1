#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Bridge{
    public:
    int n;
    int s;
    
    Bridge(int n, int s){
        this->n = n;
        this->s = s;
    }
};

bool compare(Bridge b1, Bridge b2){
    if(b1.n != b2.n){
        return b1.n < b2.n;
    }
    else{
        return b1.n<b2.n;
    }
}


int main(){
    int n;
    cin>>n;
    vector<Bridge> v;
    for(int i = 0; i<n; i++){
        int north, south;
        cin>>north>>south;
        Bridge b(north, south);
        // v[i].n = north;
        // v[i].s = south;
        v.push_back(b);
    }
    sort(v.begin(), v.end(), compare);

    vector<int> dp(n);
    int omax = 0;
    for(int i = 0; i<n; i++){
        int max = 0;
        for(int j = 0; j<i; j++){
            if(v[j].s <= v[i].s){
                if(dp[j] > max){
                    max = dp[j];
                }
            }
        }
        dp[i] = max+1;
        if(dp[i]>omax){
            omax = dp[i];
        }

    }
    cout<<omax;

}