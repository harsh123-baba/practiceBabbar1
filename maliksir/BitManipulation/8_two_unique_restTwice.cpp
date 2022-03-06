#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    vector<int> v = {10, 20, 20, 10, 30, 30, 40, 45};
    int x = 0;
    for(int i=0;i<v.size(); i++){
        x = x^v[i];
    }
    int rbsm = x & -x;
    int a = 0;
    int b = 0;
    for(int i = 0; i<v.size(); i++){
        if((rbsm & v[i])==0){
            b = b ^ v[i];
        }
        else{
            a = a^ v[i];
        }
    }
    cout<<a<<" "<<b;
}