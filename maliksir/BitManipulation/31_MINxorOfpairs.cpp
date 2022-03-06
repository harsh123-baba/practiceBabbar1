#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    int n=4;
    cin>>n;
    vector<int> v(n);
    // vector<int> v = {0,2, 5,7};

    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    
    int min = INT32_MAX;
    vector<string> s;
    sort(v.begin(), v.end());
    for(int i = 0; i<n-1; i++){
        int x = v[i] ^ v[i+1];
        if(min> x){
            min = x;
            vector<string>s(1);
            s.push_back(to_string(v[i]) + ", " + to_string(v[i+1]));
        }
        else if(x==min){
            s.push_back(to_string(v[i]) + ", " + to_string(v[i+1]));
        }

    }
    for(string str: s){
        cout<<str<<endl;
    }
}
