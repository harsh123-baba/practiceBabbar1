#include<bits/stdc++.h>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;


int getNum(string s, unordered_map<char, int> map){
    string num = "";   
    for(int i = 0; i<s.size(); i++){
        num+=to_string(map[s[i]]);
    }
    int x = stoi(num);
    // cout<<x<<endl;    
    // cout<<num<<endl;
    return x;
}



void CryptoArithmetic(vector<bool>used, unordered_map<char,int> map,string s, int idx, string s1, string s2, string s3){
    if(idx==s.size()){
        int num1 = getNum(s1, map);
        int num2 = getNum(s2,map);
        int num3 = getNum(s3, map);

        if(num1+num2 == num3){
            // cout<<num1<< " "<<num2<< " "<<num3<<endl;
            for(char ch = 'a'; ch<'z'; ch++){
                // char ch =(char) ('a'+i);
                if(map.find(ch)!= map.end()){
                    cout<<ch<<"-" << map[ch]<<" ";
                }   
            }
            cout<<endl;
            
        }
        // cout<<idx<<endl;
        return;
    }
    char ch = s[idx];
    for(int num = 0; num<=9; num++){
        if(used[num]==false){
            used[num]=true;
            map[ch]= num;
            CryptoArithmetic(used, map, s, idx+1, s1, s2, s3);
            used[num] = false;
            map[ch] = -1;
        }
    }
}   


int main(){
    vector<bool> used(10, false);
    unordered_map<char, int> m;
    string s1 = "team";
    string s2 = "pep";
    string s3 = "toppr";
    string uq = "";
    for(int i = 0; i<s1.size(); i++){
        if(m.find(s1[i])!= m.end()){
            continue;
        }
        else{
            m[s1[i]]=-1;
            uq += s1[i];
        }
    }
    for(int i = 0; i<s2.size(); i++){
        if(m.find(s2[i])!= m.end()){
            continue;
        }
        else{
            m[s2[i]]=-1;
            uq += s2[i];
        }
    }
    for(int i = 0; i<s3.size(); i++){
        if(m.find(s3[i])!= m.end()){
            continue;
        }
        else{
            m[s3[i]]=-1;
            uq += s3[i];
        }
    }
    // cout<<uq;
    CryptoArithmetic(used, m, uq, 0, s1, s2, s3);
    // getNum("more", m);
}