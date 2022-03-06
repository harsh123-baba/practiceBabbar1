#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int withfee(vector<int> stocks, int fee){
    int obuyStateProfit = -stocks[0];
    int osellStateProfit = 0;
    int n = stocks.size();
    for(int i = 1; i<n; i++){
        int nbuyStateProfit = 0;
        int nsellStateProfit = 0;
        // why i declare these variable
        // why dont i use directly prev varibable and update them
        // actually these variables are use 2 times so i cant loose their value
        
        if( osellStateProfit - stocks[i] > obuyStateProfit){
            nbuyStateProfit = osellStateProfit - stocks[i];
        }
        else{
            nbuyStateProfit = obuyStateProfit;
        }
        if(obuyStateProfit + stocks[i] -fee > osellStateProfit){
            nsellStateProfit = osellStateProfit + stocks[i] - fee;
        }
        else{
            nsellStateProfit = osellStateProfit;
        }
        osellStateProfit = nsellStateProfit;
        obuyStateProfit = nbuyStateProfit;
    }
    return osellStateProfit;
}   


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int fee;
    
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cin>>fee;
    cout<<withfee(v, fee);
}