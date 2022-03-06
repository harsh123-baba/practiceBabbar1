/*  here we have to think off about many more option to solve before that i have done one thing
    i have gone from starting position to destination position (x1);
    and come back and collect cherries (y1)
    ese hr x1 k liye bht sare return path bh nikle


    // ab nyi approch leke chlo 
    suppose 2 robot h us point pr toh wo apne hisab s move kre or bta de max cherry to pick


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solution(int r1, int c1, int r2, int c2, vector<vector<int>> v){
    if(r1 >= v.size() || c1 >= v.size() || r2 >= v.size() || c2 >= v.size() || v[r1][c1] == -1 || v[r2][c2] == -1){
        return INT32_MIN;
    }
    if(r1 == v.size()-1 && c1 == v.size()-1){
        return v[r1][c1];
    }
    int cherries = 0;
    if(r1 == r2 && c1 == c2){
        cherries += v[r1][c1];
    }
    else{
        cherries += v[r1][c1] + v[r2][c2];
    }
    int f1 = solution(r1, c1+1, r2, c2+1, v);
    int f2 = solution(r1+1, c1, r2+1, c2, v);
    int f3 = solution(r1+1, c1, r2, c2+1, v);
    int f4 = solution(r1, c1+1, r2+1, c2, v);
    cherries += max(max(f1, f2), max(f3, f4));
    return cherries;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }    
    cout<<solution(0,0, 0, 0, v);
}