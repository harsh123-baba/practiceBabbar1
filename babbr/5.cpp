#include<iostream>
#include<algorithm>
using namespace std;

void MoveNegPos(int A[], int n){
    int i= 0;
    int j = n-1;
    while(i<j){
        if(A[i]<0){
            i++;
        }
        if(A[j] > 0){
            j--;
        }
        else{
            swap(A[i], A[j]);
            i++;
            j--;      
        }
    }
}


int main(){
    int A[] = {2,6, -3, -4, -5 , 9, 10};
    int n = sizeof(A)/sizeof(n);
    MoveNegPos(A, n);
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }

}