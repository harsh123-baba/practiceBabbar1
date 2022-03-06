#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> MergeIntervals(vector<vector<int>> v){
    sort(v.begin(), v.end());
  
    int s = v[0][0];
    int e = v[0][1];
    vector<vector<int>> ans;

    for(int i = 1; i<v.size(); i++){
        if(v[i][0]<=e){
            e = max(v[i][0], e);
        }
        else{
            ans.push_back({s, e});
            s = v[i][0];
            e = v[i][1];
        }
    }
    ans.push_back({s, e});
    return ans;
}


int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = MergeIntervals(intervals);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }

}