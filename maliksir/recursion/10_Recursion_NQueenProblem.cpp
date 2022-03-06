#include<vector>
#include<iostream>
using namespace std;

bool isPossibleSpot(vector<vector<int>>v, int row, int col){
    //vertically hi check krna hoga kyoki ek row m sirf ek hi queen aayegi esa code hm niche chla rhe hai
    for(int i = row-1, j = col; i>=0; i--){
        if(v[i][j]==1){
            return false;
        }
    }
    //digonally (soya hua)
    for(int i =row-1, j=col-1; i>=0&& j>=0; i--, j--){
        if(v[i][j]==1){
            return false;
        }
    }
    //digonally (khda hua)
    for(int i=row-1, j=col+1; i>=0 &&j<v[0].size();i--,j++){
        if(v[i][j]==1){
            return false;
        }
    }
    return true;
}

void Nqueen(vector<vector<int>>v, int row, string s){
    if(row==v.size()){
        cout<<s<<endl;
        return;
    }
    //vertically
    for(int i = 0; i<v.size(); i++){
        if(isPossibleSpot(v, row,i)){
            v[row][i]=1;
            Nqueen(v, row+1, s+to_string(row)+"-"+to_string(i)+". ");
            v[row][i]=0;
        }
    }
    return;
}


int main(){
    vector<vector<int>>v(4, vector<int>(4));
    Nqueen(v, 0, "");
}