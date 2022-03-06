#include<vector>
#include<iostream>
using namespace std;


/*
    level pr hoge letters;
    option m hoge boxes/positions
*/


void Combination(vector<bool> boxes, int tb, int lb, int ci){

    if(ci>tb){
        for(int i = 0; i<boxes.size(); i++){
            if(boxes[i]){
                cout<<"i";
            }
            else{
                cout<<"-";
            }
        }
        cout<<endl;
    return;
    }
    for(int b=lb+1; b<boxes.size(); b++){
        if(boxes[b]==false){
            boxes[b]=true;
            Combination(boxes, tb, b, ci+1);
            boxes[b]=false;
        }
    }
    

}


int main(){
    vector<bool> boxes(3, 0);
    Combination(boxes, 2, -1, 1);
}