#include<unordered_set>
#include<iostream>
using namespace std;

//using permutation concept
//here level pr hoge places and 

void WordKSelection(string unique, int ts, int cc, int lc, string ans){
    if(cc> ts){
        cout<<ans<<endl;
        return;
    }
    for(int i = lc+1; i<unique.size(); i++){
        char ch = unique[i];
        WordKSelection(unique, ts, cc+1,i, ans+ch);
    }
}



int main(){
    string s = "abbbaaacccc";
    unordered_set<char> set;
    string unique = "";
    for(int i = 0; i<s.size(); i++){
        if(set.find(s[i])==set.end()){
            // char ch = s[i]
            set.insert(s[i]);
            unique+=s[i];
        }
    }
    WordKSelection(unique,2, 1, -1,""); 
}   