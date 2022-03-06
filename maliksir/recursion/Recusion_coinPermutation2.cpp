#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void coinselection(vector<int> coins, int tmnt, int amt, string ans){
    if(amt>tmnt){
        return;
    }
    else if(amt==tmnt){
        cout<<ans<<endl;
        return;
    }
    for(int i = 0; i<coins.size(); i++){
        coinselection(coins, tmnt, amt+coins[i], ans+to_string(coins[i])+"-");
    }
}


int main(){
    vector<int> coin = {2,3,5};
    coinselection(coin, 7, 0, "");


}