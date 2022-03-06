#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


void EqualSum(int n, int k, int i, vector<int> v, vector<vector<int>> ans, int ssf, int sum, vector<int> PartSum){
    if(k ==1){
        cout<<"[";
        for(int i = 0; i<v[i]; i++){
            cout<<v[i]<<", ";
        }
        cout<<"]";
    }
    if(k>n){
        cout<<"-1";
    }
    
    if(i==n){
        if(ssf == k){

            bool flag = true;

            for(int i = 0; i<PartSum.size()-1; i++){
                if(PartSum[i] != PartSum[i+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int i = 0; i<ans.size(); i++){
                    cout<<"[";
                    for(int j = 0; j<ans[i].size(); j++){
                        cout<<ans[i][j];
                        if(j!=ans[i].size()-1){
                            cout<<", ";
                        }
                    }
                    cout<<"]";
                }
                cout<<endl;
            }
        }
        return;
    }

    for(int j = 0; j<ans.size(); j++){
        if(ans[j].size()>0){
            ans[j].push_back(v[i]);
            PartSum[i] += v[i];
            EqualSum(n, k, i+1, v, ans, ssf, sum, PartSum);
            PartSum[i] -= v[i];
            ans[j].pop_back();
        }
        else{
            ans[j].push_back(v[i]);
            PartSum[i] += v[i];
            EqualSum(n, k, i+1, v, ans, ssf+1,sum, PartSum);
            PartSum[i] -= v[i];
            ans[j].pop_back();
            break;
        }
    }


}


int main(){
    int n;
    int k;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i =0; i<n; i++){
        cin>>v[i];
        
    }
    for(int i = 0; i<n;i++){
        sum+=v[i];
    }
    cin>>k;
    vector<int>PartSum(k);
    vector<vector<int>> ans(k);
    EqualSum(n, k, 0,  v, ans, 1, sum,PartSum);

}