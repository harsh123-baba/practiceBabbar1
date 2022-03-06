#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    vector<int> v = {1, 3, 2};
    int c = 0;
    for(int i = 0;i<v.size(); i++){
        int x = v[i];
        for(int k = i+1; k<v.size(); k++){
            x = x^v[k];
            if(x == 0){
                c+=(k-i);
            }
        }
    }
    cout<<c;
    
}