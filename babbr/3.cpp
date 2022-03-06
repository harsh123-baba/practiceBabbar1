// kth smallest;
#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int A[], int n,int k){
    priority_queue<int> q;
    for(int i = 0; i<n; i++){
        q.push(A[i]);
        if(q.size()>k){
            q.pop();
        }
    }
    return q.top();
}



int main(){
    int A[] = {2,6, 3, 4, 5 , 9, 10};
    int n = sizeof(A)/sizeof(n);
    cout<<kthSmallest(A, n, 3);
}
