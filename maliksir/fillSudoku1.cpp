#include<vector>
#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;


bool isValid(vector<vector<int>>& v, int row, int col, int val){
    
    for(int i = 0; i < 9; i++) {
            if(v[i][col] == val) 
                return false; 
            
            if(v[row][i] == val) 
                return false; 
            
            if(v[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) 
                return false; 
        }
        return true;

}

void Print(vector<vector<int>>& v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}




bool solveSudoku(vector<vector<int>>& v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] == 0){
                    for(int c = 1; c <= 9; c++){
                        if(isValid(v, i, j, c)){
                            v[i][j] = c; 
                            
                            if(solveSudoku(v))
                                return true; 
                            else
                                v[i][j] = 0; 
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }

void Sudoku(vector<vector<int>>& v){
    solveSudoku(v);
    // Print(v);
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


Print(v);
Sudoku(v);
cout<<endl;
Print(v);
}