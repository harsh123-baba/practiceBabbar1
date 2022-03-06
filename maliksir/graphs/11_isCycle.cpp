#include<bits/stdc++.h> 
#include<iostream>
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

bool IsCycle(vector<Edge> graph[], int n, int s, vector<bool>& visited){
    // vector<bool> visited(n);
    queue<Pair> q;
    q.push(Pair(s, to_string(s)));
    bool flag = false;
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        if(visited[rem.val] == true){
            return true;
        }

        visited[rem.val] = true; 
        for(Edge e : graph[rem.val]){
            if(visited[rem.val] == false){
                q.push(Pair(rem.val , to_string(rem.val)));
            }
        }
    }
    return false;

}


int main(){
    int n;
    cin>>n;
    vector<Edge> graph[n];
    int edges;
    cin>>edges;
    for(int v = 0; v<edges; v++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(Edge(s, d, w));
        graph[d].push_back(Edge(d, s, w));
    }
    int s;
    cin>>s;
    vector<bool> visited(n, false);
    for(int v = 0; v<n; v++){
        if(visited[v] == false){
            bool cycle = IsCycle(graph, n, s, visited);
            if(cycle){
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"false";
    
}