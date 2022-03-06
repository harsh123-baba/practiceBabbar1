#include<bits/stdc++.h>
// #include<iostream>
using namespace std;




int main(){
    int n;
    cin>>n;
    // cout<<-n<<endl;
    // cout<<n<<ndl;
    int compliment = ~n;
    // cout<<compliment<<endl;
    int rbsm = n & (compliment+1);
    // the first 1 that is present in this binary number from back can be known using 2s compliment and n

    string s = bitset<8>(rbsm).to_string();
    // int x = DecToAny(rbsm,2);
    cout<<s;
    // cout<<x;
    // cout<<bitset<32>(n);
    // char res[1000];
    // itoa(rbsm, res, 2);

}