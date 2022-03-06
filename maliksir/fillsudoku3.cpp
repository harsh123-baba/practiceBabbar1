#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>> board, int row, int col, char val){
        //row

        cout<<"ISvalid called";
        for(int i = 0; i<9; i++){
            if(board[i][row]==val){
                return false;
            }
        }
        //col
        for(int j = 0; j<9; j++){
            if(board[col][j] == val){
                return false;
            }
        }
        int si = (row/3)*3;
        int sj = (col/3)*3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[i+si][j+sj] == val){
                    return false;
                }
            }   
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board, int i , int j){
        if(i==board.size()){
            return true;
        }
        int ni=0;
        int nj = 0;
        if(j==board.size()-1){
            ni=i+1;
            nj = 0;
        }
        else{
            ni = i;
            nj = j+1;
        }
        if(board[i][j]!='.'){
            solveSudoku(board, ni , nj);
            return true;
        }
        else{
            for(char po = '1'; po<='9'; po++){
                if(isValid(board, i, j, po)){
                    board[i][j] = po;
                    solveSudoku(board, ni, nj);
                    board[i][j]='.';
                }
            }
        }
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int i =0;
        int j = 0;
        solveSudoku(board, 0, 0);
        
    }

    void print(vector<vector<char>>board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

int main() {
    vector<vector<char> > A = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'}, 
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'}, 
    {'4','.','.','8','.','3','.','.','1'}, 
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'}, 
    {'.','.','.','4','1','9','.','.','5'}, 
    {'.','.','.','.','8','.','.','7','9'}}; //Input sudoku

    solveSudoku(A);
    print(A);

}