#include<bits/stdc++.h> 
#include<iostream>
#include "graphClass.cpp"
using namespace std;

void topologicalSort(vector<Edge> graph[], vector<bool>& visited, int src, stack<int>& ans){
    visited[src] = true;
    for(Edge e : graph[src]){
        if(visited[e.nbr] == false ){
            topologicalSort(graph, visited, e.nbr, ans);
        }
    }    
    ans.push(src);
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
    }

    // int src = 0;
    vector<bool> visited(n);
    stack<int> ans;
    for(int i = 0; i<n; i++){
        if(visited[i] == false){
            topologicalSort(graph, visited, i , ans);
        }
    }   

    while(ans.size() > 0){
        cout<<ans.top()<<endl;
        ans.pop();
    }

}
