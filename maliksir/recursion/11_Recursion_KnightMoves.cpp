#include<vector>
#include<iostream>
using namespace std;


void Display(vector<vector<int>>& chess){
    for(int i =0; i<chess.size(); i++){
        for(int j = 0; j<chess[0].size(); j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void KnightMoves(vector<vector<int>> chess, int row, int col, int move){
    if(row<0 || col<0 || row>=chess.size() || col>=chess.size() || chess[row][col]>0){
        return;
    }
    else if(move==(chess.size()*chess[0].size())){
        chess[row][col]=move;
        Display(chess);
        chess[row][col]=0;
        return;
    }
    chess[row][col] = move;
    KnightMoves(chess, row-2, col+1, move+1);
    KnightMoves(chess, row-1, col+2, move+1);
    KnightMoves(chess, row+1, col+2, move+1);
    KnightMoves(chess, row+2, col+1, move+1);
    KnightMoves(chess, row+2, col-1, move+1);
    KnightMoves(chess, row+1, col-2, move+1);
    KnightMoves(chess, row-1, col-2, move+1);
    KnightMoves(chess, row-2, col-1, move+1);
    chess[row][col]=0;
    return;
}




int main(){
    vector<vector<int>> v(5, vector<int>(5, 0));
    KnightMoves(v, 2, 2,1);
}