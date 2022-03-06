#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Perm(vector<char> spots,string s, int cc, unordered_map<char, int> map){
    if(cc== spots.size()){
        for(int i = 0; i<spots.size();  i++){
            cout<<spots[i];
        }
        cout<<endl;
        return;
    }

    char ch = s[cc];
    int lo = map[ch];
    for( int i = lo +1; i<spots.size(); i++){
        if(spots[i] == '\0'){
            spots[i] = ch;
            map[ch] = i;
            Perm(spots, s, cc+1, map);
            map[ch] = lo;
            spots[i] = '\0';
        }
    }
}

int main(){
    string s;
    cin>>s;
    vector<char> spots(s.size());
    unordered_map<char, int> map;
    for(int i = 0; i<spots.size(); i++){
        map[s[i]] = -1;
    }
    Perm(spots, s, 0, map);
}