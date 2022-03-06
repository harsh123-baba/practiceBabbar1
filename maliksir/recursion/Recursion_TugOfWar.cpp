#include<bits/stdc++.h>
#include<iostream>
using namespace std;

static int mindiff = INT32_MAX;
string ans = "";
void TugOfWar(vector<int> arr, int sumSet1, int sumSet2, vector<int> set1, vector<int> set2, int vidx){
    if(vidx==arr.size()){
        int delta = abs(sumSet1-sumSet2);
        if(mindiff > delta){
            mindiff = delta;
            // ans = to_string(sumSet1)+"-"+to_string(sumSet2); 
            // cout<<ans<<endl;
            cout<<sumSet1<<"- "<<sumSet2<<endl;
        }

        return;
    }
    if(set1.size() < (arr.size()+1)/2){
        set1.push_back(arr[vidx]);
        TugOfWar(arr, sumSet1+arr[vidx], sumSet2, set1, set2, vidx+1);
        set1.pop_back();
    }
    if(set2.size() < (arr.size()+1)/2){
        set2.push_back(arr[vidx]);
        TugOfWar(arr, sumSet1, sumSet2+arr[vidx], set1, set2, vidx+1);
        set2.pop_back();
    }

}




int main(){
    vector<int> v = {1,2,3,4,5,6};
    int n = v.size();
    vector<int> set1((n+1)/2);
    vector<int> set2((n+1)/2);
    TugOfWar(v, 0, 0, set1, set2, 0);
    // cout<<ans;
}