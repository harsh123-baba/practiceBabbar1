#include<vector>
#include<iostream>
using namespace std;

void solve(int open , int close, vector<string>& op, string s){
    if(open==0 && close ==0){
        op.push_back(s);
        return;
    }
    if(open!=0){
        solve(open-1, close, op, s+'(');
    }
    if(close >open){
        solve(open, close-1, op, s+')');
    }
    return;
}

vector<string> GenrateParenthesis(int n){
    vector<string> op;  
    string s;
    solve(n, n, op, s);
    return op;
}

int main(){
    vector<string>  s = GenrateParenthesis(3);
    for(int i = 0; i<s.size(); i++){
        cout<<s[i]<<"\n";
    }
}