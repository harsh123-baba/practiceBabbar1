#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// boxchooses means permutation

void BoxChooses(int ssf, int t, int row, int col, vector<bool>&queen ,string asf){
    if(row == t){
        if(ssf == t){
            cout<<asf<<endl;
        }
            return;
    }
    
    int ni = 0;
    int nj = 0;
    char sep = '\0';
    if(col == t-1){
        ni = row + 1;
        nj = 0;
        sep = '\n';
    }
    else{
        ni = row;
        nj = col + 1;
        sep = '\t';
    }

    for(int i = 0; i<queen.size(); i++){
        if(queen[i] == false){
            queen[i] = true;
            BoxChooses(ssf+1, t, ni, nj, queen, asf +"q"+to_string(i+1) + sep);
            queen[i] = false;
        }
    }
    BoxChooses(ssf, t, ni, nj, queen, asf+ "-" + sep);
}


int main(){
    int n;
    cin>>n;
    vector<bool> queen(n);
    BoxChooses(0, n, 0, 0, queen, "");
}