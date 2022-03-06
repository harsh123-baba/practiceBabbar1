// 1. You are given an array of numbers.
// 2. All numbers occur twice in the array except one.
// 3. You have to find that number by traversing only once in the array and without using any extra space.

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    vector<int> v = {10,20, 20, 10, 12};
    int x=v[0];
    for(int i = 1; i<v.size(); i++){
        x = x^v[i];
    }
    cout<<x;
}


