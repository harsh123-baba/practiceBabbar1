#include<iostream>
#include<vector>
using namespace std;

void Display(vector<vector<int>>v){
    for(int i = 0; i<v.size();i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
// Permutation

void QueneOne(vector<vector<int>>v, int q, int cq){
    if(cq>q){
        Display(v);
        cout<<endl;
        return; 
    }
    for(int i =0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j]==0){
                v[i][j]=cq;
                QueneOne(v, q, cq+1);
                v[i][j]=0;
            }
        }
    }
}


int main(){
    vector<vector<int>>v(3, vector<int>(3, 0));
    QueneOne(v, 3, 1);
}