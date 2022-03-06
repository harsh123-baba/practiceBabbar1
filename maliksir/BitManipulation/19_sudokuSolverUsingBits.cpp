#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


void Display(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(vector<vector<int>> v, vector<int> row, vector<int> col,vector<vector<int>> grid,  int i, int j){
    if(i == v.size()){
        // cout<<"hii"<<endl;
        Display(v);
        return;
    }
    if(v[i][j]>0){
        solve(v, row, col,grid,  j==(v[0].size()-1)?i+1:i, j==(v[0].size()-1)?0:j+1);
    }
    else{
        for(int num = 1; num<=9; num++){
            // cout<<i<<endl;
            if(
                ((row[i] & (1<<num))==0)&&
                ((col[j]& (1<<num))==0)&&
                ((grid[i/3][j/3] & (1<<num))==0)
            ){
                v[i][j]= num;
                //toggle operation to on that bit
                row[i] ^= (1<<num);
                col[j] ^=(1<<num);
                grid[i/3][j/3] ^= (1<<num);
                solve(v, row, col, grid,j==(v[0].size()-1)?i+1:i, j==(v[0].size()-1)?0:j+1);
                row[i] ^= (1<<num);
                col[j] ^=(1<<num);
                grid[i/3][j/3] ^= (1<<num);
                v[i][j]=0;
            }
        }
    }
}



int main(){
    vector<vector<int>> v= {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};;
    vector<int> row(9);
    vector<int> col(9);
    vector<vector<int>> grid(3, vector<int>(3));

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            int d = v[i][j];
            row[i] = row[i] | (1<<d);
            col[j] = col[j] | (1<<d);
            grid[i/3][j/3] = (1<<d);
        }
    }

    solve(v, row, col, grid, 0, 0);

}