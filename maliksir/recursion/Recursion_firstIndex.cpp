
#include<iostream>
using namespace std;

int firstIndex(int arr[], int n, int idx, int x){
    if(idx == n){
        return -1;
    }
    if(arr[idx]==x){
        return idx;
    }
    int index = firstIndex(arr, n, idx+1, x);
    return index;
}   


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 3, 4, 5};
    cout<<firstIndex(arr, 9, 0, 5);
}