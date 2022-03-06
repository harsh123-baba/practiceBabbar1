#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int res=0;

    for(int i = 0;i<32; i++){
        int counton=0;
        for(int val:v){
            if((val & (1<<i))!=0){
                counton++;
            }
        }
        int countoff = v.size()-counton;
        int diff = counton *countoff*2;
        res += diff;

    }
    cout<<res;
}   