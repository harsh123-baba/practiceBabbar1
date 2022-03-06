#include<vector>
#include<iostream>
using namespace std;

//permutation is solved using combination theory;

void QueneOneUsingCombination(int tq, int cq, int row, int col, string asf, vector<bool> queen){
    if(row==tq){
        if(cq==tq){
        cout<<asf<<endl;
        }
        return;
    }
    int ni= 0;
    int nj=0;
    string sep = "\0";
    if(col==tq-1){
        ni = row+1;
        nj=0;
        sep = "\n";
    }
    else{
        ni=row;
        nj= col+1;
        sep=" ";
    }
    for(int i = 0; i<tq; i++){
        if(queen[i]==false){
            queen[i]= true;
            QueneOneUsingCombination(tq, cq+1, ni, nj, asf+"q"+to_string(i+1)+sep, queen);
            queen[i]= false;
        }
    }
    QueneOneUsingCombination(tq, cq, ni, nj, asf+"-"+sep, queen);
}


int main(){
    vector<bool> q(2, false);
    QueneOneUsingCombination(2, 0, 0, 0, "" , q);

}