#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


void NextPermutation(vector<int>& v){
    int index1 = -1;
    for(int i = v.size()-2; i>=0; i--){
        if(v[i] < v[i+1]){
            index1 = i;
            break;
        }
    }
    if(index1 < 0){
        reverse(v.begin(), v.end());
    
    }
    else{
        int index2= 0;
        for(int i = v.size()-1;i>=0 ;i--){
            if(v[i]>v[index1]){
                index2 = i;
                break;
            }
        }
        swap(v[index1], v[index2]);
        reverse(v.begin()+index1+1, v.end());
    }
    
}


int main(){
    vector<int> v = {1, 2, 5, 3, 4};
    NextPermutation(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

}