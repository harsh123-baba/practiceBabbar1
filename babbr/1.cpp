#include<iostream>
using namespace std;

void Reverse(int A[], int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        int temp;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
}


int main(){
    int A[] = {1, 2, 3, 4};
    int n  = sizeof(A)/sizeof(int);
    Reverse(A, n);
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
}