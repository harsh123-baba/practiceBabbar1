#include<unordered_map>
#include<iostream>
using namespace std;

void Sol4(int k, int idx, string uq , unordered_map<char, int> map, string ans){
    if(k<0){
        return;
    }
    if(idx==uq.size()){
        if(k==0){
            cout<<ans<<endl;
        }
        return;
    }
    if(map[uq[idx]]){
        map[uq[idx]]-=1;
        Sol4(k-1, idx, uq, map, ans+uq[idx]);
        map[uq[idx]]++;
    }
    Sol4(k, idx+1, uq,map, ans);
}



int  main(){
    unordered_map<char, int> map;
    string s = "aaabbc";
    string uq = "";
    for(int i = 0; i<s.size(); i++){
        if(map[s[i]]){
            map[s[i]]++;
        }
        else{
            uq+=s[i];
            map[s[i]]=1;
        }
    }
    Sol4(2, 0, uq, map, "");
}