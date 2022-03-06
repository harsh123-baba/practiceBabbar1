#include<vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> MaxSum(vector<int> v, int k){
    int n = v.size();
    stack<int> s;
    vector<int>x(n);
    x[n-1] = n;
    s.push(n-1); 
    for(int i = n-2; i>=0; i--){
        while(s.size()!=0 && v[i] > v[s.top()]){
            s.pop();
        }
        if(s.size()==0){
            x[i] = n;      
        }
        else{
            x[i] = s.top();
        }
        s.push(i);
    }

    vector<int> ans ;
    for(int i = 0; i<=n-k; i++){
        if(x[i] < i+k){
            
        }
    }

}



int main(){

}