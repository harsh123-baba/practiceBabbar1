#include<bits/stdc++.h>
using namespace std;
// vector<int> getAverages(vector<int>& nums, int k) {
//     vector<int> v;
//     int n = nums.size();
//     int avgSum = 0;
//     for(int i = 0; i<k; i++){
//         v.push_back(-1);
        
//     }
//     // for(int i = 0;i<n-2k; i++){
        
//     // }
//     for(int i = k; i<n-k; i++){
//         avgSum += nums[i];
//         int x = avgSum-nums[i-k];

//         for(int j = 1; j<=k; j++){
//             avgSum +=nums[i+j];
//         }
//         int avg =avgSum/(2*k+1);
//         v.push_back(avg);
//         avgSum = x;
//     }
//     for(int i = n-k; i<n; i++){
//         v.push_back(-1);
//     }
//     return v;
// }

vector<int> getAverages(vector<int>& nums, int k) {
    vector<int> ans(nums.size(), -1);
    int n = nums.size();
    if(2*k+1 > n){
        return ans;
    }
    long long int sum = 0;
    for(int i = 0; i<2*k+1; i++){
        sum+=nums[i];
    }
    ans[k] = sum/(2*k+1);
    for(int i = 2*k+1, j = k+1, s=0; i<n; i++, j++, s++){
        sum +=nums[i];
        sum -= nums[s];
        ans[j] = sum/(2*k+1);
    }
    return ans;

}


int main(){
    vector<int> v = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    vector<int> ans = getAverages(v, k);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}