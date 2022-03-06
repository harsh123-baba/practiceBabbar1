
// 1. You are given an array of n distinct integers.
// 2. You have to partition these n integers into k non-empty subsets such that sum of integers of every subset is same.
// 3. If it is not possible to divide, then print "-1".

#include<iostream>
#include<vector>
using namespace std;


void Solution(int n, int k, vector<int> arr, vector<vector<int>> ans, int vidx,int sum, int ssf,vector<int> subsetSum){
    if(k==1){
        for(int i = 0;i<arr.size(); i++){
            cout<<arr[i]<<", ";
        }
    }
    if(k>n || sum%k != 0){
        cout<<"-1";
        return;
    }

    if(vidx == arr.size()){
        if(ssf==k){
            bool flag =true;
            for(int i = 0; i<subsetSum.size()-1; i++){
                if(subsetSum[i]!=subsetSum[i+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(vector<int> set:ans){
                    cout<<"[";
                    for(int j = 0; j<set.size(); j++){
                        cout<<set[j];
                    }
                    cout<<"]";
                }
            }
        } 
        return;
    }
    for(int i= 0; i<ans.size(); i++){
        if(ans[i].size()>0){
            ans[i].push_back(arr[vidx]);
            subsetSum[i] +=arr[vidx];
            Solution(n, k, arr, ans, vidx+1, sum, ssf,subsetSum);
            ans[i].pop_back();
            subsetSum[i] -=arr[vidx];
        }
        else{
            ans[i].push_back(arr[vidx]);
            subsetSum[i]+=arr[vidx];
            Solution(n, k, arr, ans, vidx+1, sum, ssf+1, subsetSum);
            ans[i].pop_back();
            subsetSum[i]-=arr[vidx];
            break;
        }
    }
}


int main(){
    int n=4; 
    int k =3;
    vector<int> arr = {9, 5, 4, 9};
    vector<vector<int>> v;
    vector<int> subsetSum(k);
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum+=arr[i];
    }
    Solution(n, k, arr, v, 1, sum, 0, subsetSum);
    cout<<endl;
}

