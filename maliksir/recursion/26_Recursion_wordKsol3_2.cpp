#include<unordered_map>
#include<iostream>
using namespace std;

void wordKsol3_2(int k, int idx, string ans, string uq, unordered_map<char, int> map){
    if(k<0){
        return;
    }
    if(idx==uq.size()){
        if(k==0){
        cout<<ans<<endl;

        }
        return;
    }
    char ch = uq[idx];
    if(map[ch]){
        map[ch]-=1;
        wordKsol3_2(k-1, idx,ans+ch, uq, map);
        map[ch]+=1;
    }
    wordKsol3_2(k, idx+1,ans, uq, map);
    

}


int main(){
    unordered_map<char, int> map;
    string s = "aaabbc";
    string uq = "";
    for(int i = 0; i<s.size(); i++){
        if(map[s[i]]){
            map[s[i]]++;
        }
        else{
            map[s[i]]=1;
            uq+=s[i];
        }
    }
    wordKsol3_2(2, 0, "" , uq, map);

}