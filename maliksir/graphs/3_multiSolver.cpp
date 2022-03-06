
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

bool HasPath(vector<Edge> graph[], int s, int d, vector<bool>visited){
    if(s == d){
        return true;
    }
    visited[s] = true;
    for(Edge edge : graph[s]){
        if(visited[edge.nbr] == false){
            bool hasNebrPath = HasPath(graph, edge.nbr, d, visited);
            if(hasNebrPath == true){
                return true;
            }
        }
    }
    return false;
}

string spath;
int spathwt = INT32_MAX;
string lpath;
int lpathwt = INT32_MIN;
//jst bda
string cpath;
int cpathwt = INT32_MAX;
string fpath;
int fpathwt = INT32_MIN;




void Multisolve(vector<Edge> graph[], int s, int d, vector<bool>visited, int wsf, string psf, int k, int criteria){
    if(s==d){
        cout<<psf<<endl;
        if(wsf < spathwt){
            spath = psf;
            spathwt = wsf;
        }        
        if(wsf > lpathwt){
            lpath = psf;
            lpathwt = wsf;
        }
        if(wsf > criteria && cpathwt > wsf){
            cpathwt = wsf;
            cpath  = psf;
        }
        if(wsf < criteria && fpathwt < wsf){
            fpathwt = wsf;
            fpath  = psf;
        }
        return;
        
    }
    visited[s] = true;
    for(Edge e : graph[s]){
        if(visited[e.nbr] == false){
            Multisolve(graph, e.nbr, d, visited, wsf+e.wt, psf + to_string(e.nbr), k, criteria);
        }
    }
    visited[s] = false;

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
        graph[v2].push_back(Edge(v1,v2, w));
    }
    int s, d;
    cin>>s>>d;
    vector<bool> visited(n);
    int criteria, k;
    cin>>criteria>>k;
    // cout<<HasPath(graph, s, d, visited );
    Multisolve(graph, s,d,visited, 0,"0", k, criteria);
    cout<<spathwt<<" ->"<<spath<<endl;
    cout<<lpathwt<<" ->"<<lpath<<endl;
    cout<<cpathwt<<" ->"<<cpath<<endl;
    cout<<fpathwt<<" ->"<<fpath<<endl;
}

