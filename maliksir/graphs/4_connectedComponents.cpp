#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void drawTreeAndGenrateComp(vector<Edge> graph[], vector<bool>& visited, int s, vector<int>& comp){
    visited[s] = true;
    comp.push_back(s);
    for(Edge e: graph[s]){
        if(visited[e.nbr]==false){
            drawTreeAndGenrateComp(graph, visited, e.nbr, comp);
        }
    }
}

int main(){
    int n=2;
    cin>>n;
    vector<Edge> graph[n];

    int edges = 1;
    cin>>edges;
    // graph[0].push_back(Edge(0, 1, 10));
    // graph[1].push_back(Edge(0, 1, 10));
    
    for(int i = 0; i<edges; i++){
        int s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d, w));
        graph[d].push_back(Edge(d, s, w));
    }
    vector<vector<int>> comps;
    vector<bool> visited(n, false);
    for(int v=0; v<n; v++){
        if(visited[v] == false){
            vector<int> comp;
            drawTreeAndGenrateComp(graph, visited,v,comp);
            comps.push_back(comp);
        }
    }
    for(int i = 0; i<comps.size(); i++){
        for(int j = 0; j<comps[i].size(); j++){
            cout<<comps[i][j]<<" ";
        }
        cout<<endl;
    }
}