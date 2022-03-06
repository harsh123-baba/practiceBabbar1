#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void KlenWord(string s, unordered_map<char, int> map, int ts, int idx, string asf){
    if(idx==ts){
        cout<<asf<<endl;
        return;
    }
    for(int i = 0; i<s.size(); i++){
        if(map[s[i]]>0){
            map[s[i]]-=1;
            KlenWord(s, map, ts, idx+1, asf+s[i]);
            map[s[i]]+=1;
        }
    }
}

int main(){

    string s = "aaabb";
    unordered_map<char, int> m;
    for(int i = 0; i<s.size(); i++){
        if(m[s[i]]){
            m[s[i]]++;
        }
        else{
            m[s[i]]=1;
        }
    }
    KlenWord(s, m, 3, 0, "");   

}