#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void Cointhree(string ans, vector<int> coin, vector<bool>used, int tamt, int amt){
    if(amt> tamt){
        return;
    }
    else if(tamt == amt){
       cout<<ans<<endl;
        return;
    }
    for(int i = 0; i<coin.size(); i++){
        if(used[i]==false){
            used[i] = true;
            Cointhree(ans+to_string(coin[i]), coin , used, tamt, amt+coin[i]);
            used[i] = false;
        }
    }
}

int main(){
    vector<int> coin = {2, 5, 7, 8, 4};
    vector<bool> used(coin.size(), false);
    Cointhree("", coin, used, 12,0);
}