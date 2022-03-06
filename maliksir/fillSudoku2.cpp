#include<iostream>
#include<vector>
using namespace std;
const int n= 9;
const int m= 9;


void Print(vector<vector<int>> v){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isValid(vector<vector<int>> v, int i , int j, int val){
    for(int x=0; x<9; x++){
        if(v[i][x]==val){
            return false;
        }
    }
    for(int x=0; x<9; x++){
        if(v[x][j]==val){
            return false;
        }
    }
    int si = (i/3)*3;
    int sj = (j/3)*3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3;j++){
            if(v[i+si][j+sj] == val){
                return false;
            }
        }
    }
    return true;

}



void SolveSudoku(vector<vector<int>> v, int i, int j){
    if(i==v.size()){
        Print(v);
        return;
    }
    int ni = 0;
    int nj = 0;
    if(j==v.size()-1){
        ni = i+1;
        nj = 0;
    }
    else{
        ni = i;
        nj = j+1;
    }

    if(v[i][j]!=0){
        SolveSudoku(v,ni,nj);
    }
    else{
        for(int po=1; po<=9; po++){
            if(isValid(v, i, j, po)){
                v[i][j] = po;
                SolveSudoku(v, ni, nj);
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

SolveSudoku(v, 0, 0);
}