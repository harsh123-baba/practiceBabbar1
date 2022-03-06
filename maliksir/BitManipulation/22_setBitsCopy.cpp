#include<bits/stdc++.h> 
#include<iostream>
using namespace std;





int main(){
    int a = 10;
    int b = 13;
    int l = 2;
    int r = 3;
    // int mask = 1;
    int mask =(1<< (r-l+1));
    mask = mask-1;
    mask = mask<<(l-1);

    mask = a&mask;
    int ans = b | mask;
    cout<<ans;
}