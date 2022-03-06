#include<bits/stdc++.h> 
#include<iostream>
#include "graphWt.cpp"
using namespace std;

class Pair{
    public:
    int v;
    string psf;
    int level;


    Pair(int v, string psf, int level){
        this->v = v;
        this->psf = psf;
        this->level = level;

    }
};



bool isBipartite(vector<Edge> graph[], vector<int>& visited , int s){
    // n is already visited size;
    // r m* w a*
    queue<Pair> q;
    q.push(Pair(s, to_string(s), 0));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        if(visited[rem.v] != -1){
            if(visited[rem.v] != rem.level){
                return false;
            }
        }
        else{
            visited[rem.v] = rem.level; 
        }

        for(Edge e : graph[rem.v]){
            if(visited[e.nbr] == -1){
                q.push(Pair(e.nbr, rem.psf + to_string(e.nbr), rem.level+1));
            }   
        }
    }
    return true;
    

}



int main(){
    int n;
    cin>>n;
    int edges;
    cin>>edges;
    vector<int> visited(n, -1);
    vector<Edge> graph[n];

    for(int i = 0; i<edges; i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d, w));
        graph[d].push_back(Edge(d, s, w));
        
    }

    int s=0;
    // cin>>s;

    for(int v = 0; v<n; v++){
        if(visited[v] == -1){
            bool milakya = isBipartite(graph, visited,s);
            if(milakya){
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"False";
}