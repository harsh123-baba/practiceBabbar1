#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans =0;
    for(int i = 2; i*i<n;){
        if(n%i == 0){
            n = n/i;
            ans += i;
        }
        else{
            i++;
        }
        
    }
    if(n != 1){
        ans += n;
    }
    cout<<ans;
}