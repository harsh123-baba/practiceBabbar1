#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    // i have to find the xor of all the pair sums 
    // like 
/*
     a b c d
     a+a;   b+a;
     a+b    b+b
     a+c    b+c
     a+d    b+d

     but mje ki baat yrh hai jb sare pair bnege to a+b got canclled during b+a xor beacuse of xor sake
     so bachea a+a, b+b, c+c, d+d;

  */  
    vector<int> v = {1, 2, 3, 4, 5};
    int x = 0;
    for(int i = 0; i<v.size(); i++){
        x = x^(2*v[i]);
    }
    cout<<x;
}