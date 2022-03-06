// branch and bound
#include<vector>
#include<iostream>
using namespace std;


void NQueen(vector<vector<bool>> v, vector<bool> cols, vector<bool> digs, vector<bool> digk, int row, string s){
    if(row == v.size()){
        // cout<<s<<endl;
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v.size(); j++){
                cout<<(v[i][j]? "q ":"- ");
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i = 0; i<v.size(); i++){
        if(cols[i]==false && digk[row+i] == false && digs[row-i+v.size()-1]== false){
            v[row][i]= true;
            cols[i] = true;
            digk[row+i] = true;
            digs[row-i+v.size()-1] = true;
            NQueen(v, cols, digs, digk, row+1, s+to_string(row)+"-"+ to_string(i)+" ");
            v[row][i]= false;
            cols[i] = false;
            digk[row+i] = false;
            digs[row-i+v.size()-1] = false;
        }
    }
}

int main(){
    vector<vector<bool>> v(4,vector<bool>(4, false));
    vector<bool> cols(4, false);
    vector<bool> digk(7, false);
    vector<bool> digs(7, false);
    NQueen(v,cols, digs, digk, 0,"");

}