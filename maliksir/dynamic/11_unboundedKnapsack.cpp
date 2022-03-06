#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

// in 01 knapsack i only have option to not to select him or to select him once but here i an not bounded to take element only once
// i can take this element many times so i can perform duplicacy so i am using combination or permutation algo



//permutation
int solve(vector<int> value , vector<int> weight, int target){
    vector<int> dp (target+1);
    dp[0] = 0;
    for(int bagc = 1; bagc<=target; bagc++){
            int max = 0;
        for(int i=0; i<value.size(); i++){
            if(weight[i] <= bagc){
                int remainBagc = bagc-weight[i];
                int remainBagv = dp[remainBagc];
                int totalbagV =  remainBagv+value[i];
                if(totalbagV > max){
                    max = totalbagV;
                }
            }
        }
        dp[bagc] = max;
    }
    return dp[target];
}

int main(){
    int n;
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i = 0; i<n; i++){
        cin>>value[i];
    }
    for(int i = 0; i<n; i++){
        cin>>weight[i];
    }

    int target;
    cin>>target;

    cout<<solve(value, weight, target);

}   