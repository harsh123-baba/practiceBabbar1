#include<iostream>
using namespace std;

void TargetSum(int arr[], int n,int idx , string subset, int sos,int target){
    if(idx==n){
        if(sos==target){
            cout<<subset<<endl;
        }
        return;
        // return "";
    }
    TargetSum(arr, n, idx+1, subset+to_string(arr[idx])+", " , sos+arr[idx],target);
    TargetSum(arr, n, idx+1, subset, sos,target);
}


int main(){ 
    int arr[] = {10, 20, 30, 40, 50 };
    TargetSum(arr, 5, 0, "", 0,60);
}