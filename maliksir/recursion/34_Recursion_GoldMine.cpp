#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxima = INT32_MIN;
void TravelAndCollect(vector<vector<int>>& v, int i ,int j, vector<vector<bool>>& visited, vector<int>& beg){    

    if(i<0 ||j<0 || i>=v.size() || j>=v.size() || visited[i][j]==true || v[i][j]==0){
        return;
    }

    // north upr west left 

    visited[i][j] = true;
    beg.push_back(v[i][j]);
    //north 

    TravelAndCollect(v, i-1, j, visited , beg);
    //east

    TravelAndCollect(v, i, j+1, visited , beg);
    //west

    TravelAndCollect(v, i, j-1, visited , beg);
    //south
    
    TravelAndCollect(v, i+1, j, visited , beg);


}

int GoldMine(vector<vector<int>> v){
    vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v.size(); j++){
            if(v[i][j]!=0 && visited[i][j]==false){
                vector<int> bag;
                TravelAndCollect(v, i, j, visited, bag);
                int sum = 0;
                for(int it:bag){
                    sum+=it;
                }
                if(sum>maxima){
                    maxima = sum;
                }
            }
        }
    }
    return maxima;
}


int main(){
//     6
// 6
    vector<vector<int>> v = {
    {0, 1, 4 ,2, 8 ,2},
    {4, 3, 6, 5 ,0, 4},
    {1 ,2 ,4 ,1 ,4, 6},
    {2, 0, 7, 3 ,2 ,2},
    {3 ,1, 5, 9, 2 ,4},
    {2 ,7, 0 ,8, 5 ,1},
    };
cout<<GoldMine(v);
}