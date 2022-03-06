#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


unordered_map<int, int> duplicates(vector<int> v){
    unordered_map<int, int> m;
    for(int i = 0; i<v.size(); i++){
        if(m[v[i]]){
            m[v[i]]++;
        }
        else{
            m[v[i]]=1;
        }
    }
    return m;
}

int main(){
    vector<int> v  = {1, 2, 2, 2, 3, 4, 4, 4, 4};
    // int n = sizeof(A)/sizeof(int);
    unordered_map<int,int> m =  duplicates(v);
    unordered_map<int, int> :: iterator it = m.begin();
    for(it = m.begin(); it!=m.end(); it++){
        if(it->second > 1){
            cout<<it->first<<endl;
        }
    }
   
}