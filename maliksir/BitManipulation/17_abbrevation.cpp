#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

void solve(string p){
    for(int i = 0; i<(1<<p.size()); i++){
        string s;
        int count = 0;
        for(int j = 0;j<p.size(); j++){
            int b = p.size()-1 -j;
            // i = 0b11;
            char ch = p[j];
            int x = (1<<b);
        // cout<<x<<endl;
            if((i & (1<<b))==0){
                if(count ==0){
                    s+=ch;
                }
                else{
                    s+=to_string(count);
                    s+=(ch);
                    count= 0;
                }
            }
            else{
                count++;
            }
        }
        if(count > 0){
            s+=to_string(count);
        }
        cout<<s<<endl;
    }


}


int main(){
    string s="pep";
    // cin>>s;

    solve(s);

}
