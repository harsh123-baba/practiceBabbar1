#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

void dfs(int i, int n){
    if(i > n){
        return;
    }
    cout<<i<<endl;
    for(int j = 0; j<10; j++){
        dfs(10*i+j, n);
    }
}


int main(){
    for(int i = 1; i<=9; i++){
        dfs(i, 120);
    }
    // dfs(0, 3);
}