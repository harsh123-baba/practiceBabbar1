#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int evenmask = 0xAAAAAAAA;
    int oddmask = 0x55555555;
    evenmask = n&evenmask;
    oddmask = n&oddmask;
    evenmask = (evenmask>>1);
    oddmask = (oddmask<<1);
    
    int x = evenmask | oddmask;
    cout<<x;
}
