#include<iostream>
#include<vector>
using namespace std;

static vector<string> code = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> KeyPadCombination(string s){
    if(s.size()==0){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    char ch = s[0]-'0';  // have to subtract character 0 to get integer ch mean 0th index 1st index 2nd index
    string rest = s.substr(1);
    string codeforch = code[ch];
    vector<string> mres = KeyPadCombination(rest);
    vector<string> fres;
    for(int i = 0; i<codeforch.size(); i++){
        char codeforchletters = codeforch[i];
        for(string x:mres){
            fres.push_back(codeforchletters + x);
        }
    }
    return fres;
}



int main(){
    string s = "123";
    vector<string>x = KeyPadCombination(s);
    for(string ch:x){
        cout<<ch<<endl;
    }
}