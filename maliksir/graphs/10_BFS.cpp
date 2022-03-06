#include<bits/stdc++.h> 
#include<iostream>
#include<string>
#include "graphWt.cpp"
using namespace std;

class Pair{
    public:
    int val;
    string psf;
    Pair(int val, string psf){
        this->psf = psf;
        this->val = val;
    }
};


void printBFS(vector<Edge> graph[], int src,int n){
    queue<Pair> q;
    q.push(Pair(src, to_string(src)));
    vector<bool> visited(n); 
    // visited[src] = true; 
    while(q.size() > 0){
        // visited[src]  = true;
        Pair rem = q.front();
        q.pop();
        if(visited[rem.val] == true ){
            continue;
        }
        visited[rem.val]=true;
        cout<<rem.val<<"@"<<rem.psf<<endl;
        for(Edge e : graph[rem.val]){
            if(visited[e.nbr] == false){
                q.push(Pair(e.nbr, rem.psf+to_string(e.nbr)));
            }
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
        int v1, v2, w;
        cin>>v1>>v2>>w;
        graph[v1].push_back(Edge(v1, v2, w));
        graph[v2].push_back(Edge(v2, v1, w));
    }   
    int s;
    cin>>s;
    printBFS(graph, s , n);

}