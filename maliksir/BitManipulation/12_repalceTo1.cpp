#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int res = 0;
    while(n!=1){
        if((n&1)==0){
            n = n/2;
        }
        else if(n==3)
        {
            n= n-1;
        }
        // 4x+1 nature check
        else if((n&3) ==1){
            n = n-1;
        }

        // 4x+3 nature check
        else if((n&3) ==3){
            n = n+1;
        }

        res ++;
    }
    cout<<res;

}