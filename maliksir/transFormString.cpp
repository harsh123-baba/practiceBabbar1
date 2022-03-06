#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int T=0; T<t; T++){

    string s;
    string f;
    cin>>s;
    cin>>f;
    long ans =0;
    for(int i=0; i<s.length(); i++){
    char ch = s[i];
    int  minmum =INT32_MAX;
        for(int j = 0; j<f.length(); j++){
            char fh = f[j];
            int cf = abs(ch-fh);
            
            minmum = min(minmum, min(cf, 26-cf%26));
        }
    ans+=minmum;
    }
    
    cout<<"Case #"<<T+1<< ": "<<ans<<endl;
}
        
}