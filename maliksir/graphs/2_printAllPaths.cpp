#include<bits/stdc++.h> 
#include<iostream>
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

bool HasPath(vector<Edge> graph[], int s, int d, vector<bool>visited){
    if(s == d){
        return true;
    }
    visited[s] = true;
    for(Edge edge : graph[s]){
        if(visited[edge.nbr] == false){
            bool hasNebrPath = HasPath(graph, edge.nbr, d, visited);
            if(hasNebrPath == true){
                return true;
            }
        }
    }
    return false;
}


void printPaths(vector<Edge> graph[], int s, int d, vector<bool>visited, string psf){
    if(s==d){
        cout<<psf<<endl;
        return;
    }
    visited[s] = true;
    for(Edge edge : graph[s]){
        if(visited[edge.nbr] == false){
            printPaths(graph, edge.nbr, d, visited, psf+to_string(edge.nbr));
        }
    }
    visited[s] = false;

}


int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
    int edges;
    cin>>edges;
    for(int i = 0; i<edges; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        graph[v1].push_back(Edge(v1, v2, w));
        graph[v2].push_back(Edge(v1,v2, w));
    }
    int s, d;
    cin>>s>>d;
    vector<bool> visited(n);
    // cout<<HasPath(graph, s, d, visited );

    printPaths(graph, s,d, visited , to_string(s)+"");
}