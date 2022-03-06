#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

vector<string> graycodeGenrator(int n){
    if(n==1){
        vector<string> bres;
        bres.push_back("0");
        bres.push_back("1");
        return bres;
    }
    vector<string> mres = graycodeGenrator(n-1);
    vector<string> res;
    for(int i = 0; i<mres.size(); i++){
        string s = mres[i];
        s = "0"+s;
        res.push_back(s);
    }
    for(int i = mres.size()-1; i>=0; i--){
        string s = mres[i];
        s = "1"+s;
        res.push_back(s);
    }
    return res;
}

int main(){
    int n;
    n=3;

    vector<string> res = graycodeGenrator(n);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }

}