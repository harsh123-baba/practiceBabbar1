#include<vector>
#include<iostream>
using namespace std;

const int row = 9;
const int col = 9;




bool isValid(int A[row][col]){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(A[i][j]==0){
                continue;
            }
            else{

                int a = (i/3)*3;
                int b = (j/3)*3;
                int count =0;
                for(int x = a; x<(a+3);  x++){
                    for(int y = b; y<(b+3); y++){
                        if(A[i][j] == A[x][y]){
                            count++;
                        }
                    }
                }
                if(count>1){
                    return 0;
                }

                for(int x = 0; x<9; x++){
                    if(A[i][j] == A[i][x]){
                        count++;
                    }
                }
                if(count>2){
                    return 0;
                }
                for(int x = 0; x<9; x++){
                    if(A[i][j] == A[x][j]){
                        count++;
                    }
                }
                if(count>3){
                    return 0;
                }
            }
        }
    }
    return 1;
} 



int main(){
    int A[][9] = {
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