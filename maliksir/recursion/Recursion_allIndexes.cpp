#include<iostream>
using namespace std;

int * allindex(int arr[], int n, int x, int idx ,int fsf){
    if(idx == n){
        int ans[fsf];
        return ans;
    }
    if(arr[idx]==x){
        int *ians = allindex(arr, n, x, idx+1, fsf+1);
        ians[fsf] = idx;
        return ians;
    }
    else{
        int *ians = allindex(arr, n, x,idx+1, fsf);
        return ians;
    }
}



int main(){
    int a[] = {1, 2, 3, 3, 2, 4, 2, 4, 5 };
    int *b = allindex(a, 9, 2, 0,0);
    for(int i = 0; i<3; i++){
        cout<<a[i]<<" ";
    }

}