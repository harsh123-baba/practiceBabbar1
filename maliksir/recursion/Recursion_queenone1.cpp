#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

// int count = 0;
void queenOne(vector<vector<int>> v, int q){
    if(q==v.size()+1){
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v[0].size(); j++){
                if(v[i][j] > 0){
                    cout<<"q"<<v[i][j]<<"\t";
                }
                else{
                    cout<<"-\t";
                }
            }
            cout<<endl;
        }
        // count = count+1;
        cout<<endl;
    
    }
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j] == 0){
                v[i][j]= q;
                queenOne(v, q+1);
                v[i][j] = 0;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    queenOne(v, 1);
}