#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

// can jump kth steps together
int minDiffMaxHeight(vector<int> v, int k){
    sort(v.begin(), v.end());
    int minDiffrence = INT32_MAX;
    for(int i = k; i<v.size(); i++){
        int minD = min(v[0]+k, v[i+1]-k);
        int maxD = max(v[i+1]+k, v[v.size()-1]-k);
        minDiffrence = min(minDiffrence, (maxD-minD));

    }
    return minDiffrence;
}

int main(){
    vector<int> x = {1, 5, 8, 10};
    // int n = sizeof(A)/sizeof(int);
    cout<<minDiffMaxHeight(x, 2);

}