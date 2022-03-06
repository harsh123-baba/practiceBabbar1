#include<stack>
#include<vector>
#include<iostream>
using namespace std;

// void slidingWindow(vector<int> v, int k){
//     vector<int> nextGreater(v.size());
//     stack<int> s;
//     s.push(v.size()-1);
//     nextGreater[v.size()-1] = v.size();
//     for(int i = v.size()-2; i>=0; i--){
//         while(s.size()>0 && v[i] >= v[s.top()]){
//             s.pop();
//         }
//         if(s.size()==0){
//             nextGreater[i] = v.size();
//         }
//         else{
//             nextGreater[i] = s.top();
//         }
//         s.push(i);
//     }
//     for(int i = 0; i<v.size();i++){
//         cout<<nextGreater[i]<<" ";
//     }
//     cout<<endl;

//     int j = 0;
//     for(int i = 0; i<=v.size()-k; i++){
//         if(j<i){
//             j = i;
//         }
//         while(nextGreater[j] < i+k){
//             j= nextGreater[j];
//         }
//         cout<<v[j]<<"\n";
//     }

// }

vector<int> slidingWindow(vector<int> arr, int n, int k) {
        // your code here
    stack<int> s;
    vector<int> res(n);
    s.push(n-1);
    res[n-1] = n;
    for(int i = arr.size()-2; i>=0; i--){
        while(s.size()!=0 && arr[i] > arr[s.top()]){
            s.pop();
        }
        if(s.size()==0){
            res[i] = n;
        }
        else{
            res[i] = s.top();
        }
        s.push(i);
    }
//   return result;
    
    int j = 0;
    // vector<int> res = nextGreater(arr, n);
    vector<int> ans;
    for(int i = 0; i<=n-k; i++){
        if(j<i){
            j = i;
        }
        while(res[j]<i+k){
            j=res[j];
        }
        ans.push_back(arr[j]);
    }
    return ans;
        
}


int main(){
    // vector<int> v = {2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
    vector<int> v = {1 ,2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> x = slidingWindow(v,v.size(), 3);
    for(int i = 0; i<x.size(); i++){
        cout<<x[i]<<endl;
    }

}