#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(vector<int> v){
    int n = v.size();
    int minsf = v[0];   // min so far
    int mpist = 0;     // max profit if sold today;
    vector<int> dpl(n, 0);
    for(int i = 1; i < n; i++){
        if(v[i]<minsf){
            minsf = v[i];
        }
        mpist = v[i]-minsf;
        if(mpist > dpl[i-1]){
            dpl[i] = mpist;
        }
        else{
            dpl[i] = dpl[i-1];
        }
    }
    int maxsf = v[n-1]; // max so far
    int mpibt = 0;   //max profit if bought today
    vector<int> dpr(n, 0);
    for(int i = n-2; i>=0; i--){
        if(v[i] > maxsf){
            maxsf = v[i];
        }
        mpibt = maxsf - v[i];
        if(mpibt > dpr[i+1]){
            dpr[i] = mpibt;
        }
        else{
            dpr[i] = dpr[i+1];
        }
    }
    int op = 0;
    for(int i = 0; i<n; i++){
        if(op < dpr[i]+dpl[i]){
            op = dpl[i]+dpr[i];
        }
    }
    return op;

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n, 0);


    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(v);
}