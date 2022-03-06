#include<vector>
#include<iostream>
using namespace std;



/*
    option pr hoge letters;
    level m hoge boxes/positions
*/


void combination(int cb, int tb, int ssf, int r,string ans){
    if(cb>tb){
        if(ssf==r){
            cout<<ans<<endl;
        }
        return;
    }
    combination(cb+1, tb, ssf, r, ans+"-");
    combination(cb+1, tb, ssf+1, r, ans+"i");
}


int main(){
    combination(1, 4, 0, 2, "");
}