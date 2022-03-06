#include<bits/stdc++.h> 
#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    int rev = 0;
    int flag = false;
    int j=0;
    for(int i= 31; i>=0; i--){
        if(flag){
            if((n&(1<<i)) != 0){
                // flag=true;
                cout<<1;
                int smask = (1<<j);
                rev = rev | smask;
                j++;
            }
            else{
                cout<<0;
                j++;
                // continue;
            }
        }
        else{
            if((n&(1<<i)) != 0){
                flag=true;
                int smask = (1<<j);
                rev = rev | smask;
                j++;
                cout<<1;
            }
            else{
                continue;
            }
        }
    }
    cout<<"\n";
    cout<<rev;

}