#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int MaxRActangle(vector<int> v){
    int n = v.size();
    vector<int> rb(n);
    stack<int> s;
    s.push(n-1);
    rb[n-1] = n; 
    for(int  i = n-2; i>=0; i--){
        while(s.size()>0 && v[i] < v[s.top()]){
            s.pop();
        }
        if(s.size()==0){
            rb[i] = n;
        }
        else{
            rb[i] = s.top();
        }
        s.push(i);
    }

    vector<int> lb(n);
    stack<int> s1;
    s1.push(0);
    lb[0] = -1;
    for(int i = 1; i<n; i++){
        while(s1.size()!=0 && v[i] <v[s1.top()]){
            s1.pop();
        }
        if(s1.size()==0){
            lb[i] = -1;
        }
        else{
            lb[i]=s1.top();
        }
        s1.push(i);
        
    }
    
    // for(int i = 0; i<n; i++){
    //     cout<<lb[i] << " "<<rb[i]<<endl;
    // }


    int maxArea=0;
    for(int i = 0; i<n; i++){
        int width = rb[i]-lb[i]-1;
        // cout<<width<<endl;
        int area = width*v[i];
        if(area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}


int main(){
    vector<int> v= {6, 2, 5, 4, 5, 1, 6};
    cout<<MaxRActangle(v);

}