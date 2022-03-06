#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

//only unique coins

void Coinselection(int i , vector<int> coin, int amsf, int camt, string ans){
    if(i==coin.size()){
        if(amsf == camt){
            cout<<ans<<endl;
        }
        return;
    }
    Coinselection(i+1, coin, amsf, camt+coin[i], ans+to_string(coin[i]));
    Coinselection(i+1, coin, amsf, camt, ans);

}



int main(){
    vector<int> coin = {2, 5, 7, 8, 4, 2, 2, 2, 2};
    unordered_map<int , int> m;
    vector<int> unique;
    for(int i =0; i<coin.size(); i++){
        if(m[coin[i]]){
            m[coin[i]]++;
        
        }
        else{
            m[coin[i]]=1;
            unique.push_back(coin[i]);
        }
    }


    Coinselection(0, unique, 12, 0, "");

}