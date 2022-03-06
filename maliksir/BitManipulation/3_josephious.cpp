#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int maxpower(int n){
    int i = 1;
    while(i*2<=n){
        i = i*2;
    }
    return i;
}

int main(){
    int n;
    n = 10;
    int hp2 = maxpower(n);
    int l = n-hp2;
    cout<<2*l+1;
}