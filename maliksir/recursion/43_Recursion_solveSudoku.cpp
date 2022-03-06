#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void Display(vector<vector<char>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool isPossible(vector<vector<char>> v, int row, int col , char val){
    for(int i = 0; i<9; i++){
        if(v[row][i] == val){
            return false;
        }
    }
    for(int i = 0; i<9; i++){
        if(v[i][col] == val){
            return false;
        }
    }
    int r = (row/3)*3;
    int c = (col/3)*3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(v[i+r][j+c] == val){
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<char>>& v, int row, int col){
    if(row==v.size()){
        Display(v);
        return;
    }
    int ni = 0;
    int nj = 0;
    if (col == v.size()-1){
        nj = 0;
        ni = row+1;

    }
    else{
        ni = row;
        nj = col +1;
    }

    if(v[row][col]!='.'){
        solve(v, ni, nj);
    }
    else{
        for(char po = '1'; po<='9'; po++){
            if(isPossible(v, row, col , po)){
                v[row][col] = po;
                solve(v, ni, nj);
                v[row][col] = '.';
            }
        }
    }



}

void SolveSudoku(vector<vector<char>>& v){
    
    return solve(v, 0, 0);
}




int main(){
    vector<vector<char>> v= {{'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}}; //Input sudoku
    SolveSudoku(v);

}