#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    string s = "10010101010001";
    int odd=0;
    int even = 0;
    for(int i = 0; i<s.size();i++){
        int bit = s[i]-'0';
        if((i&1) == 0){
            even+=bit;
        }
        else{
            odd+=bit;
        }
    }
    int delta = even-odd;

    if(delta %11 == 0){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}