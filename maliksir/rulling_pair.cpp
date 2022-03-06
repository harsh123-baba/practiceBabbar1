#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int getDigitSum(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n= n/10;
    }
    return sum;
}


int RullingPair(vector<int> v){
    int maximum = -1;
    unordered_map<int,int> m;
    
    for(int i = 0; i<v.size(); i++){
        int s = getDigitSum(v[i]);
        if(m.find(s)!=m.end()){
            int curr = m.at(s);
            maximum =  max(maximum, curr+v[i]);
            if(v[i]>curr){
                m[s] = v[i];
            }
            // int sum = curr+v[i];
        }
        else{
            m[s]=v[i];
        }
    }
        return maximum;

}



int main(){
    vector<int> v = {55, 23, 32, 46, 88};
    cout<<RullingPair(v);

}