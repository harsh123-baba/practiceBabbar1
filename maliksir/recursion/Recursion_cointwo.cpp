#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int amnt, int tamnt, vector<int>v, string asf, int cc){
    // if(amnt> tamnt){
    //     return;
    // }

    if(cc==v.size()){
        if(amnt == tamnt){
            cout<<asf<<".\n";
  
            
        }   
              return;

    }
    
    
    for(int i = tamnt/v[cc]; i>=1; i--){
        string path = "";
        for(int k = 0; k<i; k++){
            path += to_string(v[cc])+"-";
        }
        solve(amnt+v[cc]*i, tamnt, v, asf+path, cc+1);
    }
    solve(amnt, tamnt, v, asf, cc+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n; i++){
        cin>>v[i];
    }
    int t;
    cin>>t;
    solve(0, t, v, "", 0);
}