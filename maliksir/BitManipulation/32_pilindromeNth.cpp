#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
int getrev(int n){
    int rev = 0;
    while(n!=0){
        int lb = (n&1);
        rev |= lb;
        rev <<=1;
        n>>=1;

    }
    rev >>=1;
    return rev;
}
int Nthpillindrome(int n){
    int count = 1;
    int len =1;
    while(count <n){
        // count +=
        len++;
        int elementforThisLen= (1<<((len-1)/2));
        count+=elementforThisLen;

    }
    count -= (1<<((len-1)/2));
    int offset = n-count-1;
    int ans = (1<<(len-1));
    ans = ans | (offset<<(len/2));
    int valFR = (ans>>(len/2));
    int rev = getrev(valFR);
    ans |= rev;
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<Nthpillindrome(n);
}