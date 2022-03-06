#include<vector>
#include<iostream>
using namespace std;

void Print(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool isValid(vector<vector<int>> v, int i , int j , int val){
    for(int x = 0; x<v[0].size(); x++){
        if(v[i][x]==val){
            return false;
        }
    }
    for(int x = 0; x<v.size(); x++){
        if(v[x][j] == val){
            return false;
        }
    }

    int a = (i/3)*3;
    int b = (j/3)*3;
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            if(v[x+a][y+b]==val){
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<int>>& v, int i, int j){    
    if(i==v.size()){
        Print(v);
        return;
    }
    int ni = 0;
    int nj = 0;
    if(j==v[0].size()-1){
        nj = 0;
        ni = i+1;
    }
    else{
        nj = j+1;
        ni = i;
    }
    
    if(v[i][j]!=0){
        solveSudoku(v, ni , nj);
    }
    else{
        for(int po = 1; po<=9; po++){
            if(isValid(v, i, j, po)){
                v[i][j] = po;
                solveSudoku(v, ni, nj);
                v[i][j] = 0;
            }
        }
    }
}


int main(){
    vector<vector<int>> v= {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
solveSudoku(v, 0, 0);

}

