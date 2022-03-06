#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Edge{
    public:
    int src;
    int nbr;

    Edge(int src, int nbr){
        this->src = src;
        this->nbr = nbr;
    }
};


void drawTree(vector<Edge> graph[], int s , vector<bool>& visited, vector<int>&comp){
    visited[s] = true;
    comp.push_back(s);
    for(Edge e : graph[s]){
        if(visited[e.nbr]==false){
            drawTree(graph, e.nbr, visited, comp);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
    int edges;
    cin>>edges;
    for(int i = 0; i<edges; i++){
        int s, d;
        cin>>s>>d;
        graph[s].push_back(Edge(s, d));
        graph[d].push_back(Edge(d, s));
    }
    vector<bool> visited(n);
    vector<vector<int>> comps;
    for(int v = 0; v<n; v++){
        if(visited[v]== false){
            vector<int> comp;
            drawTree(graph, v, visited, comp);
            comps.push_back(comp);
        }
    }

    
    int count = 0;
    for(int i = 0; i<comps.size(); i++){
        for(int j = i+1; j<comps.size(); j++){
            count += comps[i].size() * comps[j].size();
        }
    }
cout<<count;
    
}