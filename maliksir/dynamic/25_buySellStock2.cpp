#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(vector<int> v){
    int n= v.size();
    int buy = 0;
    int sell = 0;
    int profit = 0;
    
    for(int i = 1; i<n; i++){
        if(v[i] >= v[i-1] ){
            sell++;
        }
        else{
            profit += v[sell] - v[buy];
            buy=sell=i;
        }
    }
    profit += v[sell] - v[buy];
    return profit;
    
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(v);


}