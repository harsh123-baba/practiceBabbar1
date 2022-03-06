#include<bits/stdc++.h> 
#include<iostream>
#include "graphWt.cpp"
using namespace std;


class Pair{
    public:
    int s;
    string psf;
    int wsf;
    Pair(int s, string psf, int wsf){
        this->s = s;
        this->psf = psf;
        this->wsf = wsf;
    }
};


bool operator >(const Pair& p1, const Pair& p2){
    return p1.wsf > p2.wsf;
}


void Dijsktra(vector<Edge> graph[], vector<bool>& visited, int src){
    priority_queue<Pair, vector<Pair> , greater<Pair>> pq;
    pq.push(Pair(src, to_string(src), 0));
    // pq.push(Pair(s, d, w));
    while(pq.size() > 0){
        Pair rem = pq.top();
        pq.pop();
        if(visited[rem.s]== true){
            continue;
        }
        visited[rem.s] = true;
        cout<<rem.s<<" via "<<rem.psf<<" @ "<<rem.wsf<<endl;
        for(Edge e:graph[rem.s]){
            if(visited[e.nbr]==false){
                pq.push(Pair(e.nbr, rem.psf+to_string(e.nbr), rem.wsf + e.wt));

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
    int s;
    cin>>s;

    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        if(visited[i] == false){
            Dijsktra(graph, visited, s);
        }
    }

}