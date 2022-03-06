#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

void Nqueen(vector<vector<bool>> v, int row, int cols,int sDiag, int wDiag, string asf){
    if(row == v.size()){
        // cout<<"hoii";
        cout<<asf<<endl;

        return;
    }
    // col & cols are different

    for(int col = 0; col< v.size(); col++){
            // cout<<row<<endl;
        if(
            ((cols & (1<<col))==0) &&
            ((sDiag & (1<<(row-col+v.size()-1)))==0) &&
            ((wDiag &(1<<(row+col)))==0)

        ){
            v[row][col] = true;
            // toggle bits
            cols = cols ^ (1<<col);
            sDiag = sDiag ^ (1<<(row-col+v.size()-1));
            wDiag = wDiag ^ (1<<(row+col));
            Nqueen(v, row+1, cols, sDiag, wDiag, asf+to_string(row)+"-"+to_string(col)+" , ");
            cols = cols ^ (1<<col);
            sDiag = sDiag ^ (1<<(row-col+v.size()-1));
            wDiag = wDiag ^ (1<<(row+col));
            v[row][col] = false;
        }
    }




}



int main(){
    int row = 0;
    int cols = 0;
    int sDiag = 0;
    int wDiag = 0;
    string asf = "";
    vector<vector<bool>> v(4, vector<bool>(4, false));
    // cout<<row;
    Nqueen(v, row, cols, sDiag, wDiag, asf);
    // cout<<row;

}