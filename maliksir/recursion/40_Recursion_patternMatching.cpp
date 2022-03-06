// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// //output pattern
// void PatternMatching(string s, string pattern, unordered_map<char, string> map, string op){
//     cout<<"Hii";
//     if(pattern.size()==0){
//         if(s.size()==0){
//             unordered_set<char> set;
//             for(int i = 0; i<op.size(); i++){
//                 char ch = op[i];
//                 if(set.find(ch) != set.end()){
//                     cout<<ch<<"->"<<map[ch];
//                     set.insert(ch);
//                 }
//             }  
//             cout<<endl; 
//         }
//     }

//     char ch = pattern[0];
//     string rop = pattern.substr(1);

    
//     if(map.find(ch)!= map.end()){
//         string prevMapping = map[ch];
//         if(s.size() >= prevMapping.size()){
//             string left = s.substr(0, prevMapping.size());
//             string right = s.substr(prevMapping.size());
//             if(left==prevMapping){
//                 PatternMatching(right, rop, map, op);
//             }
//         }
//     }
//     else{
//         for(int i = 0; i<s.size(); i++){
//             string left = s.substr(0, i+1);
//             string right = s.substr(i+1);
//             map[ch] = left;
//             PatternMatching(right, rop, map, op);
//             map.erase(ch);
//         }
//     }
// }

// int main(){
//     unordered_map<char, string> map;
//     PatternMatching("hph", "pep", map, "pep");

// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// static int count = 1;

void Solution(string s, unordered_map<char, string> map, string op, string pattern){
    cout<<"hi"<<endl;
    if(pattern.size()==0){
        if(s.size()==0){
            unordered_set<char> set;
            for(int i = 0; i<op.size(); i++){
                char ch = op[i];
                if(set.find(ch)!=set.end()){
                    cout<<ch<<"->"<<map[ch];
                    set.insert(ch);
                }
            }
        }
    }

    char ch = pattern[0];
    string rop = pattern.substr(1);
    for(int i = 0; i<s.size(); i++){
        if(map.find(ch)!= map.end()){
            string prevMapping = map[ch];
            if(prevMapping.size() <= s.size()){
                string left = s.substr(0, prevMapping.size());
                string right = s.substr(prevMapping.size());
                if(left == prevMapping){
                    Solution(right, map,op, rop);
                }
            }
        }
        else{
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);
            map[ch] = left;
            Solution(right, map, op, rop);
            map.erase(ch);
        }
    } 
}

int main(){
    unordered_map<char, string> map;
    Solution("mzaddytzaddy", map, "abcb", "abcb");

}
