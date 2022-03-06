#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i =1 ; i<arr.size(); i++){
            arr[i] = arr[i]^arr[i-1];
        }
        
        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
                int fval = arr[r];
                ans.push_back(fval);
            }
            else{
                int fval = arr[r]^arr[l-1];
                ans.push_back(fval);
            }
        }
        
        return ans;
    }

int main(){
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int> ans = xorQueries(arr, queries);
    for(int i =0 ; i<ans.size(); i++){
            cout<<ans[i]<<endl;
        }
}