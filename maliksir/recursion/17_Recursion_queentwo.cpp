#include<iostream>
#include<vector>
using namespace std;

//combination   

void QueenTwo(int tq, int cq, string asf, int row, int col){
    if(row==tq){
        if(cq==tq){
            cout<<asf<<endl;
        }
        return;
    }
    string yasf="";
    string nasf="";
    int ni=0;
    int nj=0;
    if(col==tq-1){
        ni = row+1;
        nj = 0;
        yasf = asf+"q\n";
        nasf = asf+"-\n";
    }
    else{
        ni=row;
        nj=col+1;
        yasf = asf+"q";
        nasf = asf+"-";
    }
    QueenTwo(tq, cq+1, yasf, ni, nj);
    QueenTwo(tq, cq, nasf, ni, nj);
}



int main(){
    QueenTwo(4, 1, "", 0, 0);
}