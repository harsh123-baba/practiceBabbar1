#include<vector>
#include<iostream>
using namespace std;

void RecursionQueenchooses(vector<vector<bool>> boxes, int tq, int cq, int i, int j){
    if(cq>tq){
        for(int i =0; i<boxes.size(); i++){
            for(int j =0; j<boxes[0].size();j++){
                if(boxes[i][j]==true){
                    cout<<"q\t";
                }
                else{
                    cout<<"-\t";
                }
            }
            cout<<endl;

        }
        cout<<endl;
        return;
    }
    for(int col = j+1; col<boxes.size(); col++){
        if(boxes[i][col]==false){
            boxes[i][col]=true;
            RecursionQueenchooses(boxes, tq, cq+1, i, j);
            boxes[i][col]=false;
            
        }
    }
    for(int row = i+1; row<boxes.size(); row++){
        if(boxes[row][j]==false){
            boxes[row][j]=true;
            RecursionQueenchooses(boxes, tq, cq+1, i, j);
            boxes[row][j]=false;
            
        }
    }

}


int main(){
    vector<vector<bool>> v(3, vector<bool>(3, false));
    RecursionQueenchooses(v, 3, 1, 0, 0);

}