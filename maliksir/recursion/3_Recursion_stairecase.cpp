#include<vector>
#include<iostream>
using namespace std;

vector<string> StairCase(int n){
    if(n==0){
        vector<string> v;
        v.push_back("");
        return v;
    }
    if(n<0){
        vector<string> v;
        return v;
    }
    vector<string> path1 = StairCase(n-1);
    vector<string> path2 = StairCase(n-2);
    vector<string> path3 = StairCase(n-3);

    vector<string> path;
    for(string x:path1){
        path.push_back("1"+x);
    }
    for(string x:path2){
        path.push_back("2"+x);
    }
    for(string x:path3){
        path.push_back("3"+x);
    }
    
    return path;
}




int main(){
    int n = 4;
    vector<string> v = StairCase(n);
    for(string s : v){
        cout<<s<<endl;
    }
}