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


void MultiSolver(vector<Edge> graph[], int s, int d, string psf, int wsf, int criteria, int k, vector<bool>visited){
    if(s==d){
        return;
    }
    visited[s] = true;
    for(Edge e : graph[s]){
        if(visited[e.nbr] == false){
            MultiSolver(graph, e.nbr, d,psf+to_string(e.src), wsf+(e.wt), criteria,k,visited); 
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
}