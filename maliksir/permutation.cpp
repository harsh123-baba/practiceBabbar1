#include<iostream>
using namespace std;

void Permutation(int box[], int n, int r, int ci){
    if(ci> r){
        for(int i = 0; i<n; i++){
            cout<<box[i]<<" ";
        }
        // count++;
        cout<<endl;
        return;
    }
    for(int i = 0; i<n; i++){
        if(box[i]==0){
            box[i] = ci;
            Permutation(box, n, r, ci+1);
            box[i] = 0;
        }
    }
    // cout<<count;
}



void Permutation(int n, int r){
    int box[n];
    for(int i = 0; i<n;i++){
        box[i] = 0;
    }
    int count = 0;
    return Permutation(box, n, r, 1);
    
}


int main(){
    Permutation(4, 2);

}