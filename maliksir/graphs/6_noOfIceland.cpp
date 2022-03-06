#include<bits/stdc++.h>
using namespace std;


void drawTree(int i, int j, vector<vector<int>>& v, vector<vector<bool>>& visited){
    if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j] == 1 || visited[i][j] == true){
        return;
    }
    visited[i][j] = true;
    drawTree(i-1, j, v, visited);
    drawTree(i, j-1, v, visited);
    drawTree(i+1, j, v, visited);
    drawTree(i, j+1, v, visited);
    
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>> v[i][j];
        }
    }
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == 0 && visited[i][j] == false){
                drawTree(i, j, v, visited);
                count++;
            }
        }
    }
    cout<<count;

}