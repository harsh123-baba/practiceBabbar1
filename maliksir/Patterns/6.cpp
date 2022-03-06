#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    //write your code here
    
    int st = n/2;
    int sp = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=st; j++){
            cout<<"*\t";
        }
        for(int j = 1; j<=sp; j++){
            cout<<"\t";
        }
        for(int j = 1; j<=st; j++){
            cout<<"*\t";
        }
        if(i<=n/2){
            sp +=2;
            st-=1;
        }   
        else{
            sp-=2;
            st+=1;
        }
        cout<<endl;
    }
    
    
}