#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int solve(int a , int b, int c){
    int flip = 0;
    for(int i = 0; i<32; i++){
        bool ai = false;
        bool bi = false;
        bool ci = false;
        
        if((a & (1<<i)) >0){
            ai = true;
        }
        if((b&(1<<i))>0){
            bi = true;
        }
        if((c & (1<<i)) > 0){
            ci = true;
        }
        if(ci){
            if(!ai && !bi){
                flip++;
            }
            
        }
        else{
            if(ai && bi){
                flip+=2;
            }
            else if(ai || bi){
                flip ++;
            }
        }


    }
    return flip;
}


int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int flips = solve(a, b, c);
    cout<<flips;
}