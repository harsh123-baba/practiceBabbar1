
// 1. You are given two integers n and k, where n represents number of elements and k  represents number of subsets.
// 2. You have to partition n elements in k subsets and print all such configurations.

#include<iostream>
#include<vector>
using namespace std;

void Kpartition(int n, int k, int i, int nos, vector<vector<int>> ans){
    if(i>n){
        if(nos==k){
            for(vector<int> set:ans){
                cout<<"[";
                for(int i = 0; i<set.size(); i++){
                    cout<<set[i];
                }
                cout<<"]";
            }
            cout<<endl;
        }
        return;
    }
    for(int j = 0; j<ans.size(); j++){
        if(ans[j].size()>0){
            ans[j].push_back(i);
            Kpartition(n, k, i+1, nos, ans);
            ans[j].pop_back();
        }
        else{
            ans[j].push_back(i);
            Kpartition(n, k, i+1, nos+1, ans);
            ans[j].pop_back();
            break;
        }
    }
}

int main(){
    int n = 4;
    int k = 3;
    vector<vector<int>> v(k);
    Kpartition(n, k, 1, 0, v);
}