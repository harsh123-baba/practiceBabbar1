#include<bits/stdc++.h> 
#include<iostream>
#include "graphWt.cpp"
using namespace std;


class Pair{
    public:
    int v;
    int time;
    Pair(int v, int time){
        this->v = v;
        this->time = time;
    }
};

int spreadInf(vector<Edge> graph[], vector<int>& visited, int t, int src, int& count){
    queue<Pair> q;
    // int count = 0;
    q.push(Pair(src, 1));
    while(q.size()>0){
        //r
        Pair rem = q.front();
        q.pop();
        
        // *m
        if(visited[rem.v] > 0){
            continue;
        }
        //m;

        visited[rem.v] = rem.time;
        if(rem.time > t){
            break;
        }
        count++;
        for(Edge e : graph[rem.v]){
            if(visited[e.nbr] == 0){
                q.push(Pair(e.nbr, rem.time+1));
            }
        }


    }
    return count;
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
    int s, t;
    cin>>s>>t;
    int count = 0;
    vector<int>visited(n, 0);
    for(int i = 0; i<n; i++){
        if(visited[i] == 0){
            spreadInf(graph, visited,t, s, count);
        }
    }
cout<<count;

}