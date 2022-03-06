#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(char oddc, unordered_map<char, int> map, int cs, int ts , string asf, char ch){

}


int main(){
    string s;
    cin>>s;
    unordered_map<char, int>map;
    for(int i = 0; i<s.size(); i++){
        if(map[s[i]]){
            map[s[i]]++;
        }
        else{
            map[s[i]]=1;
        }
    }
    char oddch = '\0';
    int len = 0;
    int odds = 0;
    for(auto it : map){
        char ch = it.first;
        int freq = it.second;
        if(freq % 2 !=  0){
            oddch = ch;
            odds++;
        }
        map[ch] = freq/2;
        len+=freq/2;
        solve(oddch, map, 1, len, "", ch);
    }

}