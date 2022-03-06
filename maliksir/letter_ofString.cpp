#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


vector<char> StringWord(string s){
    string word;
    vector<char> ans;
    stringstream iss(s);
    string x = iss.str();
    while(iss>>word){
        ans.push_back(word[0]);
    }
    return ans;
}


int main(){
    string s = "Mamta singh";
    vector<char> x = StringWord(s);
    for(int i = 0; i<x.size(); i++){
        cout<<x[i]<<" ";
    }
}