#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int getMinToRemove(string s){
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            if(st.size()==0){
                st.push(')');
            }else if(st.top()=='('){
                st.pop();
            }
            else if(st.top()!='('){
                st.push(')');
            }
        }
    }
    return st.size();
}


void Solution(string s, int minRemovalallowed, unordered_map<string, bool> map){
    if(minRemovalallowed == 0){
        int mr = getMinToRemove(s);
        if(mr == 0){
            if(!map[s]){
                cout<<s<<endl;
                // map.insert(s);
                map[s]=true;
            }
        }
        return;
    }

    for(int i = 0; i<s.size(); i++){
        string l = s.substr(0, i);
        string r = s.substr(i+1);
        Solution(l+r, minRemovalallowed-1, map);
    }

}





int main(){
    stack<char> st;
    string s = "()())";
    // Solution(st, 0, s, 0);
    // cout<<getMinToRemove(s);
    int mra = getMinToRemove(s);
    unordered_map<string, bool> map;
    Solution(s, mra, map);
}