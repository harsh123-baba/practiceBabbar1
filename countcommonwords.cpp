#include<bits/stdc++.h>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string, int> m1;
        int count  = 0;
        for(int i = 0; i<words1.size(); i++){
            if((m1.find(words1[i])!=m1.end())){
                m1[words1[i]]++;
            }
            else{
                m1[words1[i]]=1;
            }
        }
        unordered_map<string, int> m2;
        for(int i = 0; i<words2.size(); i++){
            // if(m2.find(words2[i])!=m2.end()){
            //     m2[words2[i]]++;
            // }
            // else{
            //     m2[words2[i]]=1;
            // }
            if(m1[words2[i]] && m1[words2[i]]==1 && m2.find(words2[i])== m2.end() ){
                m2[words2[i]]=1;
            }
        }
        return m2.size();

        
        // for(auto it :m){
        //     if(it.second == 1){
        //         count++;
        //     }
        // }



        // return count;
    }


int main(){
    vector<string> words1 = {"leetcode","is","amazing","as","is"};
    vector<string> words2 ={"amazing","leetcode","is"};
    cout<<countWords(words1, words2);
}


// ["leetcode","is","amazing","as","is"]
// ["amazing","leetcode","is"]
// ["b","bb","bbb"]
// ["a","aa","aaa"]