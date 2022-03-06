#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int GameOfExecution(int n, int k){
    if(n==1){
        return 0;
    }
    int x = GameOfExecution(n-1, k);
    int y = (x+k)%n;
    return y;

}


int main(){
    cout<<GameOfExecution(4, 2);
}