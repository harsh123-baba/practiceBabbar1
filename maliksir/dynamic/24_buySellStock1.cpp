#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    // vector<int> v = {3, 4, 1, 7, }
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    
    int ifSellToday = 0;
    int bestBuy = v[0];
    int asf = 0;
    for(int i =1; i<n; i++){
        if(bestBuy > v[i]){
            bestBuy = v[i];
        }
        ifSellToday = v[i] - bestBuy ;
        if(asf < ifSellToday){
            asf = ifSellToday;
        }
    }

    cout<<asf;

}