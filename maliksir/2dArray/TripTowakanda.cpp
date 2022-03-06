#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void visit(vector<vector<int>> v){
    int c = 0;
    while(c < v.size()){

    
        for(int i = 0; i<v[0].size(); i++){
            cout<<v[i][c]<<endl;
        }
        c++;
        for(int i = v[0].size()-1; i>=0; i--){
            cout<<v[i][c]<<endl;
        }
        c++;
    }
}


int main(){
    vector<vector<int>> v = {{1, 2}, 
                            {3, 4}};
    visit(v);
}