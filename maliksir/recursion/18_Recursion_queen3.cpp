#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void Combination(vector<vector<int>> v, int cq, int tq, int lc){
    if(cq>tq){
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v[0].size(); j++){
                if(v[i][j]==1){
                    cout<<"q\t";
                }
                else{
                    cout<<"-\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i = lc+1; i<v.size()*v.size(); i++){
        int row = i/v.size();
        int col = i%v.size();
        v[row][col] = 1;
        Combination(v, cq+1, tq, i);
        v[row][col] = 0;
    }
}

int main(){
    vector<vector<int>> v(3,vector<int>(3, 0));
    Combination(v, 1, 3, -1);
}