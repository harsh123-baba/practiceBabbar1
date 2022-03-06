#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

//level pr char
// option mei slot

void WordLen(vector<char> slot, string uq, int idx, int k){
    if(idx==uq.size()){
        if(k==0){
            for(int i = 0; i<slot.size(); i++){
                cout<<slot[i];
            }
            cout<<endl;
        }
        return;
    }
    for(int i = 0; i<slot.size(); i++){
        if(slot[i]=='\0'){
            slot[i] = uq[idx];
            WordLen(slot, uq, idx+1, k-1);
            slot[i] = '\0';
        }
    }
    WordLen(slot, uq, idx+1, k);
}




int main(){
    string s = "abbbaccc";
    unordered_set<char> set;
    int k =2;
    vector<char> slot(2, '\0');
    string uq = "";
    for(int i = 0; i<s.size(); i++){
        if(set.find(s[i])== set.end()){
            set.insert(s[i]);
            uq+=s[i];
        }
    }  
    WordLen(slot, uq, 0, k); 

}