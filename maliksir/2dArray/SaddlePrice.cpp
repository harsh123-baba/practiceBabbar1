#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Min(vector<vector<int>>v, int i){
    int min = INT32_MAX;
    int row = -1;
    for(int k = 0; k<v.size(); k++){
        if(v[i][k] <min){
            min = v[i][k];
            row = k;
        }
    }
    return row;
}
int Max(vector<vector<int>>v, int j){
    int max = INT32_MIN;
    int col = -1;
    for(int i = 0; i<v[0].size(); i++){
        if(v[i][j] > max){
            max=v[i][j];
            col = i;
        }
    }
    // cout<<max<<endl;
    return col;
}


int saddle(vector<vector<int>> v){
    int val = -1;
    for(int i = 0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            if(j==Min(v, i) && i==Max(v, i)){
                val = v[i][j];
                break;
            }
        }
    }
    return val;


}


int main(){
    vector<vector<int>> v = {{35,36,50},{10,11,16},{23,30,34}};
    // cout<<Max(v, 1);
    cout<<saddle(v);
}