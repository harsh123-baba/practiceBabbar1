#include<iostream>
#include<bits/stdc++.h>
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



void Hamilton(vector<Edge> graph[], int src, int oSrc, unordered_set<int>visited, string psf, int n){
    if(visited.size() == n-1){
        cout<<psf;
        bool flag = false;
        for(Edge e : graph[src]){
            if(e.nbr == oSrc){
                flag = true;
                break;
            }
        }
        if(flag == true){
            cout<<"*\n";
        }
        else{
            cout<<".\n";
        }
        return;
    }
    visited.insert(src);
    for(Edge e : graph[src]){
        if(visited.find(e.nbr) == visited.end()){
            Hamilton(graph, e.nbr, oSrc, visited, psf+to_string(e.nbr), n);
        }
    }
    visited.erase(src);
}


int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
    int edges;
    cin>>edges;
    for(int i = 0; i<edges; i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d, w));
        graph[d].push_back(Edge(d, s, w));
    }
    int s;
    cin>>s;
    unordered_set<int> visited(n);
    Hamilton(graph, s, s,visited, to_string(s)+"", n);

}