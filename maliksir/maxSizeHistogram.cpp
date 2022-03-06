#include<stack>
#include<vector>
#include<iostream>
using namespace std;

int maxAreaHistogram(vector<int> v){
    vector<int> rb(v.size());
    stack<int> srb;
    srb.push(v.size()-1);
    rb[v.size()-1] = v.size();
    for(int i = v.size()-2; i>=0; i--){
        while(srb.size()!=0 && v[i] < v[srb.top()]){
            srb.pop();
        }
        if(srb.size()==0){
            rb[i] = v.size();
        }
        else{
            rb[i] = srb.top();
        }
        srb.push(i);
    }
    
    
    vector<int> lb(v.size());
    stack<int> slb;
    slb.push(-1);
    lb[0] = -1;
    for(int i = 1; i<v.size(); i++){
        while(slb.size()!=0 && v[i] < v[slb.top()]){
            slb.pop();
        }
        if(slb.size()==0){
            lb[i]=-1;
        }
        else{
            lb[i] = slb.top();
        }
        slb.push(i);
    }
    
    int maxarea = 0;
    for(int i = 0; i<v.size()-1; i++){
        int width = rb[i]-lb[i];
        int area = width* v[i];
        if(area > maxarea){
            maxarea = area;
        }
    }
return maxarea;
}





int main(){

}