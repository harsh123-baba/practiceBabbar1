#include<vector>
#include<iostream>
using namespace std;

bool isSafe(vector<vector<bool>> v, int i, int j){
    if(i-1>=0 && j-2>=0 && v[i-1][j-2]){
        return false;
    }
    if(i-2>=0 && j-1>=0 && v[i-2][j-1]){
        return false;
    }if(i-2>=0 && j+1<v.size() && v[i-2][j+1]){
        return false;
    }if(i-1>=0 && j+2<v.size() && v[i-1][j+2]){
        return false;
    }if(i+1<v.size()  && j+2<v.size()  && v[i+1][j+2]){
        return false;
    }
    if(i+2<v.size()  && j+1<v.size()  && v[i+2][j+1]){
        return false;
    }

    if(i+2<v.size()  && j-1>=0  && v[i+2][j-1]){
        return false;
    }
    if(i+1<v.size()  && j-2>=0  && v[i+1][j-2]){
        return false;
    }
    return true;
}



void Nknight(vector<vector<bool>> v,int t, int o,  int lc){
    if(t==o){
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v.size(); j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;

    }
    for(int i = lc+1; i<v.size()*v.size();i++){
        int r = i/v.size();
        int c = i%v.size();
        if(v[r][c]==false && isSafe(v, r, c)){
            v[r][c]= true;
            Nknight(v, t, o+1, r*v.size()+c);
            v[r][c]= false;
        }
    }
}


int main(){
    vector<vector<bool>> v(3, vector<bool> (3, false));
    Nknight(v, 3, 0, -1);
}