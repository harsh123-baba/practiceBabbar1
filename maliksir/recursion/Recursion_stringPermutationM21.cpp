#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

void StringPermutation(string s, int cc, vector<char> spots, unordered_map<char, int> lo){
    if(cc==s.size()){
        for(int i =0; i<spots.size(); i++){
            cout<<spots[i];
        }
        cout<<endl;
        return ; 
    }
    char ch = s[cc];
    int last = lo[ch];
    for(int i = last+1; i<spots.size(); i++){
        if(spots[i] == '\0'){
            spots[i] = ch;
            lo[ch] = i;
            StringPermutation(s, cc+1, spots, lo);
            spots[i] = '\0';
            lo[ch] = last;
        }
    }
}


int main(){
    string s = "abba";
    unordered_map<char, int> lo;
    vector<char> spots(s.size());
    for(int i = 0; i<s.size(); i++){
        lo[s[i]] = -1;
    }
    StringPermutation(s, 0, spots, lo);
}