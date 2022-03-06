#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void Matrix(vector<vector<int>> v1, vector<vector<int>> v2){
    vector<vector<int>> v(v1.size(), vector<int>(v2[0].size()));
    if(v1.size()!=v2[0].size()){
        cout<<"Dimenssion are not familier to perform operation ";
        return;
    }
    for(int i= 0; i<v.size();i++){
        for(int j = 0; j<v[0].size(); j++){
            for(int k = 0; k<v1.size(); k++){
                v[i][j] += v1[i][k] * v2[k][j]; 
            }
        }
    }
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    int n1, m1, n2, m2;
    cin>>n1>>m1;
    vector<vector<int>>v1(n1, vector<int> (m1));
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<m1; j++){
            cin>>v1[i][j];
        }
    }
    cin>>n2>>m2;
    vector<vector<int>> v2(n2, vector<int> (m2));
    for(int i = 0; i<n2; i++){
        for(int j= 0; j<n2; j++){
            cin>>v2[i][j];
        }
    }
    Matrix(v1, v2);
}