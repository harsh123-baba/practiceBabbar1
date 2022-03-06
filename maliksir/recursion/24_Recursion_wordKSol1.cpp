#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


void WordKselection(string uniqueString, int cc,int ssf ,int r, string ans){
    if(cc==uniqueString.size()){
        if(ssf==r){
            cout<<ans<<endl;
        }
        return;
    }
    char ch = uniqueString[cc];
    WordKselection(uniqueString, cc+1, ssf+1, r, ans+ch);
    WordKselection(uniqueString, cc+1, ssf, r, ans+"");
}


int main(){
    string s = "abbaccc";
    // i want to directly pass the unique string so my work load gonna less 
    string uniqueString = "";
    unordered_set<char> set;
    
    for(char ch : s){
        if(set.find(ch)==set.end()){
            set.insert(ch);
            uniqueString+=ch;
        }
    }
    WordKselection(uniqueString, 0, 0, 2, "");
}

