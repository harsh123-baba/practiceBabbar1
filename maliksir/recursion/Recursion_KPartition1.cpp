#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int c = 1;
void Kpartition(int n, int k, int ssf, int i, vector<vector<int>> v){
    if(i==n){
        if(ssf==k){
            cout<<c<<". ";
            c++;
            
            for(int i =0; i<v.size(); i++){
                
                cout<<"[";
                for(int j = 0; j<v[i].size(); j++){
                    cout<<v[i][j];
                    if(j!=v[i].size()-1){
                        cout<<", ";
                    }
                }  
                cout<<"] ";
            }
            cout<<endl;
        }
        return;
    }


    for(int j = 0; j<v.size(); j++){
        if(v[j].size()>0){
            v[j].push_back(i);
            Kpartition(n, k , ssf, i+1, v);
            v[j].pop_back();
        }
        else{
            v[j].push_back(i);
            Kpartition(n, k, ssf+1, i+1, v);
            v[j].pop_back();
            break;
        }
    }
}



int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>>v(k);
    Kpartition(n, k, 0, 1, v);

}