#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void KlenWord3Comb(string s, unordered_map<char, int>m, vector<char> spots, int ts, int ssf, int idx){
    if(idx == s.size()){
        if(ssf==ts){
            for(int i = 0; i<spots.size(); i++){
                cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }
    char ch = s[idx];
    int lo = m[ch];
    for(int i = lo+1; i<spots.size(); i++){
        if(spots[i]=='\0'){
            spots[i] = ch;
            m[ch] = i;
            KlenWord3Comb(s, m, spots, ts, ssf+1, idx+1);
            spots[i] = '\0';
            m[ch] = lo;
        }
    }
    if(lo==-1){
        KlenWord3Comb(s, m, spots, ts, ssf, idx+1);

    }
}


int main(){
    string s = "aaabc";
    unordered_map<char, int> map;
    for(int i= 0; i<s.size(); i++){
        map[s[i]] =-1;
    }
    int k = 3;
    vector<char> spots(k, '\0');
    KlenWord3Comb(s,map, spots, k, 0, 0);
}