#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums, int k) {
    unordered_map<int,int> a;
    for(int i:nums)
        a[i]++;
    int ans=0;
    for(auto x:a)
    {
        if(k==0)
        {    
            if(x.second>1)
                ans++;
        }
            else if(a.find(x.first+k)!=a.end())
                ans++;
    }
    
    return ans;
}


int main(){
    int n;
    // cin>>n;
    vector<int> nums = {3,1,4,1,5};
    // for(int i = 0; i<n; i++){
    //     cin>>v[i];
    // }
    int k = 2;
    cout<<findPairs(nums, k);

}