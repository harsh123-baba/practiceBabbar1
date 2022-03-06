#include<iostream>
#include<unordered_set>
using namespace std;

//level is performed by call
// options are performed by for loop

// slot level bnege
// char bnege option

void Klen2(int idx ,int k , string uq, unordered_set<char> used, string ans){
    if(idx>k){
        cout<<ans<<endl;
        return;
    }
    for(int i = 0; i<uq.size(); i++){
        if(used.find(uq[i])==used.end()){
            used.insert(uq[i]);
            Klen2(idx+1, k, uq, used, ans+uq[i]);
            used.erase(uq[i]);
        }
    }
}


int main(){
    string s = "abbbaaacccc";
    unordered_set<char> unique;
    string uq ="";
    for(int i = 0;i<s.size(); i++){
        if(unique.find(s[i])==unique.end()){
            unique.insert(s[i]);
            uq+=s[i];
        }
    }
    unordered_set<char> used;
    Klen2(1, 2, uq, used, "");
}