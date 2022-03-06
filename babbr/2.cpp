#include<iostream>
using namespace std;

class MaxMin{
    public:
    int max;
    int min;
};

MaxMin maxMinget(int A[], int n){
    int max = INT32_MIN;
    int min = INT32_MAX;
    MaxMin m;

    for(int i = 0; i<n; i++){
        if(max <= A[i]){
            max = A[i];
        }
        if(A[i] < min){
            min = A[i];
        }
    }
    m.max = max;
    m.min = min;
    return m;
}


int main(){
    int A[] = {100, 124, 4564, 4651, 45121};
    int n = sizeof(A)/sizeof(A[0]);
    MaxMin m = maxMinget(A, n);
    cout<<m.max <<" "<<m.min<<endl;

}