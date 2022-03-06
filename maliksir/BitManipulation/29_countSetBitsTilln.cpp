#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int largestof2inRange(int n){
    int x =0;

    // 1<<x means 2 ki power x
    while((1<<x)<=n){
        x++;
    }
    return x-1;
}


int solution(int n){
    if(n==0){
        return 0;
    }
    // cout<<"hi";
    int x = largestof2inRange( n);
    int btill2x = x*(1<<(x-1));  //1 to 7 tk max itne bits on the
    int msb2xton = n - (1<<x)+1; // 11 m s 7 ghtaye taki ab pta chle ki or kitna kaam baki hai 
    int rest = n - (1<<x);  // 3 aayega 11 - 8 kiya
    int ans = btill2x + msb2xton+solution(rest);
    return ans;
}

// using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<solution(n);
}