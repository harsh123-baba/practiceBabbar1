
#include "graphWt.cpp"
#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


class Pair{
    public:
    int v;
    string psf;
    Pair(int v, string psf){
        this-> v = v;
        this->psf = psf;
    }
};


void DFSiter(vector<Edge> graph[],int src, int n){
    stack<Pair> s;
    vector<bool>visited(n);
    s.push(Pair(src, to_string(src)));

    while(s.size()> 0){
        Pair rem = s.top();
        s.pop();
        if(visited[rem.v] == true){
            continue;
        }
        visited[rem.v] = true;
        cout<<rem.v <<"@"<<rem.psf<<endl;   
        for(Edge e : graph[rem.v]){
            if(visited[e.nbr]==false){
                s.push(Pair(e.nbr, rem.psf+to_string(e.nbr)));
            }
        }

    }

}
int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
    int edges;
    cin>> edges;
    for(int i = 0; i<edges; i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d,w));
        graph[d].push_back(Edge(d, s,w));
    }
    int s;
    cin>>s;
    vector<bool> visited(n);
    DFSiter(graph, s, n);
}