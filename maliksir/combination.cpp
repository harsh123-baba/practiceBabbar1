#include<iostream>
using namespace std;



void combination(int currBox, int totalBox, int SelectedSoFar, int TotalSelected, string ansSoFar){
    if(currBox > totalBox){
        if(SelectedSoFar == TotalSelected){
            cout<<ansSoFar<<"\n";
        }
        // cout<<endl;
        return;
        // cout<<endl;
    }
    combination(currBox+1, totalBox,SelectedSoFar+1, TotalSelected, ansSoFar+"i");
    combination(currBox+1, totalBox,SelectedSoFar, TotalSelected, ansSoFar+"_");
    
}


int main(){

    combination(1, 4, 0, 2, ""); 
}