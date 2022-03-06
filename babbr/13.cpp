#include<vector>
#include<iostream>
using namespace std;

long long KadaneAlgo(vector<int> v){
    long long maxSumHere = v[0];
    long long maxSofar = v[0];
    for(int i=1; i<v.size(); i++){
        long long x = v[i];
        maxSumHere = max(x, x+maxSumHere);
        maxSofar = max(maxSofar, maxSumHere);
    }
    return maxSofar;
}


int main(){
    vector<int> Arr = {1,2,3,-2,5};
    // int n = sizeof(Arr)/sizeof(Arr[0]);
    cout<<KadaneAlgo(Arr)<<endl;   
}