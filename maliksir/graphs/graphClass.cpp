#include<bits/stdc++.h> 
#include<iostream>
using namespace std;


class Edge{
    public:
    int src;    
    int nbr;
    Edge(int src, int nbr){
        this->src = src;
        this->nbr = nbr;
    }
    
};