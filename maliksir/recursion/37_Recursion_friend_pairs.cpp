// This video discusses the alternate approach for the Friends Pairing problem using Recursion and Backtracking. In this problem, 
// 1. You are given an integer n, which represents n friends numbered from 1 to n.
// 2. Each one can remain single or can pair up with some other friend.
// 3. You have to print all the configurations in which friends can remain single or can be paired up.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void FriendsPairing(vector<bool> used, int n , string asf, int i)
{   
    if(i>n){
        cout<<asf<<endl;
        return;
    }
    if(used[i]== true){
        FriendsPairing(used, n, asf, i+1);
    }
    else{
        used[i]=true;
        FriendsPairing(used, n, asf+"("+to_string(i)+")", i+1);
        for(int j = i+1; j<=n; j++){
            if(used[j]==false){
                used[j] = true;
                FriendsPairing(used, n, asf+"("+to_string(i)+", "+to_string(j)+")", i+1);
                used[j] = false;
            }
        }
        used[i] = false;
    }

}

int main(){
    int n = 3;

    vector<bool> used(n+1, false);
    FriendsPairing(used, n, "", 1);
}