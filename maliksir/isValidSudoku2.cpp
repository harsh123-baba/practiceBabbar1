
#include<vector>
#include<iostream>
using namespace std;

int isValid(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j]==0){
                continue;
            }
            else{
                int a = (i/3)*3;
                int b = (j/3)*3;
                int count = 0;
                
                for(int x = a; x<a+3; x++){
                    for(int y = a; y<b+3; y++){
                        if(v[x][y] == v[i][j]){
                            count++;
                        }
                    }
                }
                if(count>1){
                    return 0;
                }

                for(int x = 0; x<9; x++){
                    if(v[i][x] == v[i][j]){
                        return 0;
                    }
                }
                for(int y = 0; y<9; y++){
                    if(v[y][j]==v[i][j]){
                        return 0;
                    }
                }
                
            }
        }
    }
    return 1;
}




int main(){


}