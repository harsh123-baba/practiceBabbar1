//max sum subarray


#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

int kadane(vector<int> v){
    
    int currSum = v[0];
    int oSum = v[0];
    
    for(int i = 1; i<v.size(); i++){
        currSum = max(v[i], currSum+v[i]);
        oSum = max(currSum, oSum);
    }
    return oSum;
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i= 0; i<n; i++){
        cin>>v[i];
    }
    cout<<kadane(v);

}
