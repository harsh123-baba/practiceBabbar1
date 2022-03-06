#include<iostream>
#include<unordered_map>
using namespace std;

void WordSelection3(int idx, int k, string ans, unordered_map<char, int> unique, string uq){
    if(k<0){return;}
    if(idx== uq.size()){
        if(k==0){
            cout<<ans<<endl;
        }
        return;
    }
    char ch = uq[idx];
    int maxFreq = unique[ch];
    for(int i = maxFreq; i>=0; i--){
        string s ="";
        for(int j=0; j<i; j++){
            s+=ch;
        }
        WordSelection3(idx+1, k-i, ans+s, unique, uq);
    }
}


int main(){
    string s = "aaabbc";
    string uq="";
    unordered_map<char, int> m;
    for(char ch: s){
        if(m[ch]){
            m[ch]++;
        }
        else{
            m[ch]=1;
            uq+=ch;
        }
    }
    WordSelection3(0, 2, "", m, uq);
}