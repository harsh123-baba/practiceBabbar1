#include<vector>
#include<iostream>
using namespace std;


vector<string> MazePath(int sr, int sc, int dr, int dc){
    if(sr== dr && sc == dc){
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> paths;

    // horizontal moves;
    for(int ms = 1; ms<=dc-sc ; ms++){
        vector<string> hpaths = MazePath(sr, sc+ms, dr, dc);
        for(string x:hpaths){
            paths.push_back("h"+to_string(ms)+x);
        }
    }

    //vertical moves
    for(int ms = 1; ms <= dr-sr; ms++){
        vector<string> vpath = MazePath(sr+ms, sc, dr, dc);
        for(string x: vpath){
            paths.push_back("v"+to_string(ms)+x);
        }
    }

    // digonal paths
    for(int ms =1; ms<= dr-sr && ms <=dc-sc; ms++){
        vector<string> dpath = MazePath(sr+ms , sc+ms, dr, dc);
        for(string x:dpath){
            paths.push_back("d"+to_string(ms)+x);
        }
    }
    return paths;
}



int main(){
    vector<string> v = MazePath(1, 1, 3, 3);
    for(string x:v){
        cout<<x<<endl;
    }

}