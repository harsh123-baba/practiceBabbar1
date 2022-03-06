#include<vector>
#include<iostream>
using namespace std;

void Display(vector<vector<bool>>& v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v.size(); j++){
            // cout<<(v[i][j]?"q\t":"-\t");
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isPossible(vector<vector<bool>> v, int row , int col){
    for(int i=row, j = col; i>=0&&j>=0; i--, j--){
        if(v[i][j]){
            return false;
        }
    }
    for(int i = row, j = col; i>=0; i--){
        if(v[i][j]){
            return false;
        }
    }
    for(int i = row, j = col; i>=0&&j<v.size(); i--, j++){
        if(v[i][j]){
            return false;
        }
    }
    for(int i = row, j = col; j>=0; j--){
        if(v[i][j]){
            return false;
        }
    }
    return true;

} 


void NqueenCombination(vector<vector<bool>> v, int tq, int cq, int lidx){
    if(cq== tq){
    Display(v);
    cout<<endl;
        return;
    }
    for(int i = lidx+1; i<v.size()*v.size(); i++){
        int row = i/v.size();
        int  col = i%v.size();
        if(v[row][col]==false && isPossible(v, row, col)){
            v[row][col]= true;
            NqueenCombination(v, tq, cq+1, row*v.size()+col);
            v[row][col]=false;
        }   
    }
}



int main(){
    vector<vector<bool>> v(4, vector<bool>(4, false));
    NqueenCombination(v, 4,1, -1);
    Display(v);
}