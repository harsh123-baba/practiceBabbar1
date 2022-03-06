#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    vector<int> v = {1,2,2, 4};
    int x = v[0];
    for(int i=1; i<v.size(); i++){
        x = x^v[i];
    }    
    for(int i= 1;i<=v.size(); i++){
        x = x^i;
    }
    int rsbm= x & -x;
    int a  = 0;
    int b = 0;
    for(int i = 0; i<v.size(); i++){
        if((rsbm & v[i])==0){
            a = a^v[i];
        }
        else{
            b = b^v[i];
        }
    }
    for(int i =1; i<=v.size(); i++){
        if((rsbm & i)==0){
            a = a^i;
        }
        else{
            b = b^i;
        }
    }
    for(int i = 0; i<v.size(); i++){
        if(v[i]==a){
            cout<<"Missing : "<<b<<endl;
            cout<<"repeat : "<<a<<endl;
            break;
        }
        else if(v[i]==b){
            cout<<"Missing : "<<a<<endl;
            cout<<"repeat : "<<b<<endl;
            break;
        }
    }

}