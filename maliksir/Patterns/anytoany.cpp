#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int AnyToAny(int n, int b1, int b2) {
    
  //write your code here
  int ans =0;
  int count = 0;

    while(n>0){
        int x = n%10;
        ans += x*pow(b1, count);
        count++;
        n = n/10;
    }
     cout<<ans<<endl;   
    // i have ans so i hv to convert that ans in another base case
    vector<int> v;
    while(ans>0){
        int y = ans%b2;
        v.push_back(y);
        ans = ans/b2;
    }
    int val =0;
    for(int i = v.size()-1; i>=0; i--){
        val = val*10+v[i];
    }
    return val;

    // vector<int> v;
    
    // while(ans >0){
    //     int y = ans%b2;
    //     v.push_back(y);
    //     n = n/b2;
    // }
    // int val=0;
    // for(int i = v.size()-1; i>=0; i--){
    //     val = val*10+ v[i];
    // }
    // return val;
    // return ans;    
}
int main() {
  int n;
  int b1;
  int b2;
  cin >> n;
  cin >> b1;
  cin >> b2;
  int res = AnyToAny(n, b1, b2);
  cout << res << endl;
}