// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
// i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


int withCoolDown(vector<int> v){
    int n = v.size();
    int oldSellStateP = 0;
    int oldBuyStateP = -v[0];
    int oldCoolStateP = 0;

    
    for(int i = 1; i<n; i++){
        int newSellStateP = 0;
        int newBuyStateP = 0;
        int newCoolStateP = 0;

        if(oldCoolStateP - v[i] > oldBuyStateP ){
            newBuyStateP = oldCoolStateP - v[i];
        }
        else{
            newBuyStateP = oldBuyStateP; 
        }

        if(oldBuyStateP + v[i] > oldSellStateP){
            newSellStateP = oldBuyStateP + v[i];
        }
        else{
            newSellStateP = oldSellStateP;
        }

        if(oldSellStateP  > oldCoolStateP){
            newCoolStateP = oldSellStateP;
        }
        else{
            newCoolStateP = oldCoolStateP;
        }
        oldCoolStateP = newCoolStateP;
        oldBuyStateP = newBuyStateP;
        oldSellStateP = newSellStateP;
    }
    return oldSellStateP;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<withCoolDown(v);

}