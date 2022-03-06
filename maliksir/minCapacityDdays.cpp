#include<iostream>
using namespace std;

bool isPossible(int A[], int n, int d, int mid){
    int day =1;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=A[i];
        if(sum>mid){
            sum = A[i];
            day++;
        }
    }
    return day<=d;
}

int minCapacity(int A[], int n, int d){
    int max = INT32_MIN;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=A[i];
        if(max<A[i]){
            max = A[i];
        }
    }
    int low = max;
    int high = sum;
    int ans = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(A, n, d, mid)==true){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}


int main(){
    // int A[] = {2, 3, 4, 1, 5, 6, 7, 9, 8, 10};
    // int A[] = {1, 2, 1};
    int A[] = {9, 8, 10};

    int n = sizeof(A)/sizeof(int);
    int d = 3;
    cout<<minCapacity(A, n, d);


}