#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string swap(string s, int i , int j){
    char ith = s[i];
    char jth = s[j];
    string l = s.substr(0, i);
    string m = s.substr(i+1, j);
    string r = s.substr(j+1);

    return l+jth+m+ith+r;

}

// static string maxima=s;
void solution(string s, int k, string maxima){
    if(stoi(maxima) < stoi(s)){
        maxima = s;
    }
    if(k==0){
        cout<<maxima<<endl;

        return;
    }
    for(int i = 1; i<s.size(); i++){
        for(int j = i+1; j<s.size(); j++){
            string swappedString = swap(s, i ,j);
            solution(swappedString, k-1, maxima);

        }
    }
}


int main(){
    string s = "1234567";
    solution(s, 4, s);
    // cout<<maxima;

}