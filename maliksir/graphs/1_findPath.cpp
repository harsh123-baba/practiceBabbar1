#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    Edge(){

    }
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

bool solve(vector<Edge> graph[], int s, int d, vector<bool>& visited){
    if(s==d){
        return true;
    }
    visited[s] = true;
    for(Edge edge : graph[s]){
        if(visited[edge.nbr] == false){
            bool hasPath = solve(graph, edge.nbr, d, visited);
            if(hasPath){
                return true;
            }
        }
    }
    return false;
}



int main(){
    int n;
    cin>>n;
    int edges;
    cin>>edges;
    vector<Edge> graph[n];
    for(int i = 0; i<edges; i++){
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    vector<bool> visited(n);
    int s, d;
    cin>>s>>d;
    bool x = solve(graph, s, d, visited);
    if(x){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
}



