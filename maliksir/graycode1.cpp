#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> grayCode(int n){
    if(n==1){
        vector<string> x;
        x.push_back("0");
        x.push_back("1");
        return x;
    }
    vector<string> ans = grayCode(n-1);
    vector<string>ansfinal;
    for(int i = 0; i<ans.size(); i++){
        string s=ans[i];
        ansfinal.push_back("0"+s);
    }
    for(int i = ans.size()-1; i>=0; i--){
        string s=ans[i];
        ansfinal.push_back("1"+s);
    }
    return ansfinal;

}

int main(){
    vector<string> s = grayCode(3);
    for(int i = 0; i<s.size(); i++){
        cout<<s[i]<<endl;
    }
}