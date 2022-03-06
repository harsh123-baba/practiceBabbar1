#include<iostream>
using namespace std;
#include<vector>

int LargestSum(vector<int> v){
    int maxSumHere = v[0];
    int maxSoFar = v[0];
    for(int i =1; i<v.size(); i++){
        maxSumHere = max(maxSumHere , maxSumHere+v[0]);
        maxSoFar = max(maxSoFar, maxSumHere);
    }
    return maxSoFar;
}


int main(){
    vector<int> A = {3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3 , 1, -5, 4};
    // int n = sizeof(A)/sizeof(int);
    int x = LargestSum(A);
    cout<<x<<endl;
}


