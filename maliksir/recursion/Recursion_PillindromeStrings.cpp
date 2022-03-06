#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Pillindrome(int c, int t, string asf , unordered_map<char, int> map, char oddc){
    if(c>t){
        string rev = "";
        string res = asf;
        for(int i  = asf.size()-1; i>=0; i--){
            rev += asf[i];
        }
        if(oddc!='\0'){
            res+=oddc;
        }
        res = res+rev;
        cout<<res;
        cout<<endl;
        return;
    }
    for(auto it:map){
        int freq = it.second;
        if(freq>0){
            map[it.first] = freq-1;
            Pillindrome(c+1, t, asf+it.first, map, oddc);
            map[it.first] = freq;
        }   
    }
}


int main(){
    string s = "aabbd";
    unordered_map<char, int> map;
    for(int i = 0; i<s.size(); i++){
        if(map[s[i]]){
            map[s[i]]++;
        }
        else{
            map[s[i]]=1;
        }
    }
    // for(auto it : map){
    //     cout<<it.first<<" "<<it.second<< " ";
    // }
    char oddc = '\0';
    int odd = 0;
    int len = 0;
    for(auto it : map){
        if(it.second % 2 !=0){
            oddc = it.first;
            odd++;

        }
        it.second = it.second/2;
        len += it.second;
        // cout<<len<<" ";
        // cout<<it.second<<endl;
    }
    if(odd > 1){
        cout<<"-1\n";
        return 0;
    }
    // cout<<len<<endl;
    Pillindrome(1, len, "", map, oddc);
}