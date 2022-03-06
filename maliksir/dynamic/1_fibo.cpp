#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

//recursive Soln
int fib(int n){
    if(n==1 || n== 0 ){
        return n;
    }
    int f1 = fib(n-1);
    int f2 = fib(n-2);
    return f1+f2;
}

// memoization()

int fibMem(int n, vector<int> v){
    if(n==1 || n==0){
        return n;
    }
    if(v[n] >0){
        return v[n];
    }
    int f1 = fibMem(n-1, v);
    int f2  = fibMem(n-2 , v);
    int cp = f1+f2;
    v[n] = cp;
    return cp;
}

// tabular format

int fibtab(int n){
    vector<int> dp(n+1, 0);
    dp[0]=0;
    dp[1]=1;
    for(int i= 2; i<=n; i++){
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n+1, 0);
    cout<<fibtab(n);
}