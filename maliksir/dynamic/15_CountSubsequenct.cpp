#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(string s){
    
    int a = 0;
    int ab = 0;
    int abc = 0;
    
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='a'){
            a = 2*a +1;

        }
        else if(s[i]=='b'){
            ab = 2*ab +a;
            
        }
        else if(s[i]=='c'){
            abc = 2*abc +ab;
            
        }
    }
    return abc;
}


int main(){
    string s ="abcabc";
    // cin>>s;
    cout<<solve(s);
    
}