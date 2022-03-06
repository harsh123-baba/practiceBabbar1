#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


void solve(unordered_map<char,int> map, string s, int k , int idx, vector<char> spots){
    // if(k<0){
    //     return;
        // }
    if(idx == s.size()){
        if(k==0){
            for(int i = 0; i<spots.size(); i++){
                cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }

    char ch = s[idx];
    int lo = map[ch];

    for(int i = lo+1; i<spots.size(); i++){
        if(spots[i] == '\0'){
            spots[i] = ch;
            map[ch] = i;
            solve(map, s, k-1, idx+1, spots);
            spots[i] = '\0';
            map[ch] = lo;
        }
    }
    if(lo == -1){
        solve(map , s, k, idx+1, spots);
    }
}
int main(){
    string s;
    cin>>s;
    unordered_map<char, int> map;
    // string uq = "";
    for(int i = 0; i<s.size(); i++){
        map[s[i]]  = -1;
    }
    int k;
    cin>>k;
    vector<char>spots(k, '\0');
    solve(map, s, k, 0, spots);

}