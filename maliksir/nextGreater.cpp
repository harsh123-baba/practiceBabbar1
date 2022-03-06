#include<vector>
#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int> v){
    vector<int> x(v.size());
    stack<int> s;
    s.push(v[v.size()-1]);
    x[v.size()-1] = -1;
    
    for(int i = v.size()-2; i>=0; i--){
        while(s.size()>0 && v[s.top()] <= v[i]){
            s.pop();
        }
        if(s.size()==0){
            x[i] = -1;
        }
        else{
            x[i] = s.top();
        }
        s.push(i);
    }
    return x;
}


int main(){
    // stack<int> s;
    vector<int> v = {5, 8, 2, 3, 4,10, 9, 1, 6, 5};
    vector<int> x = nextGreater(v);
    for(int i = 0; i<v.size(); i++){
        cout<<x[i]<<" ";
    }
}