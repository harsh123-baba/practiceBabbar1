#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int twoTransaction(vector<int> v){
    int n = v.size();
    int maxProfitIFSoldToday = 0;
    int leastSoFar = v[0];
    vector<int> dpMaxProfitIFSoldUptoToday(n, 0);
    for(int i = 1; i < n; i++){
        if(v[i] < leastSoFar){
            leastSoFar = v[i];
        }
        maxProfitIFSoldToday = v[i] - leastSoFar;
        if(maxProfitIFSoldToday > dpMaxProfitIFSoldUptoToday[i-1]){
            dpMaxProfitIFSoldUptoToday[i] = maxProfitIFSoldToday;

        }
        else{
            dpMaxProfitIFSoldUptoToday[i] = dpMaxProfitIFSoldUptoToday[i-1];
        }
    }

    int maxProfitIfBoughtToday = 0;
    int maxSoFar = v[n-1];
    vector<int> dpMaxProfitIFBoughtUptoToday(n, 0);
    for(int i = n-2; i>=0; i--){
        if(v[i] > maxSoFar){
            maxSoFar = v[i];
        }
        maxProfitIfBoughtToday =maxSoFar - v[i] ;
        if(maxProfitIfBoughtToday > dpMaxProfitIFBoughtUptoToday[i+1]){
            dpMaxProfitIFBoughtUptoToday[i] = maxProfitIfBoughtToday;
        }
        else{
            dpMaxProfitIFBoughtUptoToday[i] = dpMaxProfitIFBoughtUptoToday[i+1];
        }
    }
int op = 0;
    for(int i = 0; i<n; i++){
        if(dpMaxProfitIFBoughtUptoToday[i]+dpMaxProfitIFSoldUptoToday[i] > op){
            op = dpMaxProfitIFSoldUptoToday[i] + dpMaxProfitIFBoughtUptoToday[i];
        }
    }
    return op;

}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<twoTransaction( v);
}