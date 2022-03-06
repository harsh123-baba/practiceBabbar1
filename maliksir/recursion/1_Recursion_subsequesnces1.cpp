#include<iostream>
#include<vector>
using namespace std;


vector<string> subSeq(string s){
    if(s.size()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch = s[0];
    vector<string> mres = subSeq(s.substr(1));
    vector<string> ans;
    for(string x: mres){
        ans.push_back(""+x);
        ans.push_back(ch+x);
        
    }
    return ans;

}



int main(){
    string x = "abc";
    vector<string> v = subSeq(x);
    for(string s: v){
        cout<<s<<endl;
    }

}