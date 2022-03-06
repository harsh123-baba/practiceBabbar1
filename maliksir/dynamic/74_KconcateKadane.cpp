#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int concate(vector<int> v, int k){
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i];
    }
    int sumSofar = v[0];
    int sumHere = v[0];
    if(sum < 0){
        for(int i = 1; i<2 * v.size(); i++){
            sumHere = max(v[i % v.size()], v[i % v.size()]+sumHere);
            sumSofar = max(sumHere, sumSofar);
        }
        // return sumSofar;
    }
    else if(k ==1){
        for(int i = 1; i<v.size(); i++){
            sumHere = max(v[i], v[i]+sumHere);
            sumSofar = max(sumHere, sumSofar);
        }
        // return sumSofar;
    }
    else if(sum > 0){
        for(int i = 1; i<2 * v.size(); i++){
            sumHere = max(v[i % v.size()], v[i % v.size()]+sumHere);
            sumSofar = max(sumHere, sumSofar);
        }
        sumSofar = (k-2)*sum + sumSofar;
        // return ans;
    }
    return sumSofar;
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<v.size();i++){
        cin>>v[i];

    }
    int k;
    cin>>k;
    cout<<concate(v, k);

}