#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void KlenWordThird(string s, unordered_map<char, int>m, vector<char> spots,int idx, int ts, int ssf){
    // if(ssf>ts){
    //     return;
    // }
    if(idx==s.size()){
        if(ssf==ts){
            // cout<<ans<<endl;
            for(int i = 0; i<spots.size(); i++){
                cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }
    char ch = s[idx];
    int lo = m[ch];
    for(int i = lo+1; i<spots.size() ; i++){
        if(spots[i]=='\0'){
            spots[i] = ch;
            m[ch] = i;
            KlenWordThird(s, m, spots, idx+1, ts, ssf+1);
            spots[i] = '\0';
            m[ch] = lo;
        }
    }
    if(lo==-1){
        KlenWordThird(s, m , spots, idx+1, ts, ssf);
    }

}


int main(){
    string s = "aaabc";
    
    unordered_map<char, int> m;
    for(int i = 0; i<s.size(); i++){
        m[s[i]]=-1;
    }
    int k = 3;
    vector<char> spots(k, '\0'); 
    KlenWordThird(s, m, spots, 0, k, 0);
}