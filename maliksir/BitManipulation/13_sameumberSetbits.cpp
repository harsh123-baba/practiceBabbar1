#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long ncr(int i, int k){

}

int noOfBits(long n){
    int count = 0;
    while(n > 0){
        int rsbm = n & -n;
        n -= rsbm;
        count++;
    }
    return count;
}

int main(){
    long n;
    cin>>n;
    int k = noOfBits(n);

    

}