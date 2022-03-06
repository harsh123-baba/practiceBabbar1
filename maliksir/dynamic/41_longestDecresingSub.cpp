#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    vector<int> lis(n);
    for(int i = 0; i<n; i++){
        int max = 0;
        for(int j = 0; j<i; j++){
            if(v[j] < v[i]){
                if(max < lis[j]){
                    max = lis[j];
                }
            }
        }
        lis[i] = max+1;
    } 

    vector<int> lds(n);
    for(int i = n-1; i>=0; i--){
        int max = 0;
        for(int j = n-1; j > i ; j--){
            if(v[j] <= v[i]){
                if(lds[j] > max){
                    max = lds[j];
                }
            }
        }
        lds[i] = max+1;
    }

    int omax = 0;
    for(int i = 0; i<n; i++){
        int m = lis[i] + lds[i] -1;
        if(m > omax ){
            omax = m;
        }
    }

    cout<<omax;
}

