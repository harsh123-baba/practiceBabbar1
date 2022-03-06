#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<stdio.h>
using namespace std;

const  int rowMatrix = 9;
const int colMatrix = 9;

bool isValidRow(int A[rowMatrix][colMatrix], int n){
    set<int> s;
    for(int i = 0; i<9; i++){
        if(s.find(A[i][n]) != s.end()){
            return false;
        }
        if(A[i][n] !=0){
            s.insert(A[i][n]);
        }
    }
    return true;
}

bool isValidCol(int A[rowMatrix][colMatrix], int m)
{
    set<int> s;
    for(int i = 0; i<9; i++){
        if(s.find(A[m][i])!=s.end()){
            return false;
        }
        if(A[m][i] != 0){
            s.insert(A[m][i]);
        }
    }
    return true;
}


bool isValidBox(int A[rowMatrix][colMatrix], int n , int m){
    set<int>s;
    for(int i = 0; i<3; i++){
    
        for(int j = 0; j<3; j++){
            if(s.find(A[i+n][j+m]) != s.end()){
                return false;
            }
            if(A[i+n][j+m]!=0){
                s.insert(A[i+n][j+m]);
            }
        }

    }
    return true;
}


bool isValidhelper(int A[rowMatrix][colMatrix], int row, int col){
    int r = (row /3)*3;
    int c = (col/3)*3;
    return isValidRow(A, row) && isValidCol(A, col) && isValidBox(A, r, c);
}

bool isValid( int A[rowMatrix][colMatrix]){
    for(int i = 0; i<rowMatrix; i++){
        for(int j = 0; j<colMatrix; j++){
            if(isValidhelper(A, i, j)==false){
                return false;
            }
        }
    }
    return true;
}

int main(){
// int **A = new int*[9];
// for(int i = 0; i<9; i++){
//     A[i] = new int[9];
// }
int A[][9]= {
{3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0}
};
cout<<isValid(A);
}