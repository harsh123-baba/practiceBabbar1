#include<iostream>
using namespace std;

int kenihanAlgo(int n){
    int counter = 0;
    while(n!=0){
        int rbsm = n&-n;
        n-=rbsm;
        counter++;
    }
    
    return counter;
}


int main(){
    int n = 10;
    int x = kenihanAlgo(n);
    // string x = 
    cout<<x;
}