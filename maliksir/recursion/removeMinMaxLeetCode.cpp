// 2091. Removing Minimum and Maximum From Array

// You are given a 0-indexed array of distinct integers nums.

// There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

// A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

 

// Example 1:

// Input: nums = [2,10,7,5,4,1,8,6]
// Output: 5
// Explanation: 
// The minimum element in the array is nums[5], which is 1.
// The maximum element in the array is nums[1], which is 10.
// We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
// This results in 2 + 3 = 5 deletions, which is the minimum number possible.


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int max1 = INT32_MIN;
        int iMax = -1;
        int min1 = INT32_MAX;
        int iMin = -1;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(min1 > nums[i]){
                min1 = nums[i];
                iMin = i;
            }
            if(max1<nums[i]){
                max1 = nums[i];
                iMax  = i;
            }
        }
        
        int l = min(iMin, iMax);
        int r = max(iMin, iMax);
        
        int minDel = INT32_MAX;
    // delete element from left and right also
        
        minDel = min(minDel , ((l+1)+(n-r)));
        //from right
        
        minDel = min(minDel , n-l);
        // from left;
        minDel = min(minDel, r+1);
        
        return minDel;
        
    }

int main(){



}