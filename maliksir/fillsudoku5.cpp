#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>>& v, int r, int c , char val){
    // vertically check
    for(int i = 0; i<=v.size(); i++){
        if(v[i][c]==val){
            return false;
        }
    }
    for(int j =0; j<v[0].size(); j++){
        if(v[r][j]==val){
            return false;
        }
    }
    int si = (r/3)*3;
    int sj = (c/3)*3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(v[i+si][sj+j]==val){
                return false;
            }
        }
    }
    return true;
}

void Display(vector<vector<char>>& v){
    for(int i = 0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


void FillSudoku(vector<vector<char>>& v, int r, int c){
    if(r==v.size()){
        Display(v);
        return;

    }
    int ni=0;
    int nj=0;
    if(r==v.size()-1){
        ni = r+1;
        nj= 0;
    }
    else{
        ni=r;
        nj = c+1;
    }
    if(v[r][c]!='-'){
        FillSudoku(v, ni, nj);

    }
    else{
        for(char po='1'; po<='9'; po++){
            if(isValid(v, r, c, po)){
                v[r][c]=po;
                // if()
                FillSudoku(v, ni, nj);
                v[r][c]='-';
            }
                // FillSudoku(v, ni, nj);

        }
                FillSudoku(v, ni, nj);

    }
}


int main(){
    vector<vector<char> > A = {{'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}}; //Input sudoku
    FillSudoku(A, 0, 0);    

}