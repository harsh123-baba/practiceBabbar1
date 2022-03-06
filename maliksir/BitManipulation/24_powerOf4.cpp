#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int bit = 0b01010101010101010101010101010101;
    if(n>0 && ((n & (n-1)) ==0 ) && (bit&n)>0){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

}