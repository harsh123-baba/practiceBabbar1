#include<bits/stdc++.h> 
#include<iostream>
#include "graphWt.cpp"
using namespace std;


class Pair{
    public:
    int s;
    int aquaingVertex;
    int w;
    Pair(int s, int aquaingVertex, int w){
        this->s = s;
        this->aquaingVertex = aquaingVertex;
        this->w = w;
    }
};


bool operator >(const Pair& p1, const Pair& p2){
    return p1.w > p2.w;
}



void Prims(vector<Edge> graph[], vector<bool>& visited, int s){
    priority_queue<Pair,vector<Pair>, greater<Pair>> pq;
    pq.push(Pair(s, -1, 0));
    while(pq.size()>0){
        Pair rem = pq.top();
        pq.pop();
        if(visited[rem.s]==true){
            continue;
        }
        visited[rem.s] = true;
        if(rem.aquaingVertex != -1){
            cout<<rem.s<<"-"<<rem.aquaingVertex<<"@"<<rem.w<<endl;
        }
        for(Edge e : graph[rem.s]){
            if(visited[e.nbr] == false){
                pq.push(Pair(e.nbr, rem.s, e.wt));
            }
        }

    }
}

int main(){
    int n;
    cin>>n;
    int edges;
    cin>>edges;
    vector<Edge> graph[n];
    for(int i = 0; i<edges; i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d, w));
        graph[d].push_back(Edge(d, s, w));
    }
    // int s;
    // cin>>s;

    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        if(visited[i] == false){
            // Dijsktra(graph, visited, s);
            Prims(graph, visited, 0);
        }
    }

}