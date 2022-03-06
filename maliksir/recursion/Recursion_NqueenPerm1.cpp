#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>>& v){
    for(int i = 0; i<v.size();i++){
        for(int j = 0; j<v.size(); j++){
            if(v[i][j] > 0){
                cout<<"q"<<v[i][j]<<"\t";
            }
            else{
                cout<<"-\t";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    
}

bool isPossible(vector<vector<int>>& v, int row, int col){
    
    for(int i = row -1 , j= col ; i>=0; i--){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row -1 , j= col+1 ; i>=0 && j < v.size(); i--,j++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row , j= col+1 ;  j < v.size(); j++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row + 1 , j= col+1 ;  j < v.size()&& i < v.size(); i++, j++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row +1 , j= col ;  i < v.size(); i++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row +1 , j= col-1 ; i < v.size()&& j>=0; j--, i++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    
    for(int i = row  , j= col-1 ;  j>=0; j--){
        if(v[i][j] > 0){
            return false;
        }
    }    
    for(int i = row -1 , j= col-1 ; i >=0 && j>=0; j++, i++){
        if(v[i][j] > 0){
            return false;
        }
    }    
    return true;
}

void Nqueen(vector<vector<int>> v, int cq, int tq){
    if(cq > tq){
        Display(v);
        return;
    }

    for(int i = 0; i<v.size() * v.size(); i++){
        int row = i/v.size();
        int col = i%v.size();
        if(v[row][col] == 0 && isPossible(v, row, col)){
            v[row][col] = cq+1;
            Nqueen(v, cq+1, tq);
            v[row][col] = 0;
        }
    }
}

int main(){
    // int n;
    // cin>>n;
    vector<vector<int>>v(4, vector<int>(4, 0));
    Nqueen(v, 0, 4);
}