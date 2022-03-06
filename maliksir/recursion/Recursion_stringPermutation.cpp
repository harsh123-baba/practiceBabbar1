#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

void StringPermutationhelper(string currans, int t, int c, unordered_map<char, int> m){
    if(c>t){
        // ans.push_back(currans);
        // return ans;
        cout<<currans<<endl;
        return;
    }
    for(auto i = m.begin(); i!=m.end(); i++){
        if(i->second > 0){
            i->second -=1;
            StringPermutationhelper(currans+i->first, t, c+1, m);   
            i->second +=1;
        }
    }
}

void StringPermutation(string s){
    unordered_map<char, int> m;
    for(int i = 0; i<s.size(); i++){
        if(m[s[i]]){
            m[s[i]]++;
        }
        else{
            m[s[i]]=1;
        }
    }

    return StringPermutationhelper("", s.size(), 1, m);
}



int main(){
    string s;
    cin>>s;
    StringPermutation(s);
}