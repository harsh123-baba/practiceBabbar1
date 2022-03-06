#include<iostream>
using namespace std;

int lastIndex(int arr[], int n, int idx, int x){
    if(idx == n){
        return -1;
    }
    int index = lastIndex(arr, n, idx+1, x);
    if(index == -1){
        if(arr[idx] == x){
            return idx;
        }
        else{
            return -1;
        }
    }
    else{
        return index;
    }
}

int main(){
    int arr[] = {1, 2, 2, 2, 2, 2, 2, 5, 5, 7};
    int n = sizeof(arr)/sizeof(int);
    cout<<lastIndex(arr,n, 0, 2);
}