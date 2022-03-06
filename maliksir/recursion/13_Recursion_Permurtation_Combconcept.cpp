#include<vector>
#include<iostream>
using namespace std;

//ncr * r! = npr;

//concept of combination to solve permutation

/*
    option pr hoge letters;
    level m hoge boxes/positions


*/


void Permutation(int cb, int tb, vector<int> items, int ssf, string ans, int r){
    if(cb>tb){
        if(ssf==r){
            cout<<ans<<endl;
        }
        return;
    }
    for(int i = 0; i<items.size(); i++){
        if(items[i]==0){
            items[i]=1; // to check weather item is available or not
            Permutation(cb+1, tb, items, ssf+1, ans+to_string(i+1), r);
            items[i]=0;
        }
    }
    Permutation(cb+1, tb, items, ssf , ans+"0", r);
    // return;
}



int main(){
    vector<int> items(2, 0);
    Permutation(1, 3, items, 0, "", 2);
}