#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

// recursive
int climb(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int c1 = climb(n-1);
    int c2 = climb(n-2);
    int c3 = climb(n-3);
    int c = c1+c2+c3;
    return c;
}

// tabuler
int climbtab(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        if(n==1){
            dp[i] = dp[i-1];
        }
        if(n==2){
            dp[i] = dp[i-1]+dp[i-2];
        }
        else{

            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }

    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    cout<<climbtab(n);
}