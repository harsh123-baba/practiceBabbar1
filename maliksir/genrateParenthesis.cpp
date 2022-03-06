#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void solve(int open, int close, string op, vector<string>& v)
{
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }
    if (open != 0)
    {
        // string op1 = op;
        // op1.push_back('(');
        // op1 = op1+'(';
        // cout<<op1;
        solve(open - 1, close, op+'(', v);
    }
    if (close > open)
    {
        // string op2 = op;
        // cout<<"I am called";
        // op2.push_back(')');
        // op2 = op2+')';
        // cout<<op2;
        solve(open, close - 1, op+')', v);
    }
    return;
}

vector<string> AllParenthesis(int n)
{
    // Your code goes here
    int open = 3;
    int close = 3;
    string op = "";
    vector<string> v;
    solve(open, close, op, v);
    return v;
}

int main(){
    int n = 3;
    vector<string> v = AllParenthesis(n);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}
