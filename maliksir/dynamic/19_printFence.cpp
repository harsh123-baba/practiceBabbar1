#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n>>k;
    int same = k*1;
    int diff = (k-1)*k;
    int total = diff+ same;
    
    for(int i = 3; i<n; i++){
        same = diff;
        diff = total*(k-1);
        total = same + diff;
    }
    cout<<total;
}