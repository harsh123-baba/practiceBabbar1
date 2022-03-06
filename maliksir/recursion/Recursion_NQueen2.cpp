#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<vector<int>>chess, int row , int col){
    for(int i = row-1, j=col; i>=0; i--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i = row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i=row-1, j=col+1; i>=0&&j<chess.size(); i--, j++){
        if(chess[i][j]==1){
            return false;
        }
    }
    return true;
}


void NQueen(vector<vector<int>>chess, int row, string s){
    if(row==chess.size()){
        cout<<s<<endl;
        return;
    }
    for(int col=0; col<chess.size(); col++){
        if(isPossible(chess, row, col)){
            chess[row][col]=1;
            NQueen(chess, row+1, s+to_string(row)+"-"+to_string(col)+" ");
            chess[row][col]=0;
        }
    }
}

int main(){
    vector<vector<int>>v(4, vector<int>(5));
    NQueen(v, 0, "");
}