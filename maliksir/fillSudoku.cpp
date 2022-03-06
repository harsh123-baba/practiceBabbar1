#include<vector>
#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;


bool isValid(vector<vector<int>> v, int row, int col, int val){
    //check in column
    for(int i = 0; i<v[0].size(); i++){
        if(v[row][i]==val){
            return false;
        }
    }
    
    // for row
    for(int i = 0; i<v.size(); i++){
        if(v[i][col]==val){
            return false;
        }
    }

    int si = (row/3)*3;
    int sj = (col/3)*3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3;j++){
            if(v[i+si][j+sj] == val){
                return false;
            }
        }
    }
    return true;

}

void Print(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


void solveSudoku(vector<vector<int>>& v, int i, int j){
    if(i==v.size()){
        Print(v);
        return ;
    }
    int ni = 0;
    int nj = 0;
    if(j == v[0].size()-1){
        ni= i+1;
        nj = 0;
    }
    else{
        nj = j+1;
        ni = i;
    }
    if(v[i][j]!=0){
        solveSudoku(v, ni, nj);
    }
    else{
        for(int po = 1; po<=9; po++){
            if(isValid(v, i, j, po)==true){
                v[i][j] = po;
                solveSudoku(v, ni, nj);
                v[i][j]=0;
            }
        }
    }
}

// vector<vector<int>> solveSudoku(vector<vector<int>> v){
//     return v;
// }   


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
// Print(v);
}