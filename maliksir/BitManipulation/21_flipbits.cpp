// 1. You are given two numbers A and B.
// 2. You have to print the count of bits needed to be flipped to convert 'A' to 'B'.
#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


int kernigarh(int n){
    int count = 0;
    while(n!=0){
    int rbsm = n & -n;
        n -=rbsm;
        count++;
    }
    return count;
}


int main(){
    int n=1;
    int m=2;

    int x = n^m;
    int noOfChanges = kernigarh(x);
    cout<<noOfChanges;
}