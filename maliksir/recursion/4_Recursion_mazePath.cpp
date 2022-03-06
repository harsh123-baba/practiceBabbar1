#include<iostream>
#include<vector>
using namespace std;

vector<string> MazePath(int sr, int sc, int dr, int dc){
    if(sr==dr && sc == dc){
        vector<string> s;
        s.push_back("");
        return s;
    }
    vector<string> hpath;
    vector<string> vpath;
    if(sr<dr){
        vpath = MazePath(sr+1, sc, dr, dc);
    }
    if(sc < dc){
        hpath = MazePath(sr, sc+1, dr, dc);
    }
    vector<string> path;
    for(string x:hpath){
        path.push_back("h"+x);
    }
    for(string x:vpath){
        path.push_back("v"+x);
    }
    return path;
}



int main(){
    vector<string> v = MazePath(0, 0, 2, 2);
    for(string x: v){
        cout<<x<<endl;
    }
}