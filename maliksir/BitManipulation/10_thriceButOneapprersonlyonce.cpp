#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int main(){
    vector<int> v = {51, 57,51,57, 63, 38, 57, 63, 63, 51};
    int tn = INT32_MAX;
    int tnp1 = 0;
    int tnp2 = 0;
    for(int i = 0; i<v.size(); i++){
        int cwtn = tn & v[i];
        int cwtnp1 = tnp1 & v[i];
        int cwtnp2 = tnp2 & v[i];
        
        //swtich off from 3n
        tn = tn & (~cwtn);
        // switch on from 3n+1;
        tnp1 = tnp1 | (cwtn);

        //swtich off from 3n+1
        tnp1 = tnp1 & (~cwtnp1);
        // switch on from 3n+2;
        tnp2 = tnp2 | (cwtnp1);

        
        //swtich off from 3n+2
        tnp2 = tnp2 & (~cwtnp2);
        // switch on from 3n;
        tn = tn | (cwtnp2);

    } 
    cout<<tnp1;


}