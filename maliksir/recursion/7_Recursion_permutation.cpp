#include<iostream>
using namespace std;

/*
    level pr hoge letters;
    option m hoge boxes/positions


*/

void Permutation(string s, string asf){
    if(s.size()==0){
        cout<<asf<<endl;
        return;
    }
    for(int i = 0; i<s.size(); i++){
        char ch = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i+1);
        Permutation(left+right, asf+ch);
    }
    return;

}

int main(){
    string s = "abc";
    Permutation(s, "");

}