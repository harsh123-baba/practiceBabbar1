#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

vector<int> Solution(vector<string> words, vector<string> puzzle){
    unordered_map<char, vector<int>> mWords;
    // for(int i = 0; i<26; i++){
    //     mWords[(char)('a'+i)] = vector<int>;
    // }
    
    // map m words store kr diye 
    vector<int> v;
    for(string s:words){
        int mask = 0;
        for(char ch : s){
            int bit = ch-'a';
            mask = mask | ((1<<bit));
        }
        unordered_set<char> unique;
        for(char ch: s){
            if(unique.find(ch)!= unique.end()){
                continue;
            }
            unique.insert(ch);
            mWords[ch].push_back(mask);
        }
        // for(auto it : mWords){
        //     for(int i:it.second){
        //         cout<<it.first<<" "<<i<<endl;
        //     }
        // }
    }

    // trace puzzle
    for(string word:puzzle){
    
        char c = word[0];
        // mWords[ch] pr traverse kre
        // for(string x : )
        
        int pmask=0;
        for(char ch : word){
            int bit = ch-'a';
            pmask = pmask | ((1<<bit));
        }
        int count = 0;
        // m sirf unko trace krra hu  jinke first char (of puzzle) words k word m ho
        for(int bitWords : mWords[c]){
            // int word = ;
            if((bitWords & pmask) == bitWords){
                count++;
                // cout<<"called"<<endl;
            }
        }
        v.push_back(count);
    }
    return v;
}



int main(){
    int n;
    cin>>n;
    vector<string> words;
    for(int i=0;i<n; i++){
        string s;
        cin>>s;
        words.push_back(s);
    }
    int m ;
    cin>>m;
    vector<string> puzzle;
    for(int i=0;i<m; i++){
        string s;
        cin>>s;
        puzzle.push_back(s);
    }

    vector<int> v = Solution(words, puzzle);
    for(int i = 0;  i<v.size(); i++){
        cout<<words[i] << "-> "<<v[i]<<endl;
        // cout<<v[i]<<endl;

    }
    

}