#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


class Edge{
    public:
    int src;    
    int nbr;
    int wt;
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
    
};