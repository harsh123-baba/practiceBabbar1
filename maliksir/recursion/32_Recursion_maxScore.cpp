#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


int solve(vector<int> freq, vector<string> s,vector<int> score, int idx){
    if(idx == s.size()){
        return 0;
    }
    int sno = solve(freq, s, score, idx+1);
    // int syes
    int sword = 0;
    string word = s[idx];
    bool flag = true;
    for(int i = 0; i<word.size(); i++){
        char ch = word[i];
        if(freq[ch-'a']==0){
            flag = false;
        }
        freq[ch-'a']--;
        sword += score[ch-'a'];
    }
    int syes = 0;
    if(flag){
        syes = sword + solve(freq, s , score, idx+1);
    }
    for(int i = 0;i<word.size(); i++){
        freq[word[i]-'a'] ++;
    }
    return max(sno , syes);

}



int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i = 0; i<n; i++){
        cin>>s[i];
    }
    int c;
    cin>>c;
    vector<char> alpha(c);
    for(int i = 0; i<c; i++){
        cin>>alpha[i];
    }
    // string alpha;
    // cin>>alpha;
    vector<int> score(26);
    for(int i = 0;i<26; i++){
        cin>>score[i];
    }
    vector<int> freq(26);
    for(char ch:alpha){
        freq[ch-'a']++;
    }
    cout<<solve(freq,s,score, 0);
}