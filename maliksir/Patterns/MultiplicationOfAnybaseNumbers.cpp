#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int BaseToDeciamal(int n, int b){
    int ans = 0;
    int count = 0;
    while(n>0){
        int y = n%10;
        ans  = ans+y*pow(b, count);
        count++; 
        n = n/10;
    }
    cout<<ans<<endl;
    return ans;
}
int DecimalToBase(int n, int b){
    vector<int> v;
    while(n>0){
        int x = n%b;
        v.push_back(x);
        n= n/b;
    }
    int val = 0;
    for(int i= v.size()-1; i>=0; i--){
        val = val*10+v[i];
    }
    return val;
}
int multiplication(int b,int n1, int n2){
    int num1 = BaseToDeciamal(n1, b);
    int num2 = BaseToDeciamal(n2,b);
    return DecimalToBase(num1*num2, b);

}


int main(){
    int b;
    int n1, n2;
    cin>>b;
    cin>>n1>>n2;
    cout<<multiplication(b, n1, n2);

}