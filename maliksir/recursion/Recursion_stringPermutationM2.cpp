#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

void StringPermutationM2(string s, int cc, vector<char> spots, unordered_map<char, int> lo){
    if(cc== s.size()-1){
        for(int i =0; i<spots.size(); i++){
            cout<<spots[i];
        }
        cout<<endl;
        return;
    }
    char ch = s[cc];
    int last = lo[ch];
    for(int i = last+1; i<spots.size(); i++){
        if(spots[i]=='\0'){
            spots[i]=ch;
            lo[ch] = i;
            StringPermutationM2(s, cc+1, spots, lo);
            lo[i]= last;
            spots[i] = '\0';

        }
    }

}

int main(){
    unordered_map<char, int> lo;
    string s= "abba";
    vector<char>spots(s.size());
    for(int  i = 0; i<s.size(); i++){
        lo[s[i]] = -1;
    }
    StringPermutationM2(s, 0, spots, lo);
}