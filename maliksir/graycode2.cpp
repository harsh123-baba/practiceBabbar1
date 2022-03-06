#include<vector>
#include<iostream>
using namespace std;

vector<string> grayCode(int n){
    if(n==1){
        vector<string>x;
        x.push_back("0");
        x.push_back("1");
        return x;
    }
    vector<string> res = grayCode(n-1);
    vector<string> ans;
    for(int i = 0; i<res.size(); i++){
        string s=res[i];
        ans.push_back("0"+s);
    }
    for(int i = res.size()-1; i>=0; i--){
        string s=res[i];
        ans.push_back("1"+s);
    }

    return ans;
}


int main(){ 

    vector<string> s = grayCode(3);
    for(int i = 0; i<s.size(); i++){
        cout<<s[i]<<endl;
    }
}