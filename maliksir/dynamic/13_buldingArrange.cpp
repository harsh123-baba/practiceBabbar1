#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
// it is same as prev question count binary but in this question.

// In this problem, 
// 1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
// 2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
// 3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

// here we have both side of roads means we have to make twise so just square your answer.

int  solve(int n){
    int oS =   1;
    int oB = 1;
    for(int i = 2; i<=n; i++){
        int nS = oB;
        int nB = oS+oB;
        oS = nS;
        oB = nB;
    }
    return ((oS+oB)*(oS+oB));
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}