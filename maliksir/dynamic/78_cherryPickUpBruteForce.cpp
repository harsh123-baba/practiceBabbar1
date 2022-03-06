#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxCherries = INT32_MIN;
void helper(int row, int col, int ccsf, vector<vector<int>>& v){
    if(row<0 || col<0 || row >= v.size() || col >= v[0].size() || v[row][col] == -1){
        return;
    }
    if(row == 0 && col == 0){
        maxCherries = max(maxCherries, ccsf);
    }

    int cherries = v[row][col];
    v[row][col] = 0;
    helper(row -1 , col, ccsf + cherries, v);
    helper(row, col - 1, cherries + ccsf, v);
    v[row][col] = cherries;

}

void cp(int row, int col, int ccsf, vector<vector<int>>& v){
    if(row < 0 || col < 0 || row >= v.size() || col >= v[0].size() || v[row][col] == -1){
        return ;
    }
    if(row == v.size()-1 && col == v[0].size()-1){
        helper(row, col, ccsf, v);
    } 
    int cherries = v[row][col];
    v[row][col] = 0;
    cp(row, col + 1, ccsf + cherries, v);
    cp(row+1 , col , cherries+ ccsf, v);
    v[row][col] = cherries;

}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }    
    cp(0, 0, 0, v);
    cout<<maxCherries;
}