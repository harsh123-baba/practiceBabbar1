#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool isPillindrome(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){

            return false;
            break;
        }
        i++;
        j--;
    }
    return true;
}

void Solution(string s, string asf){
    if(s.size()== 0){
        cout<<asf<<endl;
        return;
    }
    for(int i = 0; i<s.size(); i++){
        string prefix = s.substr(0, i+1);
        string ros = s.substr(i+1);
        if(isPillindrome(prefix)){
            Solution(ros, asf+"("+ prefix +")");
        }
    }
}


int main(){
    string s = "pep";
    Solution(s, "");
}